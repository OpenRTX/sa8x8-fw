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

#ifndef COMMON_H
#define COMMON_H

#include <stdbool.h>
#include <stdint.h>

/*
 * Bit-level access for uint8_t
 */
typedef struct {
  uint8_t no0 : 1;
  uint8_t no1 : 1;
  uint8_t no2 : 1;
  uint8_t no3 : 1;
  uint8_t no4 : 1;
  uint8_t no5 : 1;
  uint8_t no6 : 1;
  uint8_t no7 : 1;
} __BITS8;

/*
 * Bit-level access for uint16_t
 */
typedef struct {
  uint16_t no0 : 1;
  uint16_t no1 : 1;
  uint16_t no2 : 1;
  uint16_t no3 : 1;
  uint16_t no4 : 1;
  uint16_t no5 : 1;
  uint16_t no6 : 1;
  uint16_t no7 : 1;
  uint16_t no8 : 1;
  uint16_t no9 : 1;
  uint16_t no10 : 1;
  uint16_t no11 : 1;
  uint16_t no12 : 1;
  uint16_t no13 : 1;
  uint16_t no14 : 1;
  uint16_t no15 : 1;
} __BITS16;

/*
 * A single ring buffer item
 */
struct item {
  char c;
  struct item *next;
};

/*
 * A generic ring buffer structure
 */
struct ring {
  uint16_t size;
  struct item *buffer;
  struct item *put;
  struct item *get;
};

/*
 * Ring buffer manipulation
 */
void ring_init(struct ring *r, struct item *buf, uint16_t size);
bool ring_put(struct ring *r, char c);
bool ring_get(struct ring *r, char *c);
bool ring_empty(struct ring *r);
bool ring_full(struct ring *r);
extern struct ring rx;

/*
 * Text processing
 */
char up(char c);
int eq(const char *s1, const char *s2, uint16_t len);
const char *i2a(uint16_t n);
uint16_t a2i(const char *s, uint8_t *pos);

/*
 * Platform specific
 */
void platform_init(void);
void platform_sleep(void);
void platform_turbo(void);
void platform_refresh(bool *sq, bool *css, bool *vox);
bool platform_poke(uint8_t addr, uint8_t reg, uint16_t val);
void platform_amp_enable(bool state);
void platform_audio_enable(bool state);

/*
 * UART peripheral control
 */
void uart_init(void);
int uart_puts(const char *s);
int uart_gets(char *s, int size);

/*
 * I2C peripheral control
 */
void i2c_init(void);
void i2c_write(uint8_t addr, uint8_t reg, uint16_t val);
uint16_t i2c_read(uint8_t addr, uint8_t reg);
extern const uint8_t I2C_ADDR_XCVR;

/*
 * Time management
 */
void delay(uint32_t n);

#endif

