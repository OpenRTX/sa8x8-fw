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

#include "interrupts.h"
#include "common.h"
#include "registers.h"

void INT_BRK_I(void) {}
void INT_KI(void) {}
void INT_AD(void) {}
void INT_IIC(void) {}
void INT_CMP1(void) {}
void INT_ST0(void) {}
void INT_SR0(void) {
  ring_put(&rx, (char)u0rb);
  ir_s0ric = 0U;
}
void INT_ST1(void) {}
void INT_SR1(void) {}
void INT_TMRX(void) {}
void INT_TMRZ(void) {}
void INT_INT1(void) {}
void INT_INT3(void) {}
void INT_TMRC(void) {}
void INT_CMP0(void) {}
void INT_INT0(void) {}
