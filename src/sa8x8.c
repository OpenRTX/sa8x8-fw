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

const char VERSION[] = "sa8x8-fw/" GIT_INFO "\r\n";
const char MODEL[] = MODULE_MODEL "\r\n";

const char OK[] = "OK\r\n";
const char ERR[] = "ERR\r\n";
const char CRLF[] = "\r\n";

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
 * Convert supplied ASCII character sequence to a number
 */
uint16_t a2i(const char *s, uint8_t *pos) {
  uint16_t n = 0;
  uint8_t i = *pos;

  while ((s[i] >= '0' && s[i] <= '9') || s[i] == ' ') {
    if (s[i] == ' ') {
      i++;
      continue;
    }

    n *= 10;
    n += (uint16_t)(s[i++] - '0');
  }

  *pos = i;

  return n;
}

/*
 * Application entrypoint
 */
int main(void) {
  // Perform platform specific initialization
  platform_init();

  // Create ring buffer for received UART data
  struct item buf[16];
  ring_init(&rx, buf, 16);

  // Create command buffer and offset pointer
  char cmd[32];
  char *c;

  // Transceiver status flags
  bool sq;
  bool css;
  bool vox;

  while (1) {
    // Update status flags
    platform_refresh(&sq, &css, &vox);

    // Skip iteration if no incoming command
    if (ring_empty(&rx)) {
      continue;
    }

    // Read command from UART
    uart_gets(cmd, 32);

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
      uart_puts(OK);
      platform_turbo();
      continue;
    }

    // AT+PEEK=<REG>: Get transceiver register contents
    if (eq(&cmd[2], (char *)CMD_PEEK, sizeof(CMD_PEEK) - 1)) {
      uint8_t i = sizeof(CMD_PEEK) + 1;

      // Parse I2C register
      uint16_t reg = a2i(cmd, &i);

      // Error if register larger than single byte or missing terminator
      if (reg > 255 || !(cmd[i] == '\0')) {
        uart_puts(ERR);
        continue;
      }

      // Read requested register
      uint16_t val = i2c_read(I2C_ADDR_XCVR, (uint8_t)reg);

      // Send register contents as response
      uart_puts(i2a(val));
      uart_puts(CRLF);

      continue;
    }

    // AT+POKE=<REG>,<VAL>: Set transceiver register contents
    if (eq(&cmd[2], (char *)CMD_POKE, sizeof(CMD_POKE) - 1)) {
      uint8_t i = sizeof(CMD_POKE) + 1;

      // Parse I2C register
      uint16_t reg = a2i(cmd, &i);

      // Error response if register larger than single byte
      if (reg > 255 || !(cmd[i++] == ',')) {
        uart_puts(ERR);
        continue;
      }

      // Parse I2C value
      uint16_t val = a2i(cmd, &i);

      // Error if missing terminator
      if (!(cmd[i] == '\0')) {
        uart_puts(ERR);
        continue;
      }

      // Apply any platform specific poke actions
      if (!platform_poke(I2C_ADDR_XCVR, (uint8_t)reg, val)) {
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
      bool state = (bool) a2i(cmd, &i);

      // Error if missing terminator
      if (!(cmd[i] == '\0')) {
        uart_puts(ERR);
        continue;
      }

      // Set requested amplifier state
      platform_amp_enable(state);

      // Send command valid response
      uart_puts(OK);

      continue;
    }

    // All other requests are errors
    uart_puts(ERR);
  }

  return 0;
}

