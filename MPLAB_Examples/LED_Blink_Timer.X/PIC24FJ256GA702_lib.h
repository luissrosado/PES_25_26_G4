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

#include <stdint.h>
#include <xc.h> // include processor files - each processor file is guarded.  

// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations

// Sets the bit in position bitToChange in a reg to bitVal
#define SET_BIT_ON_REG(reg, bitToChange, bitVal) \
    ( reg = ((reg) & ~(1 << (bitToChange))) | ((bitVal) << (bitToChange)) )

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

/**
    <p><b>Function prototype:</b></p>
 * void pinMode(struct pin_t pin, __bit mode, __bit AnaOrDigi)

    <p><b>Description:</b></p>
 * Initiates the pin in INPUT/OUTPUT mode as ANALOG/DIGITAL
 * Note that some pins cannot be ANALOG, check page 127 of the datasheet

    <p><b>Parameters:</b></p>
 * pin - the pin you want to change
 * mode - INPUT/OUTPUT mode
 * AnaOrDigi - ANALOG/DIGITAL pin

 */
#define OUTPUT  0
#define INPUT   1
#define DIGITAL 0
#define ANALOG  1

#define A_PIN 0
#define B_PIN 1
struct pin_t{
    uint8_t a_b;
    uint8_t pinNum;
};
#define RA0  ((struct pin_t){A_PIN, 0})
#define RA1  ((struct pin_t){A_PIN, 1})
#define RA2  ((struct pin_t){A_PIN, 2})
#define RA3  ((struct pin_t){A_PIN, 3})
#define RA4  ((struct pin_t){A_PIN, 4})
#define RB0  ((struct pin_t){B_PIN, 0})
#define RB1  ((struct pin_t){B_PIN, 1})
#define RB2  ((struct pin_t){B_PIN, 2})
#define RB3  ((struct pin_t){B_PIN, 3})
#define RB4  ((struct pin_t){B_PIN, 4})
#define RB5  ((struct pin_t){B_PIN, 5})
#define RB6  ((struct pin_t){B_PIN, 6})
#define RB7  ((struct pin_t){B_PIN, 7})
#define RB8  ((struct pin_t){B_PIN, 8})
#define RB9  ((struct pin_t){B_PIN, 9})
#define RB10 ((struct pin_t){B_PIN, 10})
#define RB11 ((struct pin_t){B_PIN, 11})
#define RB12 ((struct pin_t){B_PIN, 12})
#define RB13 ((struct pin_t){B_PIN, 13})
#define RB14 ((struct pin_t){B_PIN, 14})
#define RB15 ((struct pin_t){B_PIN, 15})

void pinMode(struct pin_t pin, uint8_t mode, uint8_t AnaOrDigi);

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

/**
    <p><b>Function prototype:</b></p>
 * void setupTimer1(uint16_t t1con, uint16_t pr1)

    <p><b>Description:</b></p>
 * Sets up TIMER1 according to the values of t1con and pr1

    <p><b>Parameters:</b></p>
 * t1con - bit configuration is in page 160 of the datasheet
 * pr1   - value you want to flag TIMER1 with

 */
void setupTimer1(uint16_t t1con, uint16_t pr1);
// IFS0 is located in page 87 of the datasheet, TABLE 8-2
#define TIMER1_FLAG IFS0bits.T1IF

/**
    <p><b>Function prototype:</b></p>
 * void setupSOsc(
 *   uint16_t osccon,
 *   uint16_t osctun,
 *   uint16_t clkdiv,
 *   uint16_t oscdiv,
 *   uint16_t oscfdiv
 * )

    <p><b>Description:</b></p>
 * Sets up the System Oscillator according to the values of
 * osccon, osctun, clkdiv, oscdiv, oscfdiv

    <p><b>Parameters:</b></p>
 * osccon  - main control register for the oscillator, controlling clock source
 *           switching and allows the monitoring of clock sources;
 *           --bit configuration is in page 100 & 101 of the datasheet--
 * osctun  -  fine-tune the FRC Oscillator over a range of approximately ±1.5%
 *           --bit configuration is in page 102 of the datasheet--
 * clkdiv  - controls the features associated with Doze mode,
 *           as well as the postscalers for the OSCFDIV Clock mode and the PLL module
 *           --bit configuration is in page 103 of the datasheet--
 * oscdiv  - provide control for the system oscillator frequency divider
 *           --bit configuration is in page 104 of the datasheet--
 * oscfdiv - provide control for the system oscillator frequency divider
 *           --bit configuration is in page 105 of the datasheet--
 */
void setupSOsc(
    uint16_t osccon,
    uint16_t osctun,
    uint16_t clkdiv,
    uint16_t oscdiv,
    uint16_t oscfdiv
);

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

