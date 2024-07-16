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

#ifndef REGISTERS_H
#define REGISTERS_H

#include "common.h"

/********************************************************
*  declare SFR addresses                                *
********************************************************/
#pragma ADDRESS pm0_addr     0x0004    // Processor mode register0
#pragma ADDRESS pm1_addr     0x0005    // Processor mode register1
#pragma ADDRESS cm0_addr     0x0006    // System clock control register0
#pragma ADDRESS cm1_addr     0x0007    // System clock control register1
#pragma ADDRESS aier_addr    0x0009    // Address match interrupt enable register
#pragma ADDRESS prcr_addr    0x000A    // Protect register
#pragma ADDRESS ocd_addr     0x000C    // Oscillation stop detect register
#pragma ADDRESS wdtr_addr    0x000D    // Watchdog timer reset register
#pragma ADDRESS wdts_addr    0x000E    // Watchdog timer start register
#pragma ADDRESS wdc_addr     0x000F    // Watchdog timer control register
#pragma ADDRESS rmad0_addr   0x0010    // Address match interrupt register0
#pragma ADDRESS rmad1_addr   0x0014    // Address match interrupt register1
#pragma ADDRESS cspr_addr    0x001C    // Count source protect mode register
#pragma ADDRESS int0f_addr   0x001E    // INT0 input filter select register
#pragma ADDRESS hra0_addr    0x0020    // High-speed on-chip oscillator A control register 0
#pragma ADDRESS hra1_addr    0x0021    // High-speed on-chip oscillator A control register 1
#pragma ADDRESS hra2_addr    0x0022    // High-speed on-chip oscillator A control register 2
#pragma ADDRESS vca1_addr    0x0031    // Voltage detection A register 1
#pragma ADDRESS vca2_addr    0x0032    // Voltage detection A register 2
#pragma ADDRESS vw1c_addr    0x0036    // Voltage monitor 1 circuit control register
#pragma ADDRESS vw2c_addr    0x0037    // Voltage monitor 2 circuit control register
#pragma ADDRESS kupic_addr   0x004D    // Key input interrupt control register
#pragma ADDRESS adic_addr    0x004E    // Comparator conversion interrupt control register
#pragma ADDRESS cmp1ic_addr  0x0050    // Compare 1 interrupt control register
#pragma ADDRESS s0tic_addr   0x0051    // UART0 transmit interrupt control register
#pragma ADDRESS s0ric_addr   0x0052    // UART0 receive interrupt control register
#pragma ADDRESS s1tic_addr   0x0053    // UART1 transmit interrupt control register
#pragma ADDRESS s1ric_addr   0x0054    // UART1 receive interrupt control register
#pragma ADDRESS txic_addr    0x0056    // Timer X interrupt control register
#pragma ADDRESS tzic_addr    0x0058    // Timer Z interrupt control register
#pragma ADDRESS int1ic_addr  0x0059    // INT1 interrupt control register
#pragma ADDRESS int3ic_addr  0x005A    // INT3 interrupt control register
#pragma ADDRESS tcic_addr    0x005B    // Timer C interrupt control register
#pragma ADDRESS cmp0ic_addr  0x005C    // Compare 0 interrupt control register
#pragma ADDRESS int0ic_addr  0x005D    // INT0 interrupt control register
#pragma ADDRESS tzmr_addr    0x0080    // Timer Z mode register
#pragma ADDRESS tyzmr_addr   0x0080    // Timer Z mode register
#pragma ADDRESS pum_addr     0x0084    // Timer Z waveform output control register
#pragma ADDRESS prez_addr    0x0085    // Prescaler Z
#pragma ADDRESS tzsc_addr    0x0086    // Timer Z secondary
#pragma ADDRESS tzpr_addr    0x0087    // Timer Z primary
#pragma ADDRESS tzoc_addr    0x008A    // Timer Z output control register
#pragma ADDRESS tyzoc_addr   0x008A    // Timer Z output control register
#pragma ADDRESS txmr_addr    0x008B    // Timer X mode register
#pragma ADDRESS prex_addr    0x008C    // Prescaler X
#pragma ADDRESS tx_addr      0x008D    // Timer X register
#pragma ADDRESS tcss_addr    0x008E    // Timer count source select register
#pragma ADDRESS tc_addr      0x0090    // Timer C  register
#pragma ADDRESS inten_addr   0x0096    // External input enable register
#pragma ADDRESS kien_addr    0x0098    // Key input enable register
#pragma ADDRESS tcc0_addr    0x009A    // Timer C control register0
#pragma ADDRESS tcc1_addr    0x009B    // Timer C control register1
#pragma ADDRESS tm0_addr     0x009C    // Capture and compare0 register
#pragma ADDRESS tm1_addr     0x009E    // Compare1 register
#pragma ADDRESS u0mr_addr    0x00A0    // UART0 transmit/receive mode register
#pragma ADDRESS u0brg_addr   0x00A1    // UART0 bit rate generator
#pragma ADDRESS u0tb_addr    0x00A2    // UART0 transmit buffer register
#pragma ADDRESS u0c0_addr    0x00A4    // UART0 transmit/receive control register0
#pragma ADDRESS u0c1_addr    0x00A5    // UART0 transmit/receive control register1
#pragma ADDRESS u0rb_addr    0x00A6    // UART0 receive buffer register
#pragma ADDRESS u1mr_addr    0x00A8    // UART1 transmit/receive mode register
#pragma ADDRESS u1brg_addr   0x00A9    // UART1 bit rate generator
#pragma ADDRESS u1tb_addr    0x00AA    // UART1 transmit buffer register
#pragma ADDRESS u1c0_addr    0x00AC    // UART1 transmit/receive control register0
#pragma ADDRESS u1c1_addr    0x00AD    // UART1 transmit/receive control register1
#pragma ADDRESS u1rb_addr    0x00AE    // UART1 receive buffer register
#pragma ADDRESS ucon_addr    0x00B0    // UART transmit/receive control register2
#pragma ADDRESS ad_addr      0x00C0    // A-D register
#pragma ADDRESS adcon2_addr  0x00D4    // A-D control register2
#pragma ADDRESS adcon0_addr  0x00D6    // A-D control register0
#pragma ADDRESS adcon1_addr  0x00D7    // A-D control register1
#pragma ADDRESS p1_addr      0x00E1    // Port P1 register
#pragma ADDRESS pd1_addr     0x00E3    // Port P1 direction register
#pragma ADDRESS p3_addr      0x00E5    // Port P3 register
#pragma ADDRESS pd3_addr     0x00E7    // Port P3 direction register
#pragma ADDRESS p4_addr      0x00E8    // Port P4 register
#pragma ADDRESS pd4_addr     0x00EA    // Port P4 direction register
#pragma ADDRESS pur0_addr    0x00FC    // Pull-up control register0
#pragma ADDRESS pur1_addr    0x00FD    // Pull-up control register1
#pragma ADDRESS drr_addr     0x00FE    // Port P1 drivability control register
#pragma ADDRESS tcout_addr   0x00FF    // Timer C output control register
#pragma ADDRESS fmr4_addr    0x01B3    // Flash memory control register4
#pragma ADDRESS fmr1_addr    0x01B5    // Flash memory control register1
#pragma ADDRESS fmr0_addr    0x01B7    // Flash memory control register0

/********************************************************
*  declare SFR bit                                      *
********************************************************/
struct bit_def {
    unsigned char  b0:1;
    unsigned char  b1:1;
    unsigned char  b2:1;
    unsigned char  b3:1;
    unsigned char  b4:1;
    unsigned char  b5:1;
    unsigned char  b6:1;
    unsigned char  b7:1;
};

union byte_def{
  struct bit_def bit;
  unsigned char  byte;
};

/*------------------------------------------------------
  Processor mode register0
------------------------------------------------------*/
union byte_def pm0_addr;
#define    pm0           pm0_addr.byte

#define    pm03          pm0_addr.bit.b3       /* Software reset bit */

/*------------------------------------------------------
  Processor mode register1
------------------------------------------------------*/
union byte_def pm1_addr;
#define    pm1           pm1_addr.byte

#define    pm12          pm1_addr.bit.b2       /* WDT interrupt/reset select bit */

/*------------------------------------------------------
  System clock control register0
------------------------------------------------------*/
union byte_def cm0_addr;
#define    cm0           cm0_addr.byte

#define    cm02          cm0_addr.bit.b2       /* WAIT peripheral function clock stop bit */
#define    cm05          cm0_addr.bit.b5       /* Main clock (Xin-Xout) stop bit */
#define    cm06          cm0_addr.bit.b6       /* Main clock division select bit0 */

/*------------------------------------------------------
  System clock control register1
------------------------------------------------------*/
union byte_def cm1_addr;
#define    cm1           cm1_addr.byte

#define    cm10          cm1_addr.bit.b0       /* All clock stop control bit */
#define    cm13          cm1_addr.bit.b3       /* Port Xin-Xout switch bits */
#define    cm14          cm1_addr.bit.b4       /* Low-speed on-chip oscillator stop bit */
#define    cm15          cm1_addr.bit.b5       /* Xin-Xout drive capability select bit */
#define    cm16          cm1_addr.bit.b6       /* Main clock division select bit1 */
#define    cm17          cm1_addr.bit.b7       /* Main clock division select bit1 */

/*------------------------------------------------------
  Address match interrupt enable register
------------------------------------------------------*/
union byte_def aier_addr;
#define    aier          aier_addr.byte

#define    aier0         aier_addr.bit.b0      /* Address match interrupt 0 enable bit */
#define    aier1         aier_addr.bit.b1      /* Address match interrupt 1 enable bit */

/*------------------------------------------------------
  Protect register
------------------------------------------------------*/
union byte_def prcr_addr;
#define    prcr          prcr_addr.byte

#define    prc0          prcr_addr.bit.b0      /* Protect bit0 */
#define    prc1          prcr_addr.bit.b1      /* Protect bit1 */
#define    prc3          prcr_addr.bit.b3      /* Protect bit3 */

/*------------------------------------------------------
  Oscillation stop detection register
------------------------------------------------------*/
union byte_def ocd_addr;
#define    ocd           ocd_addr.byte

#define    ocd0          ocd_addr.bit.b0       /* Oscillation stop detection enabble bit */
#define    ocd1          ocd_addr.bit.b1       /* Oscillation stop detection enabble bit */
#define    ocd2          ocd_addr.bit.b2       /* System clock select bit */
#define    ocd3          ocd_addr.bit.b3       /* Clock monitor bit */

/*------------------------------------------------------
  Watchdog timer reset register
------------------------------------------------------*/
union byte_def wdtr_addr;
#define    wdtr          wdtr_addr.byte

/*------------------------------------------------------
  Watchdog timer start register
------------------------------------------------------*/
union byte_def wdts_addr;
#define    wdts          wdts_addr.byte

/*------------------------------------------------------
  Watchdog timer control register
------------------------------------------------------*/
union byte_def wdc_addr;
#define    wdc           wdc_addr.byte

#define    wdc7          wdc_addr.bit.b7       /* Prescaler select bit */

/*------------------------------------------------------
  Count source protect mode register
------------------------------------------------------*/
union byte_def cspr_addr;
#define    cspr          cspr_addr.byte
#define    cspro         cspr_addr.bit.b7      /* WDT count source protect mode select bit */

/*------------------------------------------------------
  INT0 input filter select register
------------------------------------------------------*/
union byte_def int0f_addr;
#define    int0f         int0f_addr.byte

#define    int0f0        int0f_addr.bit.b0     /* INT0 input filter select bit */
#define    int0f1        int0f_addr.bit.b1     /* INT0 input filter select bit */

/*------------------------------------------------------
  High-speed on-chip oscillator A control register 0
------------------------------------------------------*/
union byte_def hra0_addr;
#define    hra0          hra0_addr.byte

#define    hra00         hra0_addr.bit.b0      /* High-speed on-chip oscillator A enable bit */
#define    hra01         hra0_addr.bit.b1      /* High-speed on-chip oscillator A select bit */

/*------------------------------------------------------
  High-speed on-chip oscillator A control register 1
------------------------------------------------------*/
union byte_def hra1_addr;
#define    hra1          hra1_addr.byte

/*------------------------------------------------------
  High-speed on-chip oscillator A control register 2
------------------------------------------------------*/
union byte_def hra2_addr;
#define    hra2          hra2_addr.byte

#define    hra20         hra2_addr.bit.b0      /* High-speed on-chip oscillator mode select bit */
#define    hra21         hra2_addr.bit.b1      /* High-speed on-chip oscillator mode select bit */

/*------------------------------------------------------
  Voltage detection A register 1
------------------------------------------------------*/
union byte_def vca1_addr;
#define    vca1          vca1_addr.byte

#define    vca13         vca1_addr.bit.b3      /* Voltage detection 2 signal monitor flag */

/*------------------------------------------------------
  Voltage detection A register 2
------------------------------------------------------*/
union byte_def vca2_addr;
#define    vca2          vca2_addr.byte

#define    vca26         vca2_addr.bit.b6      /* Voltage detection 1 enable bit */
#define    vca27         vca2_addr.bit.b7      /* Voltage detection 2 enable bit */

/*------------------------------------------------------
  Voltage monitor 1 circuit control register
------------------------------------------------------*/
union byte_def vw1c_addr;
#define    vw1c          vw1c_addr.byte

#define    vw1c0         vw1c_addr.bit.b0      /* Voltage monitor 1 reset enable bit */
#define    vw1c1         vw1c_addr.bit.b1      /* Voltage Monitor 1 digital filter disable mode select bit */
#define    vw1c2         vw1c_addr.bit.b2      /* Voltage change detection flag */
#define    vw1c3         vw1c_addr.bit.b3      /* Voltage detection 1 signal monitor flag */
#define    vw1f0         vw1c_addr.bit.b4      /* Sampling clock select bit */
#define    vw1f1         vw1c_addr.bit.b5      /* Sampling clock select bit */
#define    vw1c6         vw1c_addr.bit.b6      /* Voltage monitor 1 circuit mode select bit */
#define    vw1c7         vw1c_addr.bit.b7      /* Voltage monitor 1 reset generating condition select bit */

/*------------------------------------------------------
  Voltage monitor 2 circuit control register
------------------------------------------------------*/
union byte_def vw2c_addr;
#define    vw2c          vw2c_addr.byte

#define    vw2c0         vw2c_addr.bit.b0      /* Voltage monitor 2 interrupt / reset enable bit */
#define    vw2c1         vw2c_addr.bit.b1      /* Voltage monitor 2 digital filter disabled mode select bit */
#define    vw2c2         vw2c_addr.bit.b2      /* Voltage change detection flag */
#define    vw2c3         vw2c_addr.bit.b3      /* WDT Detection Flag */
#define    vw2f0         vw2c_addr.bit.b4      /* Sampling clock select bit */
#define    vw2f1         vw2c_addr.bit.b5      /* Sampling clock select bit */
#define    vw2c6         vw2c_addr.bit.b6      /* Voltage monitor 2 circuit mode select bit */
#define    vw2c7         vw2c_addr.bit.b7      /* Voltage monitor 2 interrupt / reset generating condition select bit */

/*------------------------------------------------------
  Timer Z Mode register
------------------------------------------------------*/
union byte_def tzmr_addr;
#define    tzmr          tzmr_addr.byte
#define    tyzmr         tyzmr_addr.byte

#define    tzmod0        tzmr_addr.bit.b4      /* TimerZ Operation mode bit */
#define    tzmod1        tzmr_addr.bit.b5      /* TimerZ Operation mode bit */
#define    tzwc          tzmr_addr.bit.b6      /* TimerZ write control bit */
#define    tzs           tzmr_addr.bit.b7      /* TimerZ count start flag */

/*------------------------------------------------------
  Timer Z waveform output control register
------------------------------------------------------*/
union byte_def pum_addr;
#define    pum           pum_addr.byte

#define    tzopl         pum_addr.bit.b5       /* TimerZ output level latch */
#define    inostg        pum_addr.bit.b6       /* INT0 pin one-shot trigger control bit */
#define    inoseg        pum_addr.bit.b7       /* INT0 pin one-shot trigger polarity select bit */

/*------------------------------------------------------
  Prescaler Z register
------------------------------------------------------*/
union byte_def prez_addr;
#define    prez          prez_addr.byte

/*------------------------------------------------------
  Timer Z secondary register
------------------------------------------------------*/
union byte_def tzsc_addr;
#define    tzsc          tzsc_addr.byte

/*------------------------------------------------------
  Timer Z primary register
------------------------------------------------------*/
union byte_def tzpr_addr;
#define    tzpr          tzpr_addr.byte

/*------------------------------------------------------
  Timer Z output control register
------------------------------------------------------*/
union byte_def tzoc_addr;
#define    tzoc          tzoc_addr.byte
#define    tyzoc         tzoc_addr.byte

#define    tzos          tzoc_addr.bit.b0      /* TimerZ one-shot start bit */
#define    tzocnt        tzoc_addr.bit.b2      /* TimerZ programable waveform generation output switching bit */

/*------------------------------------------------------
  Timer X mode register
------------------------------------------------------*/
union byte_def txmr_addr;
#define    txmr          txmr_addr.byte

#define    txmod0        txmr_addr.bit.b0      /* Operation mode select bit0 */
#define    txmod1        txmr_addr.bit.b1      /* Operation mode select bit1 */
#define    r0edg         txmr_addr.bit.b2      /* INT1/CNTR0 polarity switching bit */
#define    txs           txmr_addr.bit.b3      /* TimerX count start flag */
#define    txocnt        txmr_addr.bit.b4      /* P30/CNTR0 select bit */
#define    txmod2        txmr_addr.bit.b5      /* Operation mode select bit2 */
#define    txedg         txmr_addr.bit.b6      /* Active edge reception flag */
#define    txund         txmr_addr.bit.b7      /* TimerX under flow flag */

/*------------------------------------------------------
  Prescaler X Register
------------------------------------------------------*/
union byte_def prex_addr;
#define    prex          prex_addr.byte

/*------------------------------------------------------
  Timer X Register
------------------------------------------------------*/
union byte_def tx_addr;
#define    tx            tx_addr.byte

/*------------------------------------------------------
  Timer count source setting register
------------------------------------------------------*/
union byte_def tcss_addr;
#define    tcss          tcss_addr.byte

#define    txck0         tcss_addr.bit.b0      /* TimerX count source select bit */
#define    txck1         tcss_addr.bit.b1      /* TimerX count source select bit */
#define    tzck0         tcss_addr.bit.b4      /* TimerZ count source select bit */
#define    tzck1         tcss_addr.bit.b5      /* TimerZ count source select bit */

/*------------------------------------------------------
  External interrupt enable register
------------------------------------------------------*/
union byte_def inten_addr;
#define    inten         inten_addr.byte

#define    int0en        inten_addr.bit.b0     /* INT0 input enable bit */
#define    int0pl        inten_addr.bit.b1     /* INT0 input polarity select bit */

/*------------------------------------------------------
  Key input enable register
------------------------------------------------------*/
union byte_def kien_addr;
#define    kien          kien_addr.byte

#define    ki0en         kien_addr.bit.b0      /* KI0 input enable bit */
#define    ki0pl         kien_addr.bit.b1      /* KI0 input polarity select bit */
#define    ki1en         kien_addr.bit.b2      /* KI1 input enable bit */
#define    ki1pl         kien_addr.bit.b3      /* KI1 input polarity select bit */
#define    ki2en         kien_addr.bit.b4      /* KI2 input enable bit */
#define    ki2pl         kien_addr.bit.b5      /* KI2 input polarity select bit */
#define    ki3en         kien_addr.bit.b6      /* KI3 input enable bit */
#define    ki3pl         kien_addr.bit.b7      /* KI3 input polarity select bit */

/*------------------------------------------------------
  Timer C control register0
------------------------------------------------------*/
union byte_def tcc0_addr;
#define    tcc0          tcc0_addr.byte

#define    tcc00         tcc0_addr.bit.b0      /* TimerC control bit */
#define    tcc01         tcc0_addr.bit.b1      /* TimerC count source select bit */
#define    tcc02         tcc0_addr.bit.b2      /* TimerC count source select bit */
#define    tcc03         tcc0_addr.bit.b3      /* INT3 interrupt and capture polarity select bit */
#define    tcc04         tcc0_addr.bit.b4      /* INT3 interrupt and capture polarity select bit */
#define    tcc06         tcc0_addr.bit.b6      /* INT3 interrupt request generation timing select bit */
#define    tcc07         tcc0_addr.bit.b7      /* INT3 interrupt/capture input switching bit */

/*------------------------------------------------------
  Timer C control register1
------------------------------------------------------*/
union byte_def tcc1_addr;
#define    tcc1          tcc1_addr.byte

#define    tcc10         tcc1_addr.bit.b0      /* INT3 input filter select bit */
#define    tcc11         tcc1_addr.bit.b1      /* INT3 input filter select bit */
#define    tcc12         tcc1_addr.bit.b2      /* TimerC counter reload select bit */
#define    tcc13         tcc1_addr.bit.b3      /* Compare0/capture select bit */
#define    tcc14         tcc1_addr.bit.b4      /* Compare0 output mode select bit */
#define    tcc15         tcc1_addr.bit.b5      /* Compare0 output mode select bit */
#define    tcc16         tcc1_addr.bit.b6      /* Compare1 output mode select bit */
#define    tcc17         tcc1_addr.bit.b7      /* Compare1 output mode select bit */

/*------------------------------------------------------
  UART0 bit rate generator
------------------------------------------------------*/
union byte_def u0brg_addr;
#define    u0brg         u0brg_addr.byte

/*------------------------------------------------------
  UART1 bit rate generator
------------------------------------------------------*/
union byte_def u1brg_addr;
#define    u1brg   u1brg_addr.byte

/*------------------------------------------------------
  UART transmit/receive control register2
------------------------------------------------------*/
union byte_def ucon_addr;
#define    ucon          ucon_addr.byte

#define    u0irs         ucon_addr.bit.b0      /* UART0 transmit interrupt cause select bit */
#define    u1irs         ucon_addr.bit.b1      /* UART1 transmit interrupt cause select bit */
#define    u0rrm         ucon_addr.bit.b2      /* UART0 continuous receive mode enable bit */
#define    u1sel0        ucon_addr.bit.b4      /* UART1 pin (P3_7/TXD1,P4_5/RXD1) select bit */
#define    u1sel1        ucon_addr.bit.b5      /* UART1 pin (P3_7/TXD1,P4_5/RXD1) select bit */
#define    cntrsel       ucon_addr.bit.b7      /* Cntr0 signal pin select bit */

/*------------------------------------------------------
  A-D control register2
------------------------------------------------------*/
union byte_def adcon2_addr;
#define    adcon2        adcon2_addr.byte

#define    cmpsel        adcon2_addr.bit.b1    /* Comparator function selection bit */

/*------------------------------------------------------
  A-D control register0
------------------------------------------------------*/
union byte_def adcon0_addr;
#define    adcon0        adcon0_addr.byte

#define    ch0           adcon0_addr.bit.b0    /* Analog input pin select bit */
#define    ch1           adcon0_addr.bit.b1    /* Analog input pin select bit */
#define    ch2           adcon0_addr.bit.b2    /* Analog input pin select bit */
#define    md            adcon0_addr.bit.b3    /* Comparator conversion operating mode select bit */
#define    adgsel0       adcon0_addr.bit.b4    /* A-D input group select bit */
#define    adcap         adcon0_addr.bit.b5    /* Comparator conversion automatic start bit */
#define    adst          adcon0_addr.bit.b6    /* Comparator conversion start flag */
#define    cks0          adcon0_addr.bit.b7    /* Frequency select bit0 */
#define    cks0_adcon0   cks0

/*------------------------------------------------------
  A-D control register1
------------------------------------------------------*/
union byte_def adcon1_addr;
#define    adcon1        adcon1_addr.byte

#define    cks1          adcon1_addr.bit.b4    /* Frequency select bit1 */
#define    cks1_adcon1   cks1

/*------------------------------------------------------
  Port P1 register
------------------------------------------------------*/
union byte_def p1_addr;
#define    p1            p1_addr.byte

#define    p1_0          p1_addr.bit.b0        /* Port P10 bit */
#define    p1_1          p1_addr.bit.b1        /* Port P11 bit */
#define    p1_2          p1_addr.bit.b2        /* Port P12 bit */
#define    p1_3          p1_addr.bit.b3        /* Port P13 bit */
#define    p1_4          p1_addr.bit.b4        /* Port P14 bit */
#define    p1_5          p1_addr.bit.b5        /* Port P15 bit */
#define    p1_6          p1_addr.bit.b6        /* Port P16 bit */
#define    p1_7          p1_addr.bit.b7        /* Port P17 bit */

/*------------------------------------------------------
  Port P1 direction register
------------------------------------------------------*/
union byte_def pd1_addr;
#define    pd1           pd1_addr.byte

#define    pd1_0         pd1_addr.bit.b0       /* Port P10 direction bit */
#define    pd1_1         pd1_addr.bit.b1       /* Port P11 direction bit */
#define    pd1_2         pd1_addr.bit.b2       /* Port P12 direction bit */
#define    pd1_3         pd1_addr.bit.b3       /* Port P13 direction bit */
#define    pd1_4         pd1_addr.bit.b4       /* Port P14 direction bit */
#define    pd1_5         pd1_addr.bit.b5       /* Port P15 direction bit */
#define    pd1_6         pd1_addr.bit.b6       /* Port P16 direction bit */
#define    pd1_7         pd1_addr.bit.b7       /* Port P17 direction bit */

/*------------------------------------------------------
  Port P3 register
------------------------------------------------------*/
union byte_def p3_addr;
#define    p3            p3_addr.byte

#define    p3_3          p3_addr.bit.b3        /* Port P33 bit */
#define    p3_4          p3_addr.bit.b4        /* Port P34 bit */
#define    p3_5          p3_addr.bit.b5        /* Port P35 bit */
#define    p3_7          p3_addr.bit.b7        /* Port P37 bit */

/*------------------------------------------------------
  Port P3 direction register
------------------------------------------------------*/
union byte_def pd3_addr;
#define    pd3           pd3_addr.byte

#define    pd3_3         pd3_addr.bit.b3       /* Port P33 direction bit */
#define    pd3_4         pd3_addr.bit.b4       /* Port P34 direction bit */
#define    pd3_5         pd3_addr.bit.b5       /* Port P35 direction bit */
#define    pd3_7         pd3_addr.bit.b7       /* Port P37 direction bit */

/*------------------------------------------------------
  Port P4 register
------------------------------------------------------*/
union byte_def p4_addr;
#define    p4            p4_addr.byte

#define    p4_2          p4_addr.bit.b2        /* Port P42 bit */
#define    p4_5          p4_addr.bit.b5        /* Port P45 bit */
#define    p4_6          p4_addr.bit.b6        /* Port P46 bit */
#define    p4_7          p4_addr.bit.b7        /* Port P47 bit */

/*------------------------------------------------------
  Port P4 direction register
------------------------------------------------------*/
union byte_def pd4_addr;
#define    pd4           pd4_addr.byte

#define    pd4_5         pd4_addr.bit.b5       /* Port P45 direction bit */

/*------------------------------------------------------
  Pull-up control register0
------------------------------------------------------*/
union byte_def pur0_addr;
#define    pur0          pur0_addr.byte

#define    pu02          pur0_addr.bit.b2      /* P10 to P13 pull-up */
#define    pu03          pur0_addr.bit.b3      /* P14 to P17 pull-up */
#define    pu06          pur0_addr.bit.b6      /* P33 pull-up */
#define    pu07          pur0_addr.bit.b7      /* P34, P35, P37 pull-up */

/*------------------------------------------------------
  Pull-up control register1
------------------------------------------------------*/
union byte_def pur1_addr;
#define    pur1          pur1_addr.byte

#define    pu11          pur1_addr.bit.b1      /* P45 pull-up */

/*------------------------------------------------------
  Port P1 drive capacity control register
------------------------------------------------------*/
union byte_def drr_addr;
#define    drr           drr_addr.byte

#define    drr0          drr_addr.bit.b0       /* P10 capacity */
#define    drr1          drr_addr.bit.b1       /* P11 capacity */
#define    drr2          drr_addr.bit.b2       /* P12 capacity */
#define    drr3          drr_addr.bit.b3       /* P13 capacity */

/*------------------------------------------------------
  Timer C output control register
------------------------------------------------------*/
union byte_def tcout_addr;
#define    tcout         tcout_addr.byte

#define    tcout0        tcout_addr.bit.b0     /* CMP output enable bit0 */
#define    tcout1        tcout_addr.bit.b1     /* CMP output enable bit1 */
#define    tcout2        tcout_addr.bit.b2     /* CMP output enable bit2 */
#define    tcout3        tcout_addr.bit.b3     /* CMP output enable bit3 */
#define    tcout4        tcout_addr.bit.b4     /* CMP output enable bit4 */
#define    tcout5        tcout_addr.bit.b5     /* CMP output enable bit5 */
#define    tcout6        tcout_addr.bit.b6     /* CMP output reverse bit0 */
#define    tcout7        tcout_addr.bit.b7     /* CMP output reverse bit1 */

/*------------------------------------------------------
  Flash mamory control register4
------------------------------------------------------*/
union byte_def fmr4_addr;
#define    fmr4          fmr4_addr.byte

#define    fmr40         fmr4_addr.bit.b0      /* Erase-suspend function enable bit */
#define    fmr41         fmr4_addr.bit.b1      /* Erase-suspend request bit */
#define    fmr42         fmr4_addr.bit.b2      /* Program-suspend request bit */
#define    fmr43         fmr4_addr.bit.b3      /* Erase command flag */
#define    fmr44         fmr4_addr.bit.b4      /* Program command flag */
#define    fmr46         fmr4_addr.bit.b6      /* Read status flag */
#define    fmr47         fmr4_addr.bit.b7      /* Low-Power consumption read mode enable bit */

/*------------------------------------------------------
  Flash mamory control register1
------------------------------------------------------*/
union byte_def fmr1_addr;
#define    fmr1          fmr1_addr.byte

#define    fmr11         fmr1_addr.bit.b1      /* EW1 mode select bit */
#define    fmr15         fmr1_addr.bit.b5      /* Block0 rewrite disable bit */
#define    fmr16         fmr1_addr.bit.b6      /* Block1 rewrite disable bit */

/*------------------------------------------------------
  Flash mamory control register0
------------------------------------------------------*/
union byte_def fmr0_addr;
#define    fmr0          fmr0_addr.byte

#define    fmr00         fmr0_addr.bit.b0      /* RY/BY status flag */
#define    fmr01         fmr0_addr.bit.b1      /* CPU rewrite mode select bit */
#define    fmr02         fmr0_addr.bit.b2      /* Block0 and 1 rewrite enable bit */
#define    fmstp         fmr0_addr.bit.b3      /* Flash memory stop bit */
#define    fmr06         fmr0_addr.bit.b6      /* Program status flag  */
#define    fmr07         fmr0_addr.bit.b7      /* Erase status flag */

/*------------------------------------------------------
  Interrupt control register
------------------------------------------------------*/
union{
  struct{
    unsigned char  ilvl0:1;                             /* Interrupt priority level select bit */
    unsigned char  ilvl1:1;                             /* Interrupt priority level select bit */
    unsigned char  ilvl2:1;                             /* Interrupt priority level select bit */
    unsigned char  ir:1;                                /* Interrupt request bit */
    unsigned char  pol:1;                               /* Polarity select bit */
    unsigned char  b5:1;
    unsigned char  b6:1;
    unsigned char  b7:1;
  }bit;
  unsigned char  byte;
} kupic_addr, adic_addr, cmp1ic_addr, s0tic_addr, s0ric_addr, s1tic_addr, s1ric_addr, txic_addr,
  tzic_addr, int1ic_addr, int3ic_addr, tcic_addr, cmp0ic_addr, int0ic_addr;

/*------------------------------------------------------
  Key input interrupt control register
------------------------------------------------------*/
#define     kupic         kupic_addr.byte

#define     ilvl0_kupic   kupic_addr.bit.ilvl0
#define     ilvl1_kupic   kupic_addr.bit.ilvl1
#define     ilvl2_kupic   kupic_addr.bit.ilvl2
#define     ir_kupic      kupic_addr.bit.ir

/*------------------------------------------------------
  Comparator conversion interrupt control register
------------------------------------------------------*/
#define     adic          adic_addr.byte

#define     ilvl0_adic    adic_addr.bit.ilvl0
#define     ilvl1_adic    adic_addr.bit.ilvl1
#define     ilvl2_adic    adic_addr.bit.ilvl2
#define     ir_adic       adic_addr.bit.ir

/*------------------------------------------------------
  Compare 1 interrupt control register
------------------------------------------------------*/
#define     cmp1ic        cmp1ic_addr.byte

#define     ilvl0_cmp1ic  cmp1ic_addr.bit.ilvl0
#define     ilvl1_cmp1ic  cmp1ic_addr.bit.ilvl1
#define     ilvl2_cmp1ic  cmp1ic_addr.bit.ilvl2
#define     ir_cmp1ic     cmp1ic_addr.bit.ir

/*------------------------------------------------------
  UART0 transmit interrupt control register
------------------------------------------------------*/
#define     s0tic         s0tic_addr.byte

#define     ilvl0_s0tic   s0tic_addr.bit.ilvl0
#define     ilvl1_s0tic   s0tic_addr.bit.ilvl1
#define     ilvl2_s0tic   s0tic_addr.bit.ilvl2
#define     ir_s0tic      s0tic_addr.bit.ir

/*------------------------------------------------------
  UART0 receive interrupt control register
------------------------------------------------------*/
#define     s0ric         s0ric_addr.byte

#define     ilvl0_s0ric   s0ric_addr.bit.ilvl0
#define     ilvl1_s0ric   s0ric_addr.bit.ilvl1
#define     ilvl2_s0ric   s0ric_addr.bit.ilvl2
#define     ir_s0ric      s0ric_addr.bit.ir

/*------------------------------------------------------
  UART1 transmit interrupt control register
------------------------------------------------------*/
#define     s1tic         s1tic_addr.byte

#define     ilvl0_s1tic   s1tic_addr.bit.ilvl0
#define     ilvl1_s1tic   s1tic_addr.bit.ilvl1
#define     ilvl2_s1tic   s1tic_addr.bit.ilvl2
#define     ir_s1tic      s1tic_addr.bit.ir

/*------------------------------------------------------
  UART1 receive interrupt control register
------------------------------------------------------*/
#define     s1ric         s1ric_addr.byte

#define     ilvl0_s1ric   s1ric_addr.bit.ilvl0
#define     ilvl1_s1ric   s1ric_addr.bit.ilvl1
#define     ilvl2_s1ric   s1ric_addr.bit.ilvl2
#define     ir_s1ric      s1ric_addr.bit.ir

/*------------------------------------------------------
  Timer X interrupt control register
------------------------------------------------------*/
#define     txic          txic_addr.byte

#define     ilvl0_txic    txic_addr.bit.ilvl0
#define     ilvl1_txic    txic_addr.bit.ilvl1
#define     ilvl2_txic    txic_addr.bit.ilvl2
#define     ir_txic       txic_addr.bit.ir

/*------------------------------------------------------
  Timer Z interrupt control register
------------------------------------------------------*/
#define     tzic          tzic_addr.byte

#define     ilvl0_tzic    tzic_addr.bit.ilvl0
#define     ilvl1_tzic    tzic_addr.bit.ilvl1
#define     ilvl2_tzic    tzic_addr.bit.ilvl2
#define     ir_tzic       tzic_addr.bit.ir

/*------------------------------------------------------
  INT1 interrupt control register
------------------------------------------------------*/
#define     int1ic        int1ic_addr.byte

#define     ilvl0_int1ic  int1ic_addr.bit.ilvl0
#define     ilvl1_int1ic  int1ic_addr.bit.ilvl1
#define     ilvl2_int1ic  int1ic_addr.bit.ilvl2
#define     ir_int1ic     int1ic_addr.bit.ir
/*------------------------------------------------------
  INT3 interrupt control register
------------------------------------------------------*/
#define     int3ic        int3ic_addr.byte

#define     ilvl0_int3ic  int3ic_addr.bit.ilvl0
#define     ilvl1_int3ic  int3ic_addr.bit.ilvl1
#define     ilvl2_int3ic  int3ic_addr.bit.ilvl2
#define     ir_int3ic     int3ic_addr.bit.ir
/*------------------------------------------------------
  Timer C interrupt control register
------------------------------------------------------*/
#define     tcic          tcic_addr.byte

#define     ilvl0_tcic    tcic_addr.bit.ilvl0
#define     ilvl1_tcic    tcic_addr.bit.ilvl1
#define     ilvl2_tcic    tcic_addr.bit.ilvl2
#define     ir_tcic       tcic_addr.bit.ir

/*------------------------------------------------------
  Compare 0 interrupt control register
------------------------------------------------------*/
#define     cmp0ic        cmp0ic_addr.byte

#define     ilvl0_cmp0ic  cmp0ic_addr.bit.ilvl0
#define     ilvl1_cmp0ic  cmp0ic_addr.bit.ilvl1
#define     ilvl2_cmp0ic  cmp0ic_addr.bit.ilvl2
#define     ir_cmp0ic     cmp0ic_addr.bit.ir

/*------------------------------------------------------
  INT0 interrupt control register
------------------------------------------------------*/
#define     int0ic        int0ic_addr.byte

#define     ilvl0_int0ic  int0ic_addr.bit.ilvl0
#define     ilvl1_int0ic  int0ic_addr.bit.ilvl1
#define     ilvl2_int0ic  int0ic_addr.bit.ilvl2
#define     ir_int0ic     int0ic_addr.bit.ir
#define     pol_int0ic    int0ic_addr.bit.pol

/*------------------------------------------------------
  UARTi transmit/receive mode register
------------------------------------------------------*/
union{
  struct{
    unsigned char  smd0  :1;    /* Serial I/O mode select bit */
    unsigned char  smd1  :1;    /* Serial I/O mode select bit */
    unsigned char  smd2  :1;    /* Serial I/O mode select bit */
    unsigned char  ckdir :1;    /* Internal/external clock select bit */
    unsigned char  stps  :1;    /* Stop bit length select bit */
    unsigned char  pry   :1;    /* Odd/even parity select bit */
    unsigned char  prye  :1;    /* Parity enable bit */
    unsigned char  b7    :1;
  }bit;
  unsigned char  byte;
}u0mr_addr,u1mr_addr;

/*------------------------------------------------------
  UART0 transmit/receive mode register
------------------------------------------------------*/
#define    u0mr          u0mr_addr.byte

#define    smd0_u0mr     u0mr_addr.bit.smd0    /* Serial I/O mode select bit */
#define    smd1_u0mr     u0mr_addr.bit.smd1    /* Serial I/O mode select bit */
#define    smd2_u0mr     u0mr_addr.bit.smd2    /* Serial I/O mode select bit */
#define    ckdir_u0mr    u0mr_addr.bit.ckdir   /* Internal/external clock select bit */
#define    stps_u0mr     u0mr_addr.bit.stps    /* Stop bit length select bit */
#define    pry_u0mr      u0mr_addr.bit.pry     /* Odd/even parity select bit */
#define    prye_u0mr     u0mr_addr.bit.prye    /* Parity enable bit */

/*------------------------------------------------------
  UART1 transmit/receive mode register
------------------------------------------------------*/
#define    u1mr          u1mr_addr.byte

#define    smd0_u1mr     u1mr_addr.bit.smd0    /* Serial I/O mode select bit */
#define    smd1_u1mr     u1mr_addr.bit.smd1    /* Serial I/O mode select bit */
#define    smd2_u1mr     u1mr_addr.bit.smd2    /* Serial I/O mode select bit */
#define    ckdir_u1mr    u1mr_addr.bit.ckdir   /* Internal/external clock select bit */
#define    stps_u1mr     u1mr_addr.bit.stps    /* Stop bit length select bit */
#define    pry_u1mr      u1mr_addr.bit.pry     /* Odd/even parity select bit */
#define    prye_u1mr     u1mr_addr.bit.prye    /* Parity enable bit */

/*------------------------------------------------------
  UARTi transmit/receive control register0
------------------------------------------------------*/
union{
  struct{
    unsigned char  clk0  :1;    /* BRG count source select bit */
    unsigned char  clk1  :1;    /* BRG count source select bit */
    unsigned char  b2    :1;
    unsigned char  txept :1;    /* Transmit register empty flag */
    unsigned char  b4    :1;
    unsigned char  nch   :1;    /* Data output select bit */
    unsigned char  ckpol :1;    /* CLK polarity select bit */
    unsigned char  uform :1;    /* Transfer format select bit */
  }bit;
  unsigned char  byte;
}u0c0_addr,u1c0_addr;

/*------------------------------------------------------
  UART0 transmit/receive control register0
------------------------------------------------------*/
#define    u0c0          u0c0_addr.byte

#define    clk0_u0c0     u0c0_addr.bit.clk0    /* BRG count source select bit */
#define    clk1_u0c0     u0c0_addr.bit.clk1    /* BRG count source select bit */
#define    txept_u0c0    u0c0_addr.bit.txept   /* Transmit register empty flag */
#define    nch_u0c0      u0c0_addr.bit.nch     /* Data output select bit */
#define    ckpol_u0c0    u0c0_addr.bit.ckpol   /* CLK polarity select bit */
#define    uform_u0c0    u0c0_addr.bit.uform   /* Transfer format select bit */

/*------------------------------------------------------
  UART1 transmit/receive control register0
------------------------------------------------------*/
#define    u1c0          u1c0_addr.byte

#define    clk0_u1c0     u1c0_addr.bit.clk0    /* BRG count source select bit */
#define    clk1_u1c0     u1c0_addr.bit.clk1    /* BRG count source select bit */
#define    txept_u1c0    u1c0_addr.bit.txept   /* Transmit register empty flag */
#define    nch_u1c0      u1c0_addr.bit.nch     /* Data output select bit */
#define    ckpol_u1c0    u1c0_addr.bit.ckpol   /* CLK polarity select bit */
#define    uform_u1c0    u1c0_addr.bit.uform   /* Transfer format select bit */

/*------------------------------------------------------
  UARTi transmit/receive control register1
------------------------------------------------------*/
union{
  struct{
    unsigned char  te:1;        /* Transmit enable bit */
    unsigned char  ti:1;        /* Transmit buffer empty flag */
    unsigned char  re:1;        /* Receive enable bit */
    unsigned char  ri:1;        /* Receive complete flag */
    unsigned char  b4:1;
    unsigned char  b5:1;
    unsigned char  b6:1;
    unsigned char  b7:1;
  }bit;
  unsigned char  byte;
}u0c1_addr,u1c1_addr;

/*------------------------------------------------------
  UART0 transmit/receive control register1
------------------------------------------------------*/
#define    u0c1          u0c1_addr.byte

#define    te_u0c1       u0c1_addr.bit.te      /* Transmit enable bit */
#define    ti_u0c1       u0c1_addr.bit.ti      /* Transmit buffer empty flag */
#define    re_u0c1       u0c1_addr.bit.re      /* Receive enable bit */
#define    ri_u0c1       u0c1_addr.bit.ri      /* Receive complete flag */

/*------------------------------------------------------
  UART1 transmit/receive control register1
------------------------------------------------------*/
#define    u1c1          u1c1_addr.byte

#define    te_u1c1       u1c1_addr.bit.te      /* Transmit enable bit */
#define    ti_u1c1       u1c1_addr.bit.ti      /* Transmit buffer empty flag */
#define    re_u1c1       u1c1_addr.bit.re      /* Receive enable bit */
#define    ri_u1c1       u1c1_addr.bit.ri      /* Receive complete flag */

/*------------------------------------------------------
  UARTi receive buffer register
------------------------------------------------------*/
union{
  struct{
    unsigned char  b0:1;
    unsigned char  b1:1;
    unsigned char  b2:1;
    unsigned char  b3:1;
    unsigned char  b4:1;
    unsigned char  b5:1;
    unsigned char  b6:1;
    unsigned char  b7:1;
    unsigned char  b8:1;
    unsigned char  b9:1;
    unsigned char  b10:1;
    unsigned char  b11:1;
    unsigned char  oer:1;       /* Overrun error flag */
    unsigned char  fer:1;       /* Framing error flag */
    unsigned char  per:1;       /* Parity error flag */
    unsigned char  sum:1;       /* Error sum flag */
  }bit;
   struct{
    unsigned char  low;         /* Low  8 bit */
    unsigned char  high;        /* High 8 bit */
  }byte;
  unsigned short  word;
}u0rb_addr,u1rb_addr;

/*------------------------------------------------------
  UART0 receive buffer register
------------------------------------------------------*/
#define    u0rb          u0rb_addr.word
#define    u0rbl         u0rb_addr.byte.low
#define    u0rbh         u0rb_addr.byte.high

#define    oer_u0rb      u0rb_addr.bit.oer     /* Overrun error flag */
#define    fer_u0rb      u0rb_addr.bit.fer     /* Framing error flag */
#define    per_u0rb      u0rb_addr.bit.per     /* Parity error flag */
#define    sum_u0rb      u0rb_addr.bit.sum     /* Error sum flag */

/*------------------------------------------------------
  UART1 receive buffer register
------------------------------------------------------*/
#define    u1rb          u1rb_addr.word
#define    u1rbl         u1rb_addr.byte.low
#define    u1rbh         u1rb_addr.byte.high

#define    oer_u1rb      u1rb_addr.bit.oer     /* Overrun error flag */
#define    fer_u1rb      u1rb_addr.bit.fer     /* Framing error flag */
#define    per_u1rb      u1rb_addr.bit.per     /* Parity error flag */
#define    sum_u1rb      u1rb_addr.bit.sum     /* Error sum flag */

/********************************************************
*  declare SFR union                                    *
********************************************************/

union{
  struct{
    unsigned char  b0:1;
    unsigned char  b1:1;
    unsigned char  b2:1;
    unsigned char  b3:1;
    unsigned char  b4:1;
    unsigned char  b5:1;
    unsigned char  b6:1;
    unsigned char  b7:1;
    unsigned char  b8:1;
    unsigned char  b9:1;
    unsigned char  b10:1;
    unsigned char  b11:1;
    unsigned char  b12:1;
    unsigned char  b13:1;
    unsigned char  b14:1;
    unsigned char  b15:1;
    unsigned char  b16:1;
    unsigned char  b17:1;
    unsigned char  b18:1;
    unsigned char  b19:1;
   }bit;
   struct{
    unsigned char  low;         /* low  8 bit */
    unsigned char  mid;         /* mid  8 bit */
    unsigned char  high;        /* high 8 bit */
    unsigned char  nc;          /* non use */
  }byte;

  unsigned long  dword;
}rmad0_addr,rmad1_addr;

#define    rmad0         rmad0_addr.dword      /* Address match interrupt register0 */
#define    rmad0l        rmad0_addr.byte.low   /* Address match interrupt register0 Low */
#define    rmad0m        rmad0_addr.byte.mid   /* Address match interrupt register0 Middle */
#define    rmad0h        rmad0_addr.byte.high  /* Address match interrupt register0 High */
#define    rmad1         rmad1_addr.dword      /* Address match interrupt register1 */
#define    rmad1l        rmad1_addr.byte.low   /* Address match interrupt register1 Low */
#define    rmad1m        rmad1_addr.byte.mid   /* Address match interrupt register1 Middle */
#define    rmad1h        rmad1_addr.byte.high  /* Address match interrupt register1 High */


union{
  struct{
    unsigned char  b0:1;
    unsigned char  b1:1;
    unsigned char  b2:1;
    unsigned char  b3:1;
    unsigned char  b4:1;
    unsigned char  b5:1;
    unsigned char  b6:1;
    unsigned char  b7:1;
    unsigned char  b8:1;
    unsigned char  b9:1;
    unsigned char  b10:1;
    unsigned char  b11:1;
    unsigned char  b12:1;
    unsigned char  b13:1;
    unsigned char  b14:1;
    unsigned char  b15:1;
   }bit;
  struct{
    unsigned char  low;         /* low  8 bit */
    unsigned char  high;        /* high 8 bit */
  }byte;
  unsigned int  word;
} tc_addr, tm0_addr, tm1_addr, u0tb_addr, u1tb_addr, ad_addr;

#define    tc            tc_addr.word          /* Timer C */
#define    tcl           tc_addr.byte.low      /* Timer C Low */
#define    tch           tc_addr.byte.high     /* Timer C High */
#define    tm0           tm0_addr.word         /* Capture, compare0 register */
#define    tm0l          tm0_addr.byte.low     /* Capture, compare0 register Low */
#define    tm0h          tm0_addr.byte.high    /* Capture, compare0 register High */
#define    tm1           tm1_addr.word         /* Compare1 register */
#define    tm1l          tm1_addr.byte.low     /* Compare1 register Low */
#define    tm1h          tm1_addr.byte.high    /* Compare1 register High */
#define    u0tb          u0tb_addr.word        /* UART0 transmit buffer register */
#define    u0tbl         u0tb_addr.byte.low    /* UART0 transmit buffer register Low */
#define    u0tbh         u0tb_addr.byte.high   /* UART0 transmit buffer register High */
#define    u1tb          u1tb_addr.word        /* UART1 transmit buffer register */
#define    u1tbl         u1tb_addr.byte.low    /* UART1 transmit buffer register Low */
#define    u1tbh         u1tb_addr.byte.high   /* UART1 transmit buffer register High */
#define    ad            ad_addr.word          /* A-D register  */
#define    adl           ad_addr.byte.low      /* A-D register Low */

#endif

