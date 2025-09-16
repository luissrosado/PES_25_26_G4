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
#ifndef PERIPHERALS_INTERRUPTS_H
#define	PERIPHERALS_INTERRUPTS_H

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

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* PERIPHERALS_INTERRUPTS_H */

