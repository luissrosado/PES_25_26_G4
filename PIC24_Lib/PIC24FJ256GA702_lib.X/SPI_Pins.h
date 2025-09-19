// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef SPI_PINS_H
#define	SPI_PINS_H

#include <xc.h> // include processor files - each processor file is guarded.  

// ===== SPI1 Pin Mapping =====
#define SPI1_MISO_RPIN   15   // RP11 -> SDI1 (Master Out, Slave In)
#define SPI1_MOSI_RPIN   14   // RP10 -> SDO1 (Master In, Slave Out)
#define SPI1_SCK_RPIN    13   // RP9  -> SCK1
#define SPI1_SS_RPIN     12   // RP8  -> SS1 (Slave Select)

// ===== SPI Constants =====
#define CMD_FROM_MASTER  0x55
#define RESPONSE_TO_SEND 0xAA

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* SPI_PINS_H */

