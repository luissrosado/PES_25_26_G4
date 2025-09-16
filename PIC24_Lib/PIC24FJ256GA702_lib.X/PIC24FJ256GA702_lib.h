/*
 * File:   PIC24FJ256GA702_lib.h
 * Author: Jo�o Duarte
 *         Gon�alo Antunes
 *         Gon�alo Batalha
 * 
 * Comments: Library for the PIC24FJ256GA702 micro-controller
 * Datasheet URL: https://www.microchip.com/content/dam/mchp/documents/MCU16/ProductDocuments/DataSheets/PIC24FJ256GA705-Family-Data-Sheet-DS30010118E.pdf
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef PIC24FJ256GA702_LIB_H
#define	PIC24FJ256GA702_LIB_H

#include <xc.h> // include processor files - each processor file is guarded. 
#include "GPIO.h"
#include "common_lib.h"
#include "peripherals_interrupts.h"

// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations

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

/**
    <p><b>Function prototype:</b></p>
 * void pinMode(struct pin_t pin, __bit mode)

    <p><b>Description:</b></p>
 * Initiates the pin in INPUT/OUTPUT mode as ANALOG/DIGITAL
 * Note that some pins cannot be ANALOG, check page 127 of the datasheet

    <p><b>Parameters:</b></p>
 * pin - the pin you want to change
 * mode - INPUT/OUTPUT mode

 */

// live documentation

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* PIC24FJ256GA702_LIB_H */

