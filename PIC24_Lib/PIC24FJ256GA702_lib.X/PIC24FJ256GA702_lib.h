/*
 * File:   PIC24FJ256GA702_lib.h
 * Author: João Duarte
 *         Gonçalo Antunes
 *         Gonçalo Batalha
 * 
 * Comments: Library for the PIC24FJ256GA702 micro-controller
 * Datasheet URL: https://www.microchip.com/content/dam/mchp/documents/MCU16/ProductDocuments/DataSheets/PIC24FJ256GA705-Family-Data-Sheet-DS30010118E.pdf
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef PIC24FJ256GA702_LIB_H
#define	PIC24FJ256GA702_LIB_H

#include <xc.h> // include processor files - each processor file is guarded.
#include <libpic30.h>

#include "GPIO.h"
#include "common_lib.h"
#include "peripherals_interrupts.h"


#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* PIC24FJ256GA702_LIB_H */

