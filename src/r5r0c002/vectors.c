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
#include "interrupts.h"

#define ID1 0xFF
#define ID2 0xFF
#define ID3 0xFF
#define ID4 0xFF
#define ID5 0xFF
#define ID6 0xFF
#define ID7 0xFF

#define OFS 0xFF

const void *HardwareVectors[] __attribute__((section(".vec"))) = {
    (void *)0xFFFF, (void *)(0x0000 | ID1 << 8), // 0x00
    (void *)0xFFFF, (void *)(0x0000 | ID2 << 8), // 0x01
    (void *)0xFFFF, (void *)(0x0000),            // 0x02
    (void *)0xFFFF, (void *)(0x0000 | ID3 << 8), // 0x03
    (void *)0xFFFF, (void *)(0x0000 | ID4 << 8), // 0x04
    (void *)0xFFFF, (void *)(0x0000 | ID5 << 8), // 0x05
    (void *)0xFFFF, (void *)(0x0000 | ID6 << 8), // 0x06
    (void *)0xFFFF, (void *)(0x0000 | ID7 << 8), // 0x07
    (void *)start,  (void *)(0x0000 | OFS << 8), // 0x08
};

const void *Vectors[] __attribute__((section(".var_vects"))) = {
    INT_BRK_I,      (void *)0x0000, // 0x00
    (void *)0xFFFF, (void *)0x0000, // 0x01
    (void *)0xFFFF, (void *)0x0000, // 0x02
    (void *)0xFFFF, (void *)0x0000, // 0x03
    (void *)0xFFFF, (void *)0x0000, // 0x04
    (void *)0xFFFF, (void *)0x0000, // 0x05
    (void *)0xFFFF, (void *)0x0000, // 0x06
    (void *)0xFFFF, (void *)0x0000, // 0x07
    (void *)0xFFFF, (void *)0x0000, // 0x08
    (void *)0xFFFF, (void *)0x0000, // 0x09
    (void *)0xFFFF, (void *)0x0000, // 0x0A
    (void *)0xFFFF, (void *)0x0000, // 0x0B
    (void *)0xFFFF, (void *)0x0000, // 0x0C
    INT_KI,         (void *)0x0000, // 0x0D
    INT_AD,         (void *)0x0000, // 0x0E
    INT_IIC,        (void *)0x0000, // 0x0F
    INT_CMP1,       (void *)0x0000, // 0x10
    INT_ST0,        (void *)0x0000, // 0x11
    INT_SR0,        (void *)0x0000, // 0x12
    INT_ST1,        (void *)0x0000, // 0x13
    INT_SR1,        (void *)0x0000, // 0x14
    (void *)0xFFFF, (void *)0x0000, // 0x15
    INT_TMRX,       (void *)0x0000, // 0x16
    (void *)0xFFFF, (void *)0x0000, // 0x17
    INT_TMRZ,       (void *)0x0000, // 0x18
    INT_INT1,       (void *)0x0000, // 0x19
    INT_INT3,       (void *)0x0000, // 0x1A
    INT_TMRC,       (void *)0x0000, // 0x1B
    INT_CMP0,       (void *)0x0000, // 0x1C
    INT_INT0,       (void *)0x0000, // 0x1D
    (void *)0xFFFF, (void *)0x0000, // 0x1E
    (void *)0xFFFF, (void *)0x0000, // 0x1F
};
