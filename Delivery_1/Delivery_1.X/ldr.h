/*
 * File:   ldr.h
 * Author: João Duarte
 *         Gonçalo Antunes
 *         Gonçalo Batalha
 *
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef LDR_H
#define	LDR_H

#include <xc.h> // include processor files - each processor file is guarded. 

// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate
#define LDR_THRESHOLD 2048 // Halfway point of a 12-bit number

// TODO Insert declarations

// LDR Registers
typedef struct {
    uint16_t value;     
    uint16_t threshold; 
    uint16_t count;   
} LDR_Registers_t;

extern volatile LDR_Registers_t LDR;

// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation
/**
    <p><b>Function prototype:</b></p>
 * void ADC_check(LDR_Registers_t* ldr)

    <p><b>Description:</b></p>
 * Compares the value with the threshold of the LDR

    <p><b>Parameters:</b></p>
 * ldr - LDR type containing the value, threshold and its respective count

 */
void ADC_check(LDR_Registers_t* ldr);


#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* LDR_H */

