/***************************************************************************
 *   Copyright (C) 2024 by Niccolò Izzo IU2KIN                             *
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
#include "registers.h"

/*
 * RDA1864S transceiver I2C address
 */
const uint8_t I2C_ADDR_XCVR = 0xE2U;

/*
 * Successfully do nothing
 */
void delay(uint16_t n) {
  while (n-- > 0) {
    asm("nop");
  }
}

/*
 * Initialize UART0 for communication
 */
void uart_init(void) {
  pd1 &= 0xCF;  // UART0: Enable peripheral
  u0mr = 0x05;  // UART0: 8N1 framing
  u0c0 = 0x02;  // UART0: f/32, TXD0, CMOS, LSB first
  u0c1 = 0x00;  // UART0: Transmit/receive disable
  u0brg = 0x03; // UART0: 115200 Baud
  s0tic = 0x00; // UART0: Transmit interrupt disable
  s0ric = 0x01; // UART0: Receive interrupt enable
  te_u0c1 = 1;  // UART0: Transmit enable
  re_u0c1 = 1;  // UART0: Receive enable
}

/*
 * Transmit a string through UART0
 */
int uart_puts(const char *s) {
  int len = 0;

  while ('\0' != *s) {
    while (0U == ti_u0c1)
      ;
    u0tbl = (unsigned char)*s++;
    ++len;
  }

  return len;
}

/*
 * Receive a string through UART0 via ring buffer
 */
int uart_gets(char *s, int size) {
  int len = 0;
  char c;

  while (len < size - 1) {
    while (!ring_get(&rx, &c))
      ;
    if (c == '\r' || c == '\n') {
      break;
    }
    s[len++] = c;
  }
  s[len] = '\0';

  return len;
}

static inline void _i2c_sdio_input(void) {
  pd1_7 = 0; // P1_7 (SDIO) is input
}

static inline void _i2c_sdio_output(void) {
  pd1_7 = 1; // P1_7 (SDIO) is output
}

static inline void _i2c_sdio_high(void) {
  p1_7 = 1; // P1_7 (SDIO) is high
}

static inline void _i2c_sdio_low(void) {
  p1_7 = 0; // P1_7 (SDIO) is low
}

static inline uint8_t _i2c_sdio_value() {
  return p1_7; // P1_7 (SDIO) read
}

static inline void _i2c_sclk_output(void) {
  pd3_5 = 1; // P3_5 (SCLK) is output
}

static inline void _i2c_sclk_high(void) {
  p3_5 = 1; // P3_5 (SCLK) is high
}

static inline void _i2c_sclk_low(void) {
  p3_5 = 0; // P3_5 (SCLK) is low
}

/*
 * Start an I2C bus transaction
 */
static inline void _i2c_start() {
  _i2c_sdio_output();

  _i2c_sdio_high();
  delay(2);

  _i2c_sclk_high();
  delay(2);

  _i2c_sdio_low();
  delay(2);

  _i2c_sclk_low();
  delay(6);
}

/*
 * Stop an I2C bus transaction
 */
static inline void _i2c_stop() {
  _i2c_sdio_output();

  _i2c_sclk_low();
  delay(2);

  _i2c_sdio_low();
  delay(2);

  _i2c_sclk_high();
  delay(2);

  _i2c_sdio_high();
  delay(2);
}

/*
 * Low-level I2C bus write transaction
 */
static void _i2c_write(uint8_t val) {
  _i2c_sdio_output();

  for (uint8_t i = 0; i < 8; i++) {
    _i2c_sclk_low();
    delay(1);

    if (val & 0x80) {
      _i2c_sdio_high();
    } else {
      _i2c_sdio_low();
    }

    val <<= 1;
    delay(1);

    _i2c_sclk_high();
    delay(2);
  }

  _i2c_sclk_low();

  _i2c_sdio_input();
  delay(2);

  _i2c_sclk_high();
  delay(2);

  _i2c_sclk_low();
  delay(1);

  _i2c_sdio_high();
  _i2c_sdio_output();
  delay(6);
}

/*
 * Low-level I2C bus read transaction
 */
static uint8_t _i2c_read(bool ack) {
  _i2c_sdio_input();

  _i2c_sclk_low();

  uint8_t val = 0;
  for (uint8_t i = 0; i < 8; i++) {
    delay(2);
    _i2c_sclk_high();
    delay(2);

    val <<= 1;
    val |= _i2c_sdio_value();

    _i2c_sclk_low();
  }

  _i2c_sdio_low();
  _i2c_sdio_output();
  delay(2);

  if (!ack) {
    _i2c_sdio_high();
  }

  delay(2);
  _i2c_sclk_high();
  delay(2);
  _i2c_sclk_low();
  delay(2);

  return val;
}

/*
 * Initialize GPIO for bit-banged I2C bus transactions
 */
void i2c_init(void) {


  _i2c_sdio_input();

  _i2c_sclk_output();
  _i2c_sclk_low();
}

/*
 * High-level I2C bus write transaction
 */
void i2c_write(uint8_t addr, uint8_t reg, uint16_t val) {
  uint8_t hi = (uint8_t)((val >> 8) & 0xFF);
  uint8_t lo = val & 0xFF;

  _i2c_start();
  _i2c_write(addr);
  _i2c_write(reg);
  _i2c_write(hi);
  _i2c_write(lo);
  _i2c_stop();
}

/*
 * High-level I2C bus read transaction
 */
uint16_t i2c_read(uint8_t addr, uint8_t reg) {
  _i2c_start();
  _i2c_write(addr);
  _i2c_write(reg);
  _i2c_start();
  _i2c_write(addr | 0x01);
  uint8_t hi = _i2c_read(true);
  uint8_t lo = _i2c_read(false);
  _i2c_stop();

  return ((uint16_t)hi << 8) | lo;
}

void platform_init(void) {
  asm("fclr i"); // Interrupts disable

  prc0 = 1; // Protect off

  cm13 = 1; // Enable external 14.7456 MHz reference
  cm05 = 0; // Enable main clock
  cm06 = 0; // Enable f/4 mode
  cm17 = 1; // Enable f/4 mode
  cm16 = 0; // Enable f/4 mode

  for (int i = 0; i <= 255; i++)
    ; // Wait for clock switch

  ocd2 = 0; // Use external reference as sysclock
  cm14 = 1; // Stop internal low speed reference

  prc0 = 0; // Protect on

  uart_init();   // Setup UART0 for transmission and reception
  i2c_init();    // Setup software I2C for bus transactions

  p3_4 = 0;  // P3_4 (H/L) is low
  pd3_4 = 1; // P3_4 (H/L) is output

  p1_0 = 0;  // P1_0 (SQ) is low
  pd1_0 = 1; // P1_0 (SQ) is output

  p1_6 = 1;  // P1_6 (PDN) is high
  pd1_6 = 1; // P1_6 (PDN) is output

  pd1_1 = 0; // P1_1 (VOX) is input
  pd1_2 = 0; // P1_2 (SQL) is input
  pd1_3 = 0; // P1_3 (PTT) is input
  pd3_3 = 0; // P3_3 (CSS) is input

  asm("fset i"); // Interrupts enable
}

void platform_sleep(void) {
  // Not implemented
}

void platform_turbo(void) {
  // Not implemented
}

void platform_refresh(struct platform_state *state) {
  bool ptt = !p1_3;
  uint16_t val;

  if (ptt && !state->ptt) {
    // Enable PTT if requested and not enabled previously
    platform_peek(0x30, &val);
    val = (val | TX) & ~RX;
    platform_poke(0x30, val);
  } else if (!ptt && state->ptt) {
    // Disable PTT if requested and enabled previously
    platform_peek(0x30, &val);
    val = (val & ~TX) | RX;
    platform_poke(0x30, val);
  }

  state->ptt = ptt;  // Push to talk from external GPIO
  state->css = p3_3; // CSS status from internal AT1846S
  state->vox = p1_1; // VOX status from internal AT1846S
  state->sq = p1_2;  // Squelch status from internal AT1846S
}

bool platform_peek(uint8_t reg, uint16_t *val) {
  *val = i2c_read(I2C_ADDR_XCVR, reg);

  return true;
}

bool platform_poke(uint8_t reg, uint16_t val) {
  // Not possible to TX and RX simultaneously
  if (reg == 0x30 && (val & TX) && (val & RX)) {
    return false;
  }

  // TX requested so disable RXEN
  if (reg == 0x30 && (val & TX)) {
    p3_7 = 1; // P3_7 (RXEN) is high
  }

  i2c_write(I2C_ADDR_XCVR, reg, val);

  // RX requested so enable RXEN
  if (reg == 0x30 && (val & RX)) {
    p3_7 = 0; // P3_7 (RXEN) is low
  }

  return true;
}

void platform_amp(bool enabled) {
  if (enabled) {
    // Enable power amplifier
    p3_4 = 0;   // P3_4 (H/L) is low
  } else {
    // Disable power amplifier
    p3_4 = 1;   // P3_4 (H/L) is high
  }
}

void platform_audio(bool enabled) {
  if (enabled) {
    // Enable external audio amplifier
    p1_0 = 0; // P1_0 (SQ) is low
  } else {
    // Disable external audio amplifier
    p1_0 = 1; // P1_0 (SQ) is high
  }
}
