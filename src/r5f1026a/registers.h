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

#ifndef REGISTERS_H
#define REGISTERS_H

#include "common.h"

/*
 * Helper types
 */
union un_adm2 {
  uint8_t adm2;
  __BITS8 BIT;
};
union un_pu1 {
  uint8_t pu1;
  __BITS8 BIT;
};
union un_pu4 {
  uint8_t pu4;
  __BITS8 BIT;
};
union un_pu12 {
  uint8_t pu12;
  __BITS8 BIT;
};
union un_pim1 {
  uint8_t pim1;
  __BITS8 BIT;
};
union un_pom1 {
  uint8_t pom1;
  __BITS8 BIT;
};
union un_pom4 {
  uint8_t pom4;
  __BITS8 BIT;
};
union un_pmc1 {
  uint8_t pmc1;
  __BITS8 BIT;
};
union un_pmc4 {
  uint8_t pmc4;
  __BITS8 BIT;
};
union un_nfen0 {
  uint8_t nfen0;
  __BITS8 BIT;
};
union un_nfen1 {
  uint8_t nfen1;
  __BITS8 BIT;
};
union un_isc {
  uint8_t isc;
  __BITS8 BIT;
};
union un_dflctl {
  uint8_t dflctl;
  __BITS8 BIT;
};
union un_mduc {
  uint8_t mduc;
  __BITS8 BIT;
};
union un_per0 {
  uint8_t per0;
  __BITS8 BIT;
};
union un_rmc {
  uint8_t rmc;
  __BITS8 BIT;
};
union un_rpectl {
  uint8_t rpectl;
  __BITS8 BIT;
};
union un_se0l {
  uint8_t se0l;
  __BITS8 BIT;
};
union un_ss0l {
  uint8_t ss0l;
  __BITS8 BIT;
};
union un_st0l {
  uint8_t st0l;
  __BITS8 BIT;
};
union un_soe0l {
  uint8_t soe0l;
  __BITS8 BIT;
};
union un_te0l {
  uint8_t te0l;
  __BITS8 BIT;
};
union un_ts0l {
  uint8_t ts0l;
  __BITS8 BIT;
};
union un_tt0l {
  uint8_t tt0l;
  __BITS8 BIT;
};
union un_toe0l {
  uint8_t toe0l;
  __BITS8 BIT;
};
union un_iicctl00 {
  uint8_t iicctl00;
  __BITS8 BIT;
};
union un_iicctl01 {
  uint8_t iicctl01;
  __BITS8 BIT;
};
union un_p1 {
  uint8_t p1;
  __BITS8 BIT;
};
union un_p2 {
  uint8_t p2;
  __BITS8 BIT;
};
union un_p4 {
  uint8_t p4;
  __BITS8 BIT;
};
union un_p6 {
  uint8_t p6;
  __BITS8 BIT;
};
union un_p12 {
  uint8_t p12;
  __BITS8 BIT;
};
union un_p13 {
  uint8_t p13;
  __BITS8 BIT;
};
union un_pm1 {
  uint8_t pm1;
  __BITS8 BIT;
};
union un_pm2 {
  uint8_t pm2;
  __BITS8 BIT;
};
union un_pm4 {
  uint8_t pm4;
  __BITS8 BIT;
};
union un_pm6 {
  uint8_t pm6;
  __BITS8 BIT;
};
union un_adm0 {
  uint8_t adm0;
  __BITS8 BIT;
};
union un_ads {
  uint8_t ads;
  __BITS8 BIT;
};
union un_adm1 {
  uint8_t adm1;
  __BITS8 BIT;
};
union un_krctl {
  uint8_t krctl;
  __BITS8 BIT;
};
union un_krm0 {
  uint8_t krm0;
  __BITS8 BIT;
};
union un_egp0 {
  uint8_t egp0;
  __BITS8 BIT;
};
union un_egn0 {
  uint8_t egn0;
  __BITS8 BIT;
};
union un_iics0 {
  uint8_t iics0;
  __BITS8 BIT;
};
union un_iicf0 {
  uint8_t iicf0;
  __BITS8 BIT;
};
union un_csc {
  uint8_t csc;
  __BITS8 BIT;
};
union un_ostc {
  uint8_t ostc;
  __BITS8 BIT;
};
union un_ckc {
  uint8_t ckc;
  __BITS8 BIT;
};
union un_cks0 {
  uint8_t cks0;
  __BITS8 BIT;
};
union un_lvim {
  uint8_t lvim;
  __BITS8 BIT;
};
union un_lvis {
  uint8_t lvis;
  __BITS8 BIT;
};
union un_dmc0 {
  uint8_t dmc0;
  __BITS8 BIT;
};
union un_dmc1 {
  uint8_t dmc1;
  __BITS8 BIT;
};
union un_drc0 {
  uint8_t drc0;
  __BITS8 BIT;
};
union un_drc1 {
  uint8_t drc1;
  __BITS8 BIT;
};
union un_if0 {
  uint16_t if0;
  __BITS16 BIT;
};
union un_if0l {
  uint8_t if0l;
  __BITS8 BIT;
};
union un_if0h {
  uint8_t if0h;
  __BITS8 BIT;
};
union un_if1 {
  uint16_t if1;
  __BITS16 BIT;
};
union un_if1l {
  uint8_t if1l;
  __BITS8 BIT;
};
union un_mk0 {
  uint16_t mk0;
  __BITS16 BIT;
};
union un_mk0l {
  uint8_t mk0l;
  __BITS8 BIT;
};
union un_mk0h {
  uint8_t mk0h;
  __BITS8 BIT;
};
union un_mk1 {
  uint16_t mk1;
  __BITS16 BIT;
};
union un_mk1l {
  uint8_t mk1l;
  __BITS8 BIT;
};
union un_pr00 {
  uint16_t pr00;
  __BITS16 BIT;
};
union un_pr00l {
  uint8_t pr00l;
  __BITS8 BIT;
};
union un_pr00h {
  uint8_t pr00h;
  __BITS8 BIT;
};
union un_pr01 {
  uint16_t pr01;
  __BITS16 BIT;
};
union un_pr01l {
  uint8_t pr01l;
  __BITS8 BIT;
};
union un_pr10 {
  uint16_t pr10;
  __BITS16 BIT;
};
union un_pr10l {
  uint8_t pr10l;
  __BITS8 BIT;
};
union un_pr10h {
  uint8_t pr10h;
  __BITS8 BIT;
};
union un_pr11 {
  uint16_t pr11;
  __BITS16 BIT;
};
union un_pr11l {
  uint8_t pr11l;
  __BITS8 BIT;
};
union un_pmc {
  uint8_t pmc;
  __BITS8 BIT;
};

/*
 * Special Function Registers
 */
#define ADM2 (*(volatile union un_adm2 *)0xF0010).adm2
#define ADM2_bit (*(volatile union un_adm2 *)0xF0010).BIT
#define ADUL (*(volatile uint8_t *)0xF0011)
#define ADLL (*(volatile uint8_t *)0xF0012)
#define ADTES (*(volatile uint8_t *)0xF0013)
#define PU1 (*(volatile union un_pu1 *)0xF0031).pu1
#define PU1_bit (*(volatile union un_pu1 *)0xF0031).BIT
#define PU4 (*(volatile union un_pu4 *)0xF0034).pu4
#define PU4_bit (*(volatile union un_pu4 *)0xF0034).BIT
#define PU12 (*(volatile union un_pu12 *)0xF003C).pu12
#define PU12_bit (*(volatile union un_pu12 *)0xF003C).BIT
#define PIM1 (*(volatile union un_pim1 *)0xF0041).pim1
#define PIM1_bit (*(volatile union un_pim1 *)0xF0041).BIT
#define POM1 (*(volatile union un_pom1 *)0xF0051).pom1
#define POM1_bit (*(volatile union un_pom1 *)0xF0051).BIT
#define POM4 (*(volatile union un_pom4 *)0xF0054).pom4
#define POM4_bit (*(volatile union un_pom4 *)0xF0054).BIT
#define PMC1 (*(volatile union un_pmc1 *)0xF0061).pmc1
#define PMC1_bit (*(volatile union un_pmc1 *)0xF0061).BIT
#define PMC4 (*(volatile union un_pmc4 *)0xF0064).pmc4
#define PMC4_bit (*(volatile union un_pmc4 *)0xF0064).BIT
#define NFEN0 (*(volatile union un_nfen0 *)0xF0070).nfen0
#define NFEN0_bit (*(volatile union un_nfen0 *)0xF0070).BIT
#define NFEN1 (*(volatile union un_nfen1 *)0xF0071).nfen1
#define NFEN1_bit (*(volatile union un_nfen1 *)0xF0071).BIT
#define ISC (*(volatile union un_isc *)0xF0073).isc
#define ISC_bit (*(volatile union un_isc *)0xF0073).BIT
#define TIS0 (*(volatile uint8_t *)0xF0074)
#define ADPC (*(volatile uint8_t *)0xF0076)
#define PIOR (*(volatile uint8_t *)0xF0077)
#define IAWCTL (*(volatile uint8_t *)0xF0078)
#define DFLCTL (*(volatile union un_dflctl *)0xF0090).dflctl
#define DFLCTL_bit (*(volatile union un_dflctl *)0xF0090).BIT
#define HIOTRM (*(volatile uint8_t *)0xF00A0)
#define HOCODIV (*(volatile uint8_t *)0xF00A8)
#define TEMPCAL0 (*(volatile uint8_t *)0xF00AC)
#define TEMPCAL1 (*(volatile uint8_t *)0xF00AD)
#define TEMPCAL2 (*(volatile uint8_t *)0xF00AE)
#define TEMPCAL3 (*(volatile uint8_t *)0xF00AF)
#define MDCL (*(volatile uint16_t *)0xF00E0)
#define MDCH (*(volatile uint16_t *)0xF00E2)
#define MDUC (*(volatile union un_mduc *)0xF00E8).mduc
#define MDUC_bit (*(volatile union un_mduc *)0xF00E8).BIT
#define PER0 (*(volatile union un_per0 *)0xF00F0).per0
#define PER0_bit (*(volatile union un_per0 *)0xF00F0).BIT
#define OSMC (*(volatile uint8_t *)0xF00F3)
#define RMC (*(volatile union un_rmc *)0xF00F4).rmc
#define RMC_bit (*(volatile union un_rmc *)0xF00F4).BIT
#define RPECTL (*(volatile union un_rpectl *)0xF00F5).rpectl
#define RPECTL_bit (*(volatile union un_rpectl *)0xF00F5).BIT
#define BCDADJ (*(volatile uint8_t *)0xF00FE)
#define SSR00 (*(volatile uint16_t *)0xF0100)
#define SSR00L (*(volatile uint8_t *)0xF0100)
#define SSR01 (*(volatile uint16_t *)0xF0102)
#define SSR01L (*(volatile uint8_t *)0xF0102)
#define SIR00 (*(volatile uint16_t *)0xF0108)
#define SIR00L (*(volatile uint8_t *)0xF0108)
#define SIR01 (*(volatile uint16_t *)0xF010A)
#define SIR01L (*(volatile uint8_t *)0xF010A)
#define SMR00 (*(volatile uint16_t *)0xF0110)
#define SMR01 (*(volatile uint16_t *)0xF0112)
#define SCR00 (*(volatile uint16_t *)0xF0118)
#define SCR01 (*(volatile uint16_t *)0xF011A)
#define SE0 (*(volatile uint16_t *)0xF0120)
#define SE0L (*(volatile union un_se0l *)0xF0120).se0l
#define SE0L_bit (*(volatile union un_se0l *)0xF0120).BIT
#define SS0 (*(volatile uint16_t *)0xF0122)
#define SS0L (*(volatile union un_ss0l *)0xF0122).ss0l
#define SS0L_bit (*(volatile union un_ss0l *)0xF0122).BIT
#define ST0 (*(volatile uint16_t *)0xF0124)
#define ST0L (*(volatile union un_st0l *)0xF0124).st0l
#define ST0L_bit (*(volatile union un_st0l *)0xF0124).BIT
#define SPS0 (*(volatile uint16_t *)0xF0126)
#define SPS0L (*(volatile uint8_t *)0xF0126)
#define SO0 (*(volatile uint16_t *)0xF0128)
#define SOE0 (*(volatile uint16_t *)0xF012A)
#define SOE0L (*(volatile union un_soe0l *)0xF012A).soe0l
#define SOE0L_bit (*(volatile union un_soe0l *)0xF012A).BIT
#define SOL0 (*(volatile uint16_t *)0xF0134)
#define SOL0L (*(volatile uint8_t *)0xF0134)
#define SSC0 (*(volatile uint16_t *)0xF0138)
#define SSC0L (*(volatile uint8_t *)0xF0138)
#define TCR00 (*(volatile uint16_t *)0xF0180)
#define TCR01 (*(volatile uint16_t *)0xF0182)
#define TCR02 (*(volatile uint16_t *)0xF0184)
#define TCR03 (*(volatile uint16_t *)0xF0186)
#define TMR00 (*(volatile uint16_t *)0xF0190)
#define TMR01 (*(volatile uint16_t *)0xF0192)
#define TMR02 (*(volatile uint16_t *)0xF0194)
#define TMR03 (*(volatile uint16_t *)0xF0196)
#define TSR00 (*(volatile uint16_t *)0xF01A0)
#define TSR00L (*(volatile uint8_t *)0xF01A0)
#define TSR01 (*(volatile uint16_t *)0xF01A2)
#define TSR01L (*(volatile uint8_t *)0xF01A2)
#define TSR02 (*(volatile uint16_t *)0xF01A4)
#define TSR02L (*(volatile uint8_t *)0xF01A4)
#define TSR03 (*(volatile uint16_t *)0xF01A6)
#define TSR03L (*(volatile uint8_t *)0xF01A6)
#define TE0 (*(volatile uint16_t *)0xF01B0)
#define TE0L (*(volatile union un_te0l *)0xF01B0).te0l
#define TE0L_bit (*(volatile union un_te0l *)0xF01B0).BIT
#define TS0 (*(volatile uint16_t *)0xF01B2)
#define TS0L (*(volatile union un_ts0l *)0xF01B2).ts0l
#define TS0L_bit (*(volatile union un_ts0l *)0xF01B2).BIT
#define TT0 (*(volatile uint16_t *)0xF01B4)
#define TT0L (*(volatile union un_tt0l *)0xF01B4).tt0l
#define TT0L_bit (*(volatile union un_tt0l *)0xF01B4).BIT
#define TPS0 (*(volatile uint16_t *)0xF01B6)
#define TO0 (*(volatile uint16_t *)0xF01B8)
#define TO0L (*(volatile uint8_t *)0xF01B8)
#define TOE0 (*(volatile uint16_t *)0xF01BA)
#define TOE0L (*(volatile union un_toe0l *)0xF01BA).toe0l
#define TOE0L_bit (*(volatile union un_toe0l *)0xF01BA).BIT
#define TOL0 (*(volatile uint16_t *)0xF01BC)
#define TOL0L (*(volatile uint8_t *)0xF01BC)
#define TOM0 (*(volatile uint16_t *)0xF01BE)
#define TOM0L (*(volatile uint8_t *)0xF01BE)
#define IICCTL00 (*(volatile union un_iicctl00 *)0xF0230).iicctl00
#define IICCTL00_bit (*(volatile union un_iicctl00 *)0xF0230).BIT
#define IICCTL01 (*(volatile union un_iicctl01 *)0xF0231).iicctl01
#define IICCTL01_bit (*(volatile union un_iicctl01 *)0xF0231).BIT
#define IICWL0 (*(volatile uint8_t *)0xF0232)
#define IICWH0 (*(volatile uint8_t *)0xF0233)
#define SVA0 (*(volatile uint8_t *)0xF0234)
#define CRCD (*(volatile uint16_t *)0xF02FA)
#define P1 (*(volatile union un_p1 *)0xFFF01).p1
#define P1_bit (*(volatile union un_p1 *)0xFFF01).BIT
#define P2 (*(volatile union un_p2 *)0xFFF02).p2
#define P2_bit (*(volatile union un_p2 *)0xFFF02).BIT
#define P4 (*(volatile union un_p4 *)0xFFF04).p4
#define P4_bit (*(volatile union un_p4 *)0xFFF04).BIT
#define P6 (*(volatile union un_p6 *)0xFFF06).p6
#define P6_bit (*(volatile union un_p6 *)0xFFF06).BIT
#define P12 (*(volatile union un_p12 *)0xFFF0C).p12
#define P12_bit (*(volatile union un_p12 *)0xFFF0C).BIT
#define P13 (*(volatile union un_p13 *)0xFFF0D).p13
#define P13_bit (*(volatile union un_p13 *)0xFFF0D).BIT
#define SDR00 (*(volatile uint16_t *)0xFFF10)
#define SIO00 (*(volatile uint8_t *)0xFFF10)
#define TXD0 (*(volatile uint8_t *)0xFFF10)
#define SDR01 (*(volatile uint16_t *)0xFFF12)
#define RXD0 (*(volatile uint8_t *)0xFFF12)
#define SIO01 (*(volatile uint8_t *)0xFFF12)
#define TDR00 (*(volatile uint16_t *)0xFFF18)
#define TDR01 (*(volatile uint16_t *)0xFFF1A)
#define TDR01L (*(volatile uint8_t *)0xFFF1A)
#define TDR01H (*(volatile uint8_t *)0xFFF1B)
#define ADCR (*(volatile uint16_t *)0xFFF1E)
#define ADCRH (*(volatile uint8_t *)0xFFF1F)
#define PM1 (*(volatile union un_pm1 *)0xFFF21).pm1
#define PM1_bit (*(volatile union un_pm1 *)0xFFF21).BIT
#define PM2 (*(volatile union un_pm2 *)0xFFF22).pm2
#define PM2_bit (*(volatile union un_pm2 *)0xFFF22).BIT
#define PM4 (*(volatile union un_pm4 *)0xFFF24).pm4
#define PM4_bit (*(volatile union un_pm4 *)0xFFF24).BIT
#define PM6 (*(volatile union un_pm6 *)0xFFF26).pm6
#define PM6_bit (*(volatile union un_pm6 *)0xFFF26).BIT
#define ADM0 (*(volatile union un_adm0 *)0xFFF30).adm0
#define ADM0_bit (*(volatile union un_adm0 *)0xFFF30).BIT
#define ADS (*(volatile union un_ads *)0xFFF31).ads
#define ADS_bit (*(volatile union un_ads *)0xFFF31).BIT
#define ADM1 (*(volatile union un_adm1 *)0xFFF32).adm1
#define ADM1_bit (*(volatile union un_adm1 *)0xFFF32).BIT
#define KRCTL (*(volatile union un_krctl *)0xFFF34).krctl
#define KRCTL_bit (*(volatile union un_krctl *)0xFFF34).BIT
#define KRF (*(volatile uint8_t *)0xFFF35)
#define KRM0 (*(volatile union un_krm0 *)0xFFF37).krm0
#define KRM0_bit (*(volatile union un_krm0 *)0xFFF37).BIT
#define EGP0 (*(volatile union un_egp0 *)0xFFF38).egp0
#define EGP0_bit (*(volatile union un_egp0 *)0xFFF38).BIT
#define EGN0 (*(volatile union un_egn0 *)0xFFF39).egn0
#define EGN0_bit (*(volatile union un_egn0 *)0xFFF39).BIT
#define IICA0 (*(volatile uint8_t *)0xFFF50)
#define IICS0 (*(volatile union un_iics0 *)0xFFF51).iics0
#define IICS0_bit (*(volatile union un_iics0 *)0xFFF51).BIT
#define IICF0 (*(volatile union un_iicf0 *)0xFFF52).iicf0
#define IICF0_bit (*(volatile union un_iicf0 *)0xFFF52).BIT
#define TDR02 (*(volatile uint16_t *)0xFFF64)
#define TDR03 (*(volatile uint16_t *)0xFFF66)
#define TDR03L (*(volatile uint8_t *)0xFFF66)
#define TDR03H (*(volatile uint8_t *)0xFFF67)
#define ITMC (*(volatile uint16_t *)0xFFF90)
#define CMC (*(volatile uint8_t *)0xFFFA0)
#define CSC (*(volatile union un_csc *)0xFFFA1).csc
#define CSC_bit (*(volatile union un_csc *)0xFFFA1).BIT
#define OSTC (*(volatile union un_ostc *)0xFFFA2).ostc
#define OSTC_bit (*(volatile union un_ostc *)0xFFFA2).BIT
#define OSTS (*(volatile uint8_t *)0xFFFA3)
#define CKC (*(volatile union un_ckc *)0xFFFA4).ckc
#define CKC_bit (*(volatile union un_ckc *)0xFFFA4).BIT
#define CKS0 (*(volatile union un_cks0 *)0xFFFA5).cks0
#define CKS0_bit (*(volatile union un_cks0 *)0xFFFA5).BIT
#define RESF (*(volatile uint8_t *)0xFFFA8)
#define LVIM (*(volatile union un_lvim *)0xFFFA9).lvim
#define LVIM_bit (*(volatile union un_lvim *)0xFFFA9).BIT
#define LVIS (*(volatile union un_lvis *)0xFFFAA).lvis
#define LVIS_bit (*(volatile union un_lvis *)0xFFFAA).BIT
#define WDTE (*(volatile uint8_t *)0xFFFAB)
#define CRCIN (*(volatile uint8_t *)0xFFFAC)
#define DSA0 (*(volatile uint8_t *)0xFFFB0)
#define DSA1 (*(volatile uint8_t *)0xFFFB1)
#define DRA0 (*(volatile uint16_t *)0xFFFB2)
#define DRA0L (*(volatile uint8_t *)0xFFFB2)
#define DRA0H (*(volatile uint8_t *)0xFFFB3)
#define DRA1 (*(volatile uint16_t *)0xFFFB4)
#define DRA1L (*(volatile uint8_t *)0xFFFB4)
#define DRA1H (*(volatile uint8_t *)0xFFFB5)
#define DBC0 (*(volatile uint16_t *)0xFFFB6)
#define DBC0L (*(volatile uint8_t *)0xFFFB6)
#define DBC0H (*(volatile uint8_t *)0xFFFB7)
#define DBC1 (*(volatile uint16_t *)0xFFFB8)
#define DBC1L (*(volatile uint8_t *)0xFFFB8)
#define DBC1H (*(volatile uint8_t *)0xFFFB9)
#define DMC0 (*(volatile union un_dmc0 *)0xFFFBA).dmc0
#define DMC0_bit (*(volatile union un_dmc0 *)0xFFFBA).BIT
#define DMC1 (*(volatile union un_dmc1 *)0xFFFBB).dmc1
#define DMC1_bit (*(volatile union un_dmc1 *)0xFFFBB).BIT
#define DRC0 (*(volatile union un_drc0 *)0xFFFBC).drc0
#define DRC0_bit (*(volatile union un_drc0 *)0xFFFBC).BIT
#define DRC1 (*(volatile union un_drc1 *)0xFFFBD).drc1
#define DRC1_bit (*(volatile union un_drc1 *)0xFFFBD).BIT
#define IF0 (*(volatile union un_if0 *)0xFFFE0).if0
#define IF0_bit (*(volatile union un_if0 *)0xFFFE0).BIT
#define IF0L (*(volatile union un_if0l *)0xFFFE0).if0l
#define IF0L_bit (*(volatile union un_if0l *)0xFFFE0).BIT
#define IF0H (*(volatile union un_if0h *)0xFFFE1).if0h
#define IF0H_bit (*(volatile union un_if0h *)0xFFFE1).BIT
#define IF1 (*(volatile union un_if1 *)0xFFFE2).if1
#define IF1_bit (*(volatile union un_if1 *)0xFFFE2).BIT
#define IF1L (*(volatile union un_if1l *)0xFFFE2).if1l
#define IF1L_bit (*(volatile union un_if1l *)0xFFFE2).BIT
#define MK0 (*(volatile union un_mk0 *)0xFFFE4).mk0
#define MK0_bit (*(volatile union un_mk0 *)0xFFFE4).BIT
#define MK0L (*(volatile union un_mk0l *)0xFFFE4).mk0l
#define MK0L_bit (*(volatile union un_mk0l *)0xFFFE4).BIT
#define MK0H (*(volatile union un_mk0h *)0xFFFE5).mk0h
#define MK0H_bit (*(volatile union un_mk0h *)0xFFFE5).BIT
#define MK1 (*(volatile union un_mk1 *)0xFFFE6).mk1
#define MK1_bit (*(volatile union un_mk1 *)0xFFFE6).BIT
#define MK1L (*(volatile union un_mk1l *)0xFFFE6).mk1l
#define MK1L_bit (*(volatile union un_mk1l *)0xFFFE6).BIT
#define PR00 (*(volatile union un_pr00 *)0xFFFE8).pr00
#define PR00_bit (*(volatile union un_pr00 *)0xFFFE8).BIT
#define PR00L (*(volatile union un_pr00l *)0xFFFE8).pr00l
#define PR00L_bit (*(volatile union un_pr00l *)0xFFFE8).BIT
#define PR00H (*(volatile union un_pr00h *)0xFFFE9).pr00h
#define PR00H_bit (*(volatile union un_pr00h *)0xFFFE9).BIT
#define PR01 (*(volatile union un_pr01 *)0xFFFEA).pr01
#define PR01_bit (*(volatile union un_pr01 *)0xFFFEA).BIT
#define PR01L (*(volatile union un_pr01l *)0xFFFEA).pr01l
#define PR01L_bit (*(volatile union un_pr01l *)0xFFFEA).BIT
#define PR10 (*(volatile union un_pr10 *)0xFFFEC).pr10
#define PR10_bit (*(volatile union un_pr10 *)0xFFFEC).BIT
#define PR10L (*(volatile union un_pr10l *)0xFFFEC).pr10l
#define PR10L_bit (*(volatile union un_pr10l *)0xFFFEC).BIT
#define PR10H (*(volatile union un_pr10h *)0xFFFED).pr10h
#define PR10H_bit (*(volatile union un_pr10h *)0xFFFED).BIT
#define PR11 (*(volatile union un_pr11 *)0xFFFEE).pr11
#define PR11_bit (*(volatile union un_pr11 *)0xFFFEE).BIT
#define PR11L (*(volatile union un_pr11l *)0xFFFEE).pr11l
#define PR11L_bit (*(volatile union un_pr11l *)0xFFFEE).BIT
#define MDAL (*(volatile uint16_t *)0xFFFF0)
#define MULA (*(volatile uint16_t *)0xFFFF0)
#define MDAH (*(volatile uint16_t *)0xFFFF2)
#define MULB (*(volatile uint16_t *)0xFFFF2)
#define MDBH (*(volatile uint16_t *)0xFFFF4)
#define MULOH (*(volatile uint16_t *)0xFFFF4)
#define MDBL (*(volatile uint16_t *)0xFFFF6)
#define MULOL (*(volatile uint16_t *)0xFFFF6)
#define PMC (*(volatile union un_pmc *)0xFFFFE).pmc
#define PMC_bit (*(volatile union un_pmc *)0xFFFFE).BIT

/*
 * Special Function Registers bits
 */
#define ADTYP ADM2_bit.no0
#define AWC ADM2_bit.no2
#define ADRCK ADM2_bit.no3
#define DFLEN DFLCTL_bit.no0
#define DIVST MDUC_bit.no0
#define MACSF MDUC_bit.no1
#define MACOF MDUC_bit.no2
#define MDSM MDUC_bit.no3
#define MACMODE MDUC_bit.no6
#define DIVMODE MDUC_bit.no7
#define TAU0EN PER0_bit.no0
#define SAU0EN PER0_bit.no2
#define IICA0EN PER0_bit.no4
#define ADCEN PER0_bit.no5
#define TMKAEN PER0_bit.no7
#define WDVOL RMC_bit.no7
#define RPEF RPECTL_bit.no0
#define RPERDIS RPECTL_bit.no7
#define SPT0 IICCTL00_bit.no0
#define STT0 IICCTL00_bit.no1
#define ACKE0 IICCTL00_bit.no2
#define WTIM0 IICCTL00_bit.no3
#define SPIE0 IICCTL00_bit.no4
#define WREL0 IICCTL00_bit.no5
#define LREL0 IICCTL00_bit.no6
#define IICE0 IICCTL00_bit.no7
#define PRS0 IICCTL01_bit.no0
#define DFC0 IICCTL01_bit.no2
#define SMC0 IICCTL01_bit.no3
#define DAD0 IICCTL01_bit.no4
#define CLD0 IICCTL01_bit.no5
#define WUP0 IICCTL01_bit.no7
#define ADCE ADM0_bit.no0
#define ADCS ADM0_bit.no7
#define SPD0 IICS0_bit.no0
#define STD0 IICS0_bit.no1
#define ACKD0 IICS0_bit.no2
#define TRC0 IICS0_bit.no3
#define COI0 IICS0_bit.no4
#define EXC0 IICS0_bit.no5
#define ALD0 IICS0_bit.no6
#define MSTS0 IICS0_bit.no7
#define IICRSV0 IICF0_bit.no0
#define STCEN0 IICF0_bit.no1
#define IICBSY0 IICF0_bit.no6
#define STCF0 IICF0_bit.no7
#define HIOSTOP CSC_bit.no0
#define MSTOP CSC_bit.no7
#define MCM0 CKC_bit.no4
#define MCS CKC_bit.no5
#define PCLOE0 CKS0_bit.no7
#define LVIF LVIM_bit.no0
#define LVIOMSK LVIM_bit.no1
#define LVISEN LVIM_bit.no7
#define LVILV LVIS_bit.no0
#define LVIMD LVIS_bit.no7
#define DWAIT0 DMC0_bit.no4
#define DS0 DMC0_bit.no5
#define DRS0 DMC0_bit.no6
#define STG0 DMC0_bit.no7
#define DWAIT1 DMC1_bit.no4
#define DS1 DMC1_bit.no5
#define DRS1 DMC1_bit.no6
#define STG1 DMC1_bit.no7
#define DST0 DRC0_bit.no0
#define DEN0 DRC0_bit.no7
#define DST1 DRC1_bit.no0
#define DEN1 DRC1_bit.no7
#define WDTIIF IF0L_bit.no0
#define LVIIF IF0L_bit.no1
#define PIF0 IF0L_bit.no2
#define PIF1 IF0L_bit.no3
#define PIF2 IF0L_bit.no4
#define PIF3 IF0L_bit.no5
#define DMAIF0 IF0L_bit.no6
#define DMAIF1 IF0L_bit.no7
#define CSIIF00 IF0H_bit.no0
#define IICIF00 IF0H_bit.no0
#define STIF0 IF0H_bit.no0
#define CSIIF01 IF0H_bit.no1
#define IICIF01 IF0H_bit.no1
#define SRIF0 IF0H_bit.no1
#define SREIF0 IF0H_bit.no2
#define TMIF01H IF0H_bit.no3
#define TMIF03H IF0H_bit.no4
#define IICAIF0 IF0H_bit.no5
#define TMIF00 IF0H_bit.no6
#define TMIF01 IF0H_bit.no7
#define TMIF02 IF1L_bit.no0
#define TMIF03 IF1L_bit.no1
#define ADIF IF1L_bit.no2
#define TMKAIF IF1L_bit.no3
#define KRIF IF1L_bit.no4
#define MDIF IF1L_bit.no5
#define FLIF IF1L_bit.no6
#define WDTIMK MK0L_bit.no0
#define LVIMK MK0L_bit.no1
#define PMK0 MK0L_bit.no2
#define PMK1 MK0L_bit.no3
#define PMK2 MK0L_bit.no4
#define PMK3 MK0L_bit.no5
#define DMAMK0 MK0L_bit.no6
#define DMAMK1 MK0L_bit.no7
#define CSIMK00 MK0H_bit.no0
#define IICMK00 MK0H_bit.no0
#define STMK0 MK0H_bit.no0
#define CSIMK01 MK0H_bit.no1
#define IICMK01 MK0H_bit.no1
#define SRMK0 MK0H_bit.no1
#define SREMK0 MK0H_bit.no2
#define TMMK01H MK0H_bit.no3
#define TMMK03H MK0H_bit.no4
#define IICAMK0 MK0H_bit.no5
#define TMMK00 MK0H_bit.no6
#define TMMK01 MK0H_bit.no7
#define TMMK02 MK1L_bit.no0
#define TMMK03 MK1L_bit.no1
#define ADMK MK1L_bit.no2
#define TMKAMK MK1L_bit.no3
#define KRMK MK1L_bit.no4
#define MDMK MK1L_bit.no5
#define FLMK MK1L_bit.no6
#define WDTIPR0 PR00L_bit.no0
#define LVIPR0 PR00L_bit.no1
#define PPR00 PR00L_bit.no2
#define PPR01 PR00L_bit.no3
#define PPR02 PR00L_bit.no4
#define PPR03 PR00L_bit.no5
#define DMAPR00 PR00L_bit.no6
#define DMAPR01 PR00L_bit.no7
#define CSIPR000 PR00H_bit.no0
#define IICPR000 PR00H_bit.no0
#define STPR00 PR00H_bit.no0
#define CSIPR001 PR00H_bit.no1
#define IICPR001 PR00H_bit.no1
#define SRPR00 PR00H_bit.no1
#define SREPR00 PR00H_bit.no2
#define TMPR001H PR00H_bit.no3
#define TMPR003H PR00H_bit.no4
#define IICAPR00 PR00H_bit.no5
#define TMPR000 PR00H_bit.no6
#define TMPR001 PR00H_bit.no7
#define TMPR002 PR01L_bit.no0
#define TMPR003 PR01L_bit.no1
#define ADPR0 PR01L_bit.no2
#define TMKAPR0 PR01L_bit.no3
#define KRPR0 PR01L_bit.no4
#define MDPR0 PR01L_bit.no5
#define FLPR0 PR01L_bit.no6
#define WDTIPR1 PR10L_bit.no0
#define LVIPR1 PR10L_bit.no1
#define PPR10 PR10L_bit.no2
#define PPR11 PR10L_bit.no3
#define PPR12 PR10L_bit.no4
#define PPR13 PR10L_bit.no5
#define DMAPR10 PR10L_bit.no6
#define DMAPR11 PR10L_bit.no7
#define CSIPR100 PR10H_bit.no0
#define IICPR100 PR10H_bit.no0
#define STPR10 PR10H_bit.no0
#define CSIPR101 PR10H_bit.no1
#define IICPR101 PR10H_bit.no1
#define SRPR10 PR10H_bit.no1
#define SREPR10 PR10H_bit.no2
#define TMPR101H PR10H_bit.no3
#define TMPR103H PR10H_bit.no4
#define IICAPR10 PR10H_bit.no5
#define TMPR100 PR10H_bit.no6
#define TMPR101 PR10H_bit.no7
#define TMPR102 PR11L_bit.no0
#define TMPR103 PR11L_bit.no1
#define ADPR1 PR11L_bit.no2
#define TMKAPR1 PR11L_bit.no3
#define KRPR1 PR11L_bit.no4
#define MDPR1 PR11L_bit.no5
#define FLPR1 PR11L_bit.no6
#define MAA PMC_bit.no0

/*
 * Interrupt vector addresses
 */
#define RST_vect 0x0
#define INTDBG_vect 0x2
#define INTWDTI_vect 0x4
#define INTLVI_vect 0x6
#define INTP0_vect 0x8
#define INTP1_vect 0xA
#define INTP2_vect 0xC
#define INTP3_vect 0xE
#define INTDMA0_vect 0x10
#define INTDMA1_vect 0x12
#define INTCSI00_vect 0x14
#define INTIIC00_vect 0x14
#define INTST0_vect 0x14
#define INTCSI01_vect 0x16
#define INTIIC01_vect 0x16
#define INTSR0_vect 0x16
#define INTSRE0_vect 0x18
#define INTTM01H_vect 0x1A
#define INTTM03H_vect 0x1C
#define INTIICA0_vect 0x1E
#define INTTM00_vect 0x20
#define INTTM01_vect 0x22
#define INTTM02_vect 0x24
#define INTTM03_vect 0x26
#define INTAD_vect 0x28
#define INTIT_vect 0x2A
#define INTKR_vect 0x2C
#define INTMD_vect 0x2E
#define INTFL_vect 0x30
#define BRK_I_vect 0x7E

#endif

