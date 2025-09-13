/*
 * File:   common.h
 * Author: João Duarte
 *         Gonçalo Antunes
 *         Gonçalo Batalha
 * 
 * Comments: Alter the setup and loop functions in order to run the program, similar to Arduino
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef COMMON_H
#define	COMMON_H

#include <xc.h> // include processor files - each processor file is guarded.

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
 * void setup(void)

    <p><b>Description:</b></p>
 * Insert here what the microcontroller is supposed to do when powering up
 */
void setup(void);

/**
    <p><b>Function prototype:</b></p>
 * void loop(void)

    <p><b>Description:</b></p>
 * Insert here what the microcontroller is supposed to constantly do
 */
void loop(void);


// live documentation

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* COMMON_H */

