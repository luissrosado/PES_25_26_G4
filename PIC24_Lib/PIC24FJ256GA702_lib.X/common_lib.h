/*
 * File:   common_lib.h
 * Author: João Duarte
 *         Gonçalo Antunes
 *         Gonçalo Batalha
 *
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef COMMON_LIB_H
#define	COMMON_LIB_H

#include <xc.h> // include processor files - each processor file is guarded. 
#include <stdint.h> 

// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations

// Sets the bit in position bitToChange in a reg to bitVal
#define SET_BIT_ON_REG(reg, bitToChange, bitVal) \
    ( reg = ((reg) & ~(1 << (bitToChange))) | ((bitVal & 1) << (bitToChange)) )

#define READ_BIT_ON_REG(reg, bitToRead) \
    (((reg) >> (bitToRead)) & 1)

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

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* COMMON_LIB_H */

