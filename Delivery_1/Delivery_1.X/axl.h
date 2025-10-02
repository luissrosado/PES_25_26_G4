/*
 * File:   axl.h
 * Author: João Duarte
 *         Gonçalo Antunes
 *         Gonçalo Batalha
 *
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef AXL_H
#define	AXL_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include "../../PIC24_Lib/PIC24FJ256GA702_lib.X/PIC24FJ256GA702_lib.h"

// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations
typedef struct LIS{
  int16_t accelX;
  int16_t accelY;
  int16_t accelZ;
} LIS;

extern volatile LIS axl;

#define SPI2_MISO_RPIN  2       // RP2  -> MDI2 (Master In, Slave Out)
#define SPI2_MOSI_RPIN  6       // RP6  -> MDO2 (Master Out, Slave In)    // SETUP IN SPI SETUP FUNCTION
#define SPI2_SCLK_RPIN  7       // RP7  -> SCLK2                          // SETUP IN SPI SETUP FUNCTION
#define SPI2_CS_RPIN    3       // RP3  -> CS2 (Slave Select)             // SETUP IN SPI SETUP FUNCTION
#define FULL_CS_PIN     RB3


#define READ 0x8000;  // MSb 1, its 16 bits because the transfer is 16 bits
#define WRITE 0x0000; // MSb 0, its 16 bits because the transfer is 16 bits

#define CTRL_REG0 0x1E
#define CTRL_REG1 0x20
#define CTRL_REG2 0x21
#define CTRL_REG3 0x22
#define CTRL_REG4 0x23
#define CTRL_REG5 0x24
#define CTRL_REG6 0x25

// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation

uint16_t SPI2_Pool_Transfer(uint16_t dataOut);
void LISconfig(void);
void readAXL(LIS *accel);

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

