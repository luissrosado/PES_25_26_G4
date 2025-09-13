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
 * void pinMode(struct pin_t pin, __bit mode)

    <p><b>Description:</b></p>
 * Initiates the pin in INPUT/OUTPUT mode as ANALOG/DIGITAL
 * Note that some pins cannot be ANALOG, check page 127 of the datasheet

    <p><b>Parameters:</b></p>
 * pin - the pin you want to change
 * mode - INPUT/OUTPUT mode

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

/**
    <p><b>Function prototype:</b></p>
 * void setupInterrupt(struct interrupt_t interrupt, uint8_t priority)

    <p><b>Description:</b></p>
 * Sets up the interrupt with priority
 * Macros were made with some of the interrupts

    <p><b>Parameters:</b></p>
 * interrupt - the interrupt you want to enable
 *              the interrupt vector is located in page 87 of the datasheet, TABLE 8-2
 * priority - the priority of the interrupt over the others

 */
#define IFS0_addr 0x88
#define IFS1_addr 0x8A
#define IFS2_addr 0x8C
#define IFS3_addr 0x8E
#define IFS4_addr 0x90
#define IFS5_addr 0x92
#define IFS6_addr 0x94
#define IFS7_addr 0x96
#define IEC0_addr 0098
#define IEC1_addr 009A
#define IEC2_addr 009C
#define IEC3_addr 009E
#define IEC4_addr 00A0
#define IEC5_addr 00A2
#define IEC6_addr 00A4
#define IEC7_addr 00A6
#define IPC0_addr 00A8
#define IPC1_addr 00AA
#define IPC2_addr 00AC
#define IPC3_addr 00AE
#define IPC4_addr 00B0
#define IPC5_addr 00B2
#define IPC6_addr 00B4
#define IPC7_addr 00B6
#define IPC8_addr 00B8
#define IPC9_addr 00BA
#define IPC10_addr 00BC
#define IPC11_addr 00BE
#define IPC12_addr 00C0
#define IPC13_addr 00C2
#define IPC14_addr 00C4
#define IPC15_addr 00C6
#define IPC16_addr 00C8
#define IPC17_addr 00CA
#define IPC18_addr 00CC
#define IPC19_addr 00CE
#define IPC20_addr 00D0
#define IPC21_addr 00D2
#define IPC22_addr 00D4
#define IPC23_addr 00D6
#define IPC24_addr 00D8
#define IPC25_addr 00DA
#define IPC26_addr 00DC
#define IPC27_addr 00DE
#define IPC28_addr 00E0
#define IPC29_addr 00E2

struct interrupt_t{
    uint8_t ifs_iec_id;
    uint8_t ifs_iec_bit;
    uint8_t ipc_id;
    uint8_t ipc_bit;
};
#define EXT0_INTERRUPT      ((struct interrupt_t){0, 0, 0, 2})
#define EXT0_ISR            __attribute__((__interrupt__, auto_psv)) _INT0Interrupt
#define T1_INTERRUPT        ((struct interrupt_t){0, 3, 0, 14})
#define T1_ISR              __attribute__((__interrupt__, auto_psv)) _T1Interrupt
#define DMA0_INTERRUPT      ((struct interrupt_t){0, 4, 1, 2})
#define DMA0_ISR            __attribute__((__interrupt__, auto_psv)) _DMA0Interrupt
#define T2_INTERRUPT        ((struct interrupt_t){0, 7, 1, 14})
#define T2_ISR              __attribute__((__interrupt__, auto_psv)) _T2Interrupt
#define T3_INTERRUPT        ((struct interrupt_t){0, 8, 2, 2})
#define T3_ISR              __attribute__((__interrupt__, auto_psv)) _T3Interrupt
#define SPI1_GEN_INTERRUPT  ((struct interrupt_t){0, 9, 2, 6})
#define SPI1_GEN_ISR        __attribute__((__interrupt__, auto_psv)) _SPI1Interrupt
#define SPI1_DONE_INTERRUPT ((struct interrupt_t){0, 10, 2, 10})
#define SPI1_DONE_ISR       __attribute__((__interrupt__, auto_psv)) _SPI1TXInterrupt
#define U1_RX_INTERRUPT     ((struct interrupt_t){0, 11, 2, 14})
#define U1_RX_ISR           __attribute__((__interrupt__, auto_psv)) _U1RXInterrupt
#define U1_TX_INTERRUPT     ((struct interrupt_t){0, 12, 3, 2})
#define U1_TX_ISR           __attribute__((__interrupt__, auto_psv)) _U1TXInterrupt
#define ADC1_INTERRUPT      ((struct interrupt_t){0, 13, 3, 6})
#define ADC1_TX_ISR         __attribute__((__interrupt__, auto_psv)) _ADC1Interrupt
#define DMA1_INTERRUPT      ((struct interrupt_t){0, 14, 3, 10})
#define DMA1_ISR            __attribute__((__interrupt__, auto_psv)) _DMA1Interrupt
#define I2C1_S_INTERRUPT    ((struct interrupt_t){1, 0, 4, 2})
#define I2C1_S_ISR          __attribute__((__interrupt__, auto_psv)) _SI2C1Interrupt
#define I2C1_M_INTERRUPT    ((struct interrupt_t){1, 1, 4, 6})
#define I2C1_M_ISR          __attribute__((__interrupt__, auto_psv)) _MI2C1Interrupt
// PUT MORE HERE IF NEEDED
void setupInterrupt(struct interrupt_t interrupt, uint8_t priority);
#define ENABLE_INTERRUPTS   INTCON2bits.GIE = 1;                // Enable the Global Interrupt Flag  
#define DISABLE_INTERRUPTS  INTCON2bits.GIE = 0;                // Disable the Global Interrupt Flag  
#define TOGGLE_INTERRUPTS   INTCON2bits.GIE = !INTCON2bits.GIE; // Toggle the Global Interrupt Flags

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
 * osctun  -  fine-tune the FRC Oscillator over a range of approximately ?1.5%
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

