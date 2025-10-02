// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef SPI_PINS_H
#define	SPI_PINS_H

#include <xc.h> // include processor files - each processor file is guarded.  

// ===== SPI1 Pin Mapping =====
#define SPI1_MOSI_RPIN   15   // [RED]    RP15 -> SDI1 (Master Out, Slave In)
#define SPI1_MISO_RPIN   14   // [ORANGE] RP14 -> SDO1 (Master In, Slave Out) SETUP IN SPI SETUP FUNCTION
#define SPI1_SCLK_RPIN   13   // [YELLOW] RP13 -> SCLK1
#define SPI1_CS_RPIN     12   // [GREEN]  RP12 -> CS1 (Slave Select)

// ===== SPI Constants =====
#define CMD_FROM_MASTER  0xAAAA
#define RESPONSE_TO_SEND 0x0F23

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* SPI_PINS_H */

