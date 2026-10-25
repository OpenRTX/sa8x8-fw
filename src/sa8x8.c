/***************************************************************************
 *   Copyright (C) 2023 by Niccolò Izzo IU2KIN                             *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, see <http://www.gnu.org/licenses/>   *
 ***************************************************************************/

#include "common.h"
#include "version.h"

const char CMD_VERSION[] = "+VERSION";
const char CMD_MODEL[] = "+MODEL";
const char CMD_TURBO[] = "+TURBO";
const char CMD_PEEK[] = "+PEEK=";
const char CMD_POKE[] = "+POKE=";
const char CMD_AMP[] = "+AMP=";
const char CMD_AUDIO[] = "+AUDIO=";
const char CMD_TOT[] = "+TOT=";

const char VERSION[] = "sa8x8-fw/" GIT_INFO "" CRLF;
const char MODEL[] = MODULE_MODEL "" CRLF;

const char OK[] = "OK" CRLF;
const char ERR[] = "ERR" CRLF;

struct ring rx;

/*
 * Initialize a ring buffer
 */
void ring_init(struct ring *r, struct item *buf, uint16_t size) {
  r->buffer = buf;
  r->size = size;

  for (uint16_t i = 0; i < r->size - 1; i++) {
    r->buffer[i].next = &r->buffer[i + 1];
  }
  r->buffer[r->size - 1].next = &r->buffer[0];

  r->put = r->buffer;
  r->get = r->buffer;
}

/*
 * Put a single character into a ring buffer
 */
bool ring_put(struct ring *r, char c) {
  if (r->put->next == r->get) {
    return false;
  }

  r->put->c = c;
  r->put = r->put->next;

  return true;
}

/*
 * Get a single character from a ring buffer
 */
bool ring_get(struct ring *r, char *c) {
  if (r->put == r->get) {
    return false;
  }

  *c = r->get->c;
  r->get = r->get->next;

  return true;
}

/*
 * Is ring buffer empty?
 */
inline bool ring_empty(struct ring *r) {
  if (r->put == r->get) {
    return true;
  }

  return false;
}

/*
 * Is ring buffer full?
 */
inline bool ring_full(struct ring *r) {
  if (r->put->next == r->get) {
    return true;
  }

  return false;
}

/*
 * Return upper case character for supplied ASCII character
 */
char up(char c) {
  if (c >= 'a' && c <= 'z') {
    c -= 32;
  }

  return c;
}

/*
 * Determine equivalence of two strings
 */
int eq(const char *s1, const char *s2, uint16_t len) {
  while (len--) {
    if (*s1++ != *s2++) {
      return 0;
    }
  }

  return 1;
}

/*
 * Convert supplied number to ASCII character sequence
 */
const char *i2a(uint16_t n) {
  static char s[8];
  uint8_t i;

  s[7] = '\0';

  if (n == 0) {
    s[6] = '0';
    return &s[6];
  }

  for (i = 6; n && i; --i, n /= 10) {
    s[i] = "0123456789"[n % 10];
  }

  return &s[i + 1];
}

/*
 * Convert supplied ASCII decimal digit sequence to a number
 *
 * Parsing starts at s[*pos] and stops at the first non-digit character,
 * whose index is stored back into *pos. Fails if there is no digit at all
 * or if the value does not fit in 16 bits.
 */
bool a2i(const char *s, uint8_t *pos, uint16_t *n) {
  uint16_t val = 0;
  uint8_t i = *pos;

  if (!(s[i] >= '0' && s[i] <= '9')) {
    return false;
  }

  while (s[i] >= '0' && s[i] <= '9') {
    uint16_t d = (uint16_t)(s[i++] - '0');

    // Reject anything above 65535 before it can wrap around
    if (val > 6553U || (val == 6553U && d > 5U)) {
      return false;
    }

    val = (uint16_t)(val * 10U + d);
  }

  *pos = i;
  *n = val;

  return true;
}

/*
 * Application entrypoint
 */
int main(void) {
  // Create ring buffer for received UART data before platform_init()
  // enables the UART receive interrupt, which writes into it
  struct item buf[16];
  ring_init(&rx, buf, 16);

  // Perform platform specific initialization
  platform_init();

  // Command buffer, filled one character at a time as they arrive
  char cmd[32];
  uint8_t len = 0;
  bool overflow = false;
  char ch;
  char *c;

  // Internal state
  struct platform_state state = {0};

  while (1) {
    // Update internal state, on every iteration so that PTT and the
    // transmit timeout are handled even while a command is half received
    platform_refresh(&state);

    // Skip iteration if no incoming character
    if (!ring_get(&rx, &ch)) {
      continue;
    }

    // Accumulate characters until end of line
    if (ch != '\r' && ch != '\n') {
      if (len < sizeof(cmd) - 1) {
        cmd[len++] = ch;
      } else {
        overflow = true; // Discard the rest of an overlong line
      }
      continue;
    }

    // End of line: terminate command and reset buffer for the next one
    cmd[len] = '\0';
    len = 0;

    // Reject a line that did not fit in the command buffer
    if (overflow) {
      overflow = false;
      uart_puts(ERR);
      continue;
    }

    // Make command case-insensitive
    c = cmd;
    while (*c) {
      *c = up(*c);
      c++;
    }

    // Ignore empty request
    if (cmd[0] == '\0') {
      continue;
    }

    // Reject anything else not prefixed with AT
    if (!(cmd[0] == 'A' && cmd[1] == 'T')) {
      uart_puts(ERR);
      continue;
    }

    // AT: Attention
    if (cmd[2] == '\0') {
      uart_puts(OK);
      continue;
    }

    // AT+VERSION: Display firmware version information
    if (eq(&cmd[2], (char *)CMD_VERSION, sizeof(CMD_VERSION))) {
      uart_puts(VERSION);
      continue;
    }

    // AT+MODEL: Display module model information
    if (eq(&cmd[2], (char *)CMD_MODEL, sizeof(CMD_MODEL))) {
      uart_puts(MODEL);
      continue;
    }

    // AT+TURBO: Enter high speed UART mode
    if (eq(&cmd[2], (char *)CMD_TURBO, sizeof(CMD_TURBO))) {
      // Refuse if the platform cannot change its baud rate, so the host
      // does not switch speed while the module stays at the old one
      if (!PLATFORM_TURBO) {
        uart_puts(ERR);
        continue;
      }

      uart_puts(OK);
      platform_turbo();
      continue;
    }

    // AT+PEEK=<REG>: Get transceiver register contents
    if (eq(&cmd[2], (char *)CMD_PEEK, sizeof(CMD_PEEK) - 1)) {
      uint8_t i = sizeof(CMD_PEEK) + 1;

      // Parse I2C register
      uint16_t reg;

      // Error if no valid number, register larger than single byte or
      // missing terminator
      if (!a2i(cmd, &i, &reg) || reg > 255 || !(cmd[i] == '\0')) {
        uart_puts(ERR);
        continue;
      }

      // Read requested register, error if the transceiver does not respond
      uint16_t val;
      if (!platform_peek((uint8_t)reg, &val)) {
        uart_puts(ERR);
        continue;
      }

      // Send register contents as response
      uart_puts(i2a(val));
      uart_puts(CRLF);

      continue;
    }

    // AT+POKE=<REG>,<VAL>: Set transceiver register contents
    if (eq(&cmd[2], (char *)CMD_POKE, sizeof(CMD_POKE) - 1)) {
      uint8_t i = sizeof(CMD_POKE) + 1;

      // Parse I2C register
      uint16_t reg;

      // Error if no valid number, register larger than single byte or
      // missing separator
      if (!a2i(cmd, &i, &reg) || reg > 255 || !(cmd[i++] == ',')) {
        uart_puts(ERR);
        continue;
      }

      // Parse I2C value
      uint16_t val;

      // Error if no valid number or missing terminator
      if (!a2i(cmd, &i, &val) || !(cmd[i] == '\0')) {
        uart_puts(ERR);
        continue;
      }

      // Apply any platform specific poke actions
      if (!platform_poke((uint8_t)reg, val)) {
        uart_puts(ERR);
        continue;
      }

      // Send command valid response
      uart_puts(OK);

      continue;
    }

    // AT+AMP=<0,1>: Set power amplifier state
    if (eq(&cmd[2], (char *)CMD_AMP, sizeof(CMD_AMP) - 1)) {
      uint8_t i = sizeof(CMD_AMP) + 1;

      // Parse state
      uint16_t state;

      // Error if not 0 or 1, or missing terminator
      if (!a2i(cmd, &i, &state) || state > 1 || !(cmd[i] == '\0')) {
        uart_puts(ERR);
        continue;
      }

      bool enabled = (state == 1);

      // Set requested amplifier state
      platform_amp(enabled);

      // Send command valid response
      uart_puts(OK);

      continue;
    }

    // AT+AUDIO=<0,1>: Set external audio amplifier state
    if (eq(&cmd[2], (char *)CMD_AUDIO, sizeof(CMD_AUDIO) - 1)) {
      uint8_t i = sizeof(CMD_AUDIO) + 1;

      // Parse state
      uint16_t state;

      // Error if not 0 or 1, or missing terminator
      if (!a2i(cmd, &i, &state) || state > 1 || !(cmd[i] == '\0')) {
        uart_puts(ERR);
        continue;
      }

      bool enabled = (state == 1);

      // Set requested amplifier state
      platform_audio(enabled);

      // Send command valid response
      uart_puts(OK);

      continue;
    }

    // AT+TOT=<SEC>: Set transmit timeout in seconds, 0 disables
    if (eq(&cmd[2], (char *)CMD_TOT, sizeof(CMD_TOT) - 1)) {
      uint8_t i = sizeof(CMD_TOT) + 1;

      // Parse timeout
      uint16_t seconds;

      // Error if no valid number or missing terminator
      if (!a2i(cmd, &i, &seconds) || !(cmd[i] == '\0')) {
        uart_puts(ERR);
        continue;
      }

      // Error if the platform has no transmit timeout support
      if (!platform_tot(seconds)) {
        uart_puts(ERR);
        continue;
      }

      // Send command valid response
      uart_puts(OK);

      continue;
    }

    // All other requests are errors
    uart_puts(ERR);
  }

  return 0;
}

