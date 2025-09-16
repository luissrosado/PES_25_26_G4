/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef GPIO_H
#define	GPIO_H

#include <xc.h> // include processor files - each processor file is guarded.
#include "common_lib.h"

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
// live documentation

#define OUTPUT  0
#define INPUT   1
#define DIGITAL 0
#define ANALOG  1

#define A_PIN 0
#define B_PIN 1
struct pin_t{
    uint8_t a_b;
    uint8_t pinNum;
    uint8_t pinType;
};
// Digital pins
#define RA0  ((struct pin_t){A_PIN, 0, DIGITAL})
#define RA1  ((struct pin_t){A_PIN, 1, DIGITAL})
#define RA2  ((struct pin_t){A_PIN, 2, DIGITAL})
#define RA3  ((struct pin_t){A_PIN, 3, DIGITAL})
#define RA4  ((struct pin_t){A_PIN, 4, DIGITAL})
#define RB0  ((struct pin_t){B_PIN, 0, DIGITAL})
#define RB1  ((struct pin_t){B_PIN, 1, DIGITAL})
#define RB2  ((struct pin_t){B_PIN, 2, DIGITAL})
#define RB3  ((struct pin_t){B_PIN, 3, DIGITAL})
#define RB4  ((struct pin_t){B_PIN, 4, DIGITAL})
#define RB5  ((struct pin_t){B_PIN, 5, DIGITAL})
#define RB6  ((struct pin_t){B_PIN, 6, DIGITAL})
#define RB7  ((struct pin_t){B_PIN, 7, DIGITAL})
#define RB8  ((struct pin_t){B_PIN, 8, DIGITAL})
#define RB9  ((struct pin_t){B_PIN, 9, DIGITAL})
#define RB10 ((struct pin_t){B_PIN, 10, DIGITAL})
#define RB11 ((struct pin_t){B_PIN, 11, DIGITAL})
#define RB12 ((struct pin_t){B_PIN, 12, DIGITAL})
#define RB13 ((struct pin_t){B_PIN, 13, DIGITAL})
#define RB14 ((struct pin_t){B_PIN, 14, DIGITAL})
#define RB15 ((struct pin_t){B_PIN, 15, DIGITAL})

#define AN0  ((struct pin_t){A_PIN, 0, ANALOG})
#define AN1  ((struct pin_t){A_PIN, 1, ANALOG})
#define AN2  ((struct pin_t){B_PIN, 0, ANALOG})
#define AN3  ((struct pin_t){B_PIN, 1, ANALOG})
#define AN4  ((struct pin_t){B_PIN, 2, ANALOG})
#define AN5  ((struct pin_t){B_PIN, 3, ANALOG})
#define AN6  ((struct pin_t){B_PIN, 14, ANALOG})
#define AN7  ((struct pin_t){B_PIN, 13, ANALOG})
#define AN8  ((struct pin_t){B_PIN, 12, ANALOG})
#define AN9  ((struct pin_t){B_PIN, 15, ANALOG})
#define AN1_ AN3 // Equivalent to AN1-
void pinMode(struct pin_t pin, uint8_t mode);

/**
    <p><b>Function prototype:</b></p>
 * void digitalWrite(struct pin_t pin, uint8_t toWrite)

    <p><b>Description:</b></p>
 * Writes the digital value toWrite to pin

    <p><b>Parameters:</b></p>
 * pin - the pin you want to write to
 * toWrite - HIGH/LOW

 */
#define HIGH 1
#define LOW 0
void digitalWrite(struct pin_t pin, uint8_t toWrite);

/**
    <p><b>Function prototype:</b></p>
 * void toggleDigitalPin(struct pin_t pin)

    <p><b>Description:</b></p>
 * Toggles the value present on the digital pin

    <p><b>Parameters:</b></p>
 * pin - the pin you want to toggle

 */
void toggleDigitalPin(struct pin_t pin);

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* GPIO_H */

