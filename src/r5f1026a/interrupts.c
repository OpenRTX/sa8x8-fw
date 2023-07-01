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

#include "interrupts.h"
#include "common.h"
#include "registers.h"

void INT_WDTI(void) {}
void INT_LVI(void) {}
void INT_P0(void) {}
void INT_P1(void) {}
void INT_P2(void) {}
void INT_P3(void) {}
void INT_DMA0(void) {}
void INT_DMA1(void) {}
void INT_ST0(void) {}
void INT_SR0(void) {
  ring_put(&rx, (char)RXD0);
  SRIF0 = 0U;
}
void INT_SRE0(void) {}
void INT_TM01H(void) {}
void INT_TM03H(void) {}
void INT_IICA0(void) {}
void INT_TM00(void) {}
void INT_TM01(void) {}
void INT_TM02(void) {}
void INT_TM03(void) {}
void INT_AD(void) {}
void INT_IT(void) {}
void INT_KR(void) {}
void INT_MD(void) {}
void INT_FL(void) {}
void INT_BRK_I(void) {}

