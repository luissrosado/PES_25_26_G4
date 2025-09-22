// config.h - PIC24FJ1024GB610 Configuration Bit Settings
#ifndef CONFIG_H
#define CONFIG_H

#include <xc.h>
#include <stdint.h>

// ================================
// Clock definitions
// ================================
#define FOSC 8000000UL       // Oscillator frequency (8 MHz)
#define FCY  (FOSC/2)       // Instruction cycle frequency (FOSC/2 for PIC24)

// Include libpic30 after defining FCY for __delay_ms/__delay_us
#include <libpic30.h>
#include "p24FJ1024GB610.h"

// ================================
// Configuration Bits
// ================================

// FSEC
#pragma config BWRP = OFF
#pragma config BSS = DISABLED
#pragma config BSEN = OFF
#pragma config GWRP = OFF
#pragma config GSS = DISABLED
#pragma config CWRP = OFF
#pragma config CSS = DISABLED
#pragma config AIVTDIS = OFF

// FBSLIM
#pragma config BSLIM = 0x1FFF

// FOSCSEL
#pragma config FNOSC = FRC
#pragma config PLLMODE = DISABLED
#pragma config IESO = ON

// FOSC
#pragma config POSCMD = NONE
#pragma config OSCIOFCN = OFF
#pragma config SOSCSEL = ON
#pragma config PLLSS = PLL_PRI
#pragma config IOL1WAY = ON
#pragma config FCKSM = CSDCMD

// FWDT
#pragma config WDTPS = PS32768
#pragma config FWPSA = PR128
#pragma config FWDTEN = ON
#pragma config WINDIS = OFF
#pragma config WDTWIN = WIN25
#pragma config WDTCMX = WDTCLK
#pragma config WDTCLK = LPRC

// FPOR
#pragma config BOREN = ON
#pragma config LPCFG = OFF
#pragma config DNVPEN = ENABLE

// FICD
#pragma config ICS = PGD1
#pragma config JTAGEN = OFF
#pragma config BTSWP = OFF

// FDEVOPT1
#pragma config ALTCMPI = DISABLE
#pragma config TMPRPIN = OFF
#pragma config SOSCHP = ON
#pragma config ALTVREF = ALTREFEN

#endif // CONFIG_H
