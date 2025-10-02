/*
 * File:   SPI.h
 * Author: João Duarte
 *         Gonçalo Antunes
 *         Gonçalo Batalha
 *
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef SPI_H
#define	SPI_H

#include <xc.h> // include processor files - each processor file is guarded.  

// ===== SPI1 Pin Mapping =====
#define SPI1_MOSI_RPIN   15   // [RED]    RP15 -> SDI1 (Master Out, Slave In)
#define SPI1_MISO_RPIN   14   // [ORANGE] RP14 -> SDO1 (Master In, Slave Out) SETUP IN SPI SETUP FUNCTION
#define SPI1_SCLK_RPIN   13   // [YELLOW] RP13 -> SCLK1
#define SPI1_CS_RPIN     12   // [GREEN]  RP12 -> CS1 (Slave Select)

// ===== SPI Command Constants =====
#define CMD_LDR_VAL         0xDDD1
#define CMD_LDR_CNT         0xDDD2

#define CMD_AXL_X           0xAAA1
#define CMD_AXL_Y           0xAAA2
#define CMD_AXL_Z           0xAAA4

#define CMD_ERROR           0x0000

#define STD_REPLY_TO_BOARD  0x4F4B // "OK" in ASCII
#define ERR_REPLY_TO_BOARD  0x4552 // "ER" in ASCII

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* SPI_H */
