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

#ifndef INTERRUPTS_H
#define INTERRUPTS_H

void INT_WDTI(void) __attribute__((interrupt));
void INT_LVI(void) __attribute__((interrupt));
void INT_P0(void) __attribute__((interrupt));
void INT_P1(void) __attribute__((interrupt));
void INT_P2(void) __attribute__((interrupt));
void INT_P3(void) __attribute__((interrupt));
void INT_DMA0(void) __attribute__((interrupt));
void INT_DMA1(void) __attribute__((interrupt));
void INT_ST0(void) __attribute__((interrupt));
void INT_SR0(void) __attribute__((interrupt));
void INT_SRE0(void) __attribute__((interrupt));
void INT_TM01H(void) __attribute__((interrupt));
void INT_TM03H(void) __attribute__((interrupt));
void INT_IICA0(void) __attribute__((interrupt));
void INT_TM00(void) __attribute__((interrupt));
void INT_TM01(void) __attribute__((interrupt));
void INT_TM02(void) __attribute__((interrupt));
void INT_TM03(void) __attribute__((interrupt));
void INT_AD(void) __attribute__((interrupt));
void INT_IT(void) __attribute__((interrupt));
void INT_KR(void) __attribute__((interrupt));
void INT_MD(void) __attribute__((interrupt));
void INT_FL(void) __attribute__((interrupt));
void INT_BRK_I(void) __attribute__((interrupt));

/* Hardware interrupts */
void PowerOnReset(void) __attribute__((interrupt));

#endif

