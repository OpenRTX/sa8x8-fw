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

#ifndef INTERRUPTS_H
#define INTERRUPTS_H

void INT_BRK_I(void) __attribute__((interrupt));
void INT_KI(void) __attribute__((interrupt));
void INT_AD(void) __attribute__((interrupt));
void INT_IIC(void) __attribute__((interrupt));
void INT_CMP1(void) __attribute__((interrupt));
void INT_ST0(void) __attribute__((interrupt));
void INT_SR0(void) __attribute__((interrupt));
void INT_ST1(void) __attribute__((interrupt));
void INT_SR1(void) __attribute__((interrupt));
void INT_TMRX(void) __attribute__((interrupt));
void INT_TMRZ(void) __attribute__((interrupt));
void INT_INT1(void) __attribute__((interrupt));
void INT_INT3(void) __attribute__((interrupt));
void INT_TMRC(void) __attribute__((interrupt));
void INT_CMP0(void) __attribute__((interrupt));
void INT_INT0(void) __attribute__((interrupt));

/* Hardware interrupts */
void start(void) __attribute__((interrupt));

#endif
