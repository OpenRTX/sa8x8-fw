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
    asm("nop");
    asm("nop");
    asm("nop");
  }
}

/*
 * Initialize UART0 for communication
 */
void uart_init(void) {
  PIOR &= (uint8_t)
          ~(1U << 1); // Disable RxD0/TxD0 alternate

  PM1_bit.no1 = 1;    // P11 (RxD0) is input until configured
  PM1_bit.no2 = 1;    // P12 (TxD0) is input until configured

  SAU0EN = 1;         // Release and enable clock to serial array unit 0
  delay(1);           // Delay recommended by hardware manual

  SPS0 = 0x0033U;     // Set operation clock:
                      //* <07>PRS013=0, <06>PRS012=0
                      //* <05>PRS011=1, <04>PRS010=1: CK01 is fCLK / 2**3
                      //* <03>PRS003=0, <02>PRS002=0
                      //* <01>PRS001=1, <00>PRS000=1: CK00 is fCLK / 2**3

  ST0 = 0x03U;        // Stop serial channel 0

  STMK0 = 1U;         // Disable INTST0 interrupt
  STIF0 = 0U;         // Clear INTST0 interrupt flag
  STPR10 = 1U;        // Set INTST0 lowest priority
  STPR00 = 1U;        // Set INTST0 lowest priority

  SRMK0 = 1U;         // Disable INTSR0 interrupt
  SRIF0 = 0U;         // Clear INTSR0 interrupt
  SRPR10 = 1U;        // Set INTSR0 lowest priority
  SRPR00 = 1U;        // Set INTSR0 lowest priority

  SREMK0 = 1U;        // Disable INTSRE0 interrupt
  SREIF0 = 0U;        // Clear INTSRE0 interrupt flag
  SREPR10 = 1U;       // Set INTSRE0 lowest priority
  SREPR00 = 1U;       // Set INTSRE0 lowest priority

  SMR00 = 0x0023U;    // Set operation mode:
                      //* <15>CKS00=0: Operation clock CK00 set by SPS0
                      //* <14>CCS00=0: Divide fMCK specified by CKS00
                      //* <08>STS00=1: Interrupt trigger by software only
                      //* <02>MD002=0, <01>MD001=1: UART mode
                      //* <00>MD000=1: Buffer empty interrupt

  SCR00 = 0x8097U;    // Set communication format:
                      //* <15>TXE00=1, <14>RXE00=0: Transmission enabled
                      //* <13>DAP00=0, <12>CKP00=0: Required for UART mode
                      //* <10>EOC00=0: Disables generation of interrupt INTSRE0
                      //* <09>PTC001=0, <08>PTC000=0: No parity bit
                      //* <07>DIR00=1: LSB first
                      //* <05>SLC001=0, <04>SLC000=1: Single stop bit
                      //* <01>DLS001=1, <00>DLS000=1: 8-bit data length

  SDR00 = 0xBE00U;    // Set transfer symbol rate: fMCK / 192

  NFEN0 |= 0x01U;     // Enable reception noise filtering
  SIR01 |= 0x07U;     // Clear error flags

  SMR01 = 0x0122U;    // Set operation mode:
                      //* <15>CKS01=0: Operation clock CK01 set by SPS0
                      //* <14>CCS01=0: Divide fMCK specified by CKS01
                      //* <08>STS01=1: Interrupt trigger valid edge of RXD0 pin
                      //* <02>MD012=0, <01>MD011=1: UART mode
                      //* <00>MD010=0: Transfer end interrupt

  SCR01 = 0x4097U;    // Set communication format:
                      //* <15>TXE01=0, <14>RXE01=1: Reception enabled
                      //* <13>DAP01=0, <12>CKP01=0: Required for UART mode
                      //* <10>EOC01=0: Disables generation of interrupt INTSRE0
                      //* <09>PTC011=0, <08>PTC010=0: No parity bit
                      //* <07>DIR01=1: LSB first
                      //* <05>SLC011=0, <04>SLC010=1: Single stop bit
                      //* <01>DLS011=1, <00>DLS010=1: 8-bit data length

  SDR01 = 0xBE00U;    // Set receive symbol rate: fMCK / 192

  SO0 |= 0x01U;     // Set buffered output of serial communication array channel
  SOE0 |= 0x01U;    // Enable output of serial communication array channel

  P1_bit.no2 = 1;   // P12 (TxD0) is high
  PM1_bit.no2 = 0;  // P12 (TxD0) is output
  PMC1_bit.no2 = 0; // P12 (TxD0) is digital I/O

  PM1_bit.no1 = 1;  // P11 (RxD0) is input
  PMC1_bit.no1 = 0; // P12 (RxD0) is digital I/O

  SS0 |= 0x03U;     // Serial channel start operation

  SRMK0 = 0U;       // Enable INTSR0 interrupt
  STIF0 = 1;        // Set transmit buffer empty interrupt flag
}

/*
 * Transmit a string through UART0
 */
int uart_puts(const char *s) {
  int len = 0;

  SMR00 |= 0x0001U;

  while ('\0' != *s) {
    while (0U == STIF0)
      ;
    STIF0 = 0U;
    TXD0 = (unsigned char)*s++;
    ++len;
  }

  SMR00 &= ~0x0001U;

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
  PM4_bit.no1 = 1; // P41 (SDIO) is input
}

static inline void _i2c_sdio_output(void) {
  PM4_bit.no1 = 0; // P41 (SDIO) is output
}

static inline void _i2c_sdio_high(void) {
  P4_bit.no1 = 1; // P41 (SDIO) is high
}

static inline void _i2c_sdio_low(void) {
  P4_bit.no1 = 0; // P41 (SDIO) is low
}

static inline uint8_t _i2c_sdio_value() {
  return P4_bit.no1; // P41 (SDIO) read
}

static inline void _i2c_sclk_output(void) {
  PM4_bit.no2 = 0; // P42 (SCLK) is output
}

static inline void _i2c_sclk_high(void) {
  P4_bit.no2 = 1; // P42 (SCLK) is high
}

static inline void _i2c_sclk_low(void) {
  P4_bit.no2 = 0; // P42 (SCLK) is low
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
  PIOR &= (uint8_t)
          ~(1U << 3); // Disable P41/P42 alternate

  PMC4_bit.no1 = 0;   // P41 (SDIO) is digital I/O
  PMC4_bit.no2 = 0;   // P42 (SCLK) is digital I/O

  PU4_bit.no1 = 1;    // P41 (SDIO) pull-up enabled
  PU4_bit.no2 = 1;    // P42 (SCLK) pull-up enabled

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
  asm("di");   // Disable interrupts

  CMC = 0x41U; // 14.7456 MHz external oscillator
  MSTOP = 0U;  // X1 oscillator operating

  MCM0 = 1U;   // High-speed system clock (fMX) as main clock (fMAIN)

  while (MCS == 0U)
    ;               // Wait for clock switch

  uart_init();      // Setup UART0 for transmission and reception
  i2c_init();       // Setup software I2C for bus transactions

  PMC1_bit.no3 = 0; // P13 (PDN) is digital I/O
  P1_bit.no3 = 1;   // P13 (PDN) is high
  PM1_bit.no3 = 0;  // P13 (PDN) is output

  PMC1_bit.no1 = 0; // P10 (RXEN) is digital I/O
  P1_bit.no0 = 0;   // P10 (RXEN) is low
  PM1_bit.no0 = 0;  // P10 (RXEN) is output

  ADPC |= 0x01;     // P20 (SQ) is digital I/O
  P2_bit.no0 = 1;   // P20 (SQ) is high
  PM2_bit.no0 = 0;  // P20 (SQ) is output

  PM2_bit.no2 = 1;  // P22 (PTT) is input

  PMC1_bit.no4 = 0; // P14  (GPIO0) is digital I/O
  PM1_bit.no4 = 1;  // P14  (GPIO0) is input: css indicator
  PM2_bit.no3 = 1;  // P23  (GPIO6) is input: squelch indicator
                    // P137 (GPIO7) is input: vox indicator

  asm("ei");        // Enable interrupts
}

void platform_sleep(void) {
  asm("halt"); // Enter low power mode
}

void platform_turbo(void) {
  asm("di"); // Disable interrupts

  SOE0 &= 0xFEU; // Disable output of serial communication array channel

  SPS0 = 0x0022U; // Set operation clock:
                  //* <07>PRS013=0, <06>PRS012=0
                  //* <05>PRS011=1, <04>PRS010=0: CK01 is fCLK / 2**2
                  //* <03>PRS003=0, <02>PRS002=0
                  //* <01>PRS001=1, <00>PRS000=0: CK00 is fCLK / 2**2

  ST0 = 0x03U; // Stop serial channel 0

  SDR00 = 0x1E00U; // Set transfer symbol rate: fMCK / 32
  SDR01 = 0x1E00U; // Set receive symbol rate: fMCK / 32

  SS0 |= 0x03U; // Serial channel start operation

  SOE0 |= 0x01U; // Enable output of serial communication array channel

  asm("ei"); // Enable interrupts
}

void platform_refresh(bool *sq, bool *css, bool *vox) {
  *sq = P2_bit.no3;  // Squelch status from internal AT1846S
  P2_bit.no0 = !*sq; // Squelch status to external pin

  *css = P1_bit.no4;  // CSS status from internal AT1846S
  *vox = P13_bit.no7; // VOX status from internal AT1846S
}

bool platform_poke(uint8_t addr, uint8_t reg, uint16_t val) {
  // Not possible to TX and RX simultaneously
  if (reg == 0x30 && (val & (1 << 6)) && (val & (1 << 5))) {
    return false;
  }

  // TX requested so disable RXEN
  if (reg == 0x30 && (val & (1 << 6))) {
    P1_bit.no0 = 1; // P10 (RXEN) is high
  }

  i2c_write(addr, reg, val);

  // RX requested so enable RXEN
  if (reg == 0x30 && (val & (1 << 5))) {
    P1_bit.no0 = 0; // P10 (RXEN) is low
  }

  return true;
}
