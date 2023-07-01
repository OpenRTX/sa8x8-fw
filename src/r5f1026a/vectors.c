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
#include "interrupts.h"

const uint8_t OptionBytes[] __attribute__((section(".option_bytes"))) = {
    0xEF, // WDT disabled
    0xFF, // LVD off
    0xE9, // HS clock 16 MHz
    0x85  // OCD enabled
};

const uint8_t SecurityID[] __attribute__((section(".security_id"))) = {
    0x00, // Never
    0x00, // gonna
    0x00, // give
    0x00, // you
    0x00, // up!
    0x00, // Never
    0x00, // gonna
    0x00, // let
    0x00, // you
    0x00  // down!
};

extern void PowerOnReset(void);

const void *HardwareVectors[] __attribute__((section(".vec"))) = {
    PowerOnReset,  // Address 0x0
    (void *)0xFFFF // Secure for debugging
};

const void *Vectors[] __attribute__((section(".vects"))) = {
    INT_WDTI,       // 0x04
    INT_LVI,        // 0x06
    INT_P0,         // 0x08
    INT_P1,         // 0x0A
    INT_P2,         // 0x0C
    INT_P3,         // 0x0E
    INT_DMA0,       // 0x10
    INT_DMA1,       // 0x12
    INT_ST0,        // 0x14
    INT_SR0,        // 0x16
    INT_SRE0,       // 0x18
    INT_TM01H,      // 0x1A
    INT_TM03H,      // 0x1C
    INT_IICA0,      // 0x1E
    INT_TM00,       // 0x20
    INT_TM01,       // 0x22
    INT_TM02,       // 0x24
    INT_TM03,       // 0x26
    INT_AD,         // 0x28
    INT_IT,         // 0x2A
    INT_KR,         // 0x2C
    INT_MD,         // 0x2E
    INT_FL,         // 0x30
    (void *)0xFFFF, // Padding
    (void *)0xFFFF, // Padding
    (void *)0xFFFF, // Padding
    (void *)0xFFFF, // Padding
    (void *)0xFFFF, // Padding
    (void *)0xFFFF, // Padding
    (void *)0xFFFF, // Padding
    (void *)0xFFFF, // Padding
    (void *)0xFFFF, // Padding
    (void *)0xFFFF, // Padding
    (void *)0xFFFF, // Padding
    (void *)0xFFFF, // Padding
    (void *)0xFFFF, // Padding
    (void *)0xFFFF, // Padding
    (void *)0xFFFF, // Padding
    (void *)0xFFFF, // Padding
    (void *)0xFFFF, // Padding
    (void *)0xFFFF, // Padding
    (void *)0xFFFF, // Padding
    (void *)0xFFFF, // Padding
    (void *)0xFFFF, // Padding
    (void *)0xFFFF, // Padding
    (void *)0xFFFF, // Padding
    (void *)0xFFFF, // Padding
    (void *)0xFFFF, // Padding
    (void *)0xFFFF, // Padding
    (void *)0xFFFF, // Padding
    (void *)0xFFFF, // Padding
    (void *)0xFFFF, // Padding
    (void *)0xFFFF, // Padding
    (void *)0xFFFF, // Padding
    (void *)0xFFFF, // Padding
    (void *)0xFFFF, // Padding
    (void *)0xFFFF, // Padding
    (void *)0xFFFF, // Padding
    (void *)0xFFFF, // Padding
    (void *)0xFFFF, // Padding
    (void *)0xFFFF, // Padding
    INT_BRK_I,      // 0x7E
};

