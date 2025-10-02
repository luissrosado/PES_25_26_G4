/*
 * File:   peripherals_interrupts.h
 * Author: João Duarte
 *         Gonçalo Antunes
 *         Gonçalo Batalha
 *
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
 * void setupADC(
 *     uint16_t ad1con1,
 *     uint16_t ad1con2,
 *     uint16_t ad1con3,
 *     uint16_t ad1chs,
 *     uint16_t ad1cssl,
 *     uint16_t bit_mode
 * )

    <p><b>Description:</b></p>
 * Sets up the internal ADC, check the datasheet from pages 285 to 290 for more details on its setup
 * If you want to check the internal registers, check pages 291 to 302

    <p><b>Parameters:</b></p>
 * bit_mode sets the ADC up in 10-bit mode in case of '0' or 12-bit mode in case of '1'
 * For the rest of the internal register setup check pages 291 to 302 of the datasheet

 */
void setupADC(
    uint16_t ad1con1,
    uint16_t ad1con2,
    uint16_t ad1con3,
    uint16_t ad1chs,
    uint16_t ad1cssl,
    uint16_t bit_mode
);


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
    volatile uint16_t* ifs_addr;
    volatile uint16_t* iec_addr;
    uint8_t ifs_iec_bit;
    volatile uint16_t* ipc_addr;
    uint8_t ipc_bit;
};
#define EXT0_INTERRUPT      ((struct interrupt_t){&IFS0, &IEC0, 0, &IPC0, 2})
#define EXT0_ISR            __attribute__((__interrupt__, auto_psv)) _INT0Interrupt
#define T1_INTERRUPT        ((struct interrupt_t){&IFS0, &IEC0, 3, &IPC0, 14})
#define T1_ISR              __attribute__((__interrupt__, auto_psv)) _T1Interrupt
#define DMA0_INTERRUPT      ((struct interrupt_t){&IFS0, &IEC0, 4, &IPC1, 2})
#define DMA0_ISR            __attribute__((__interrupt__, auto_psv)) _DMA0Interrupt
#define T2_INTERRUPT        ((struct interrupt_t){&IFS0, &IEC0, 7, &IPC1, 14})
#define T2_ISR              __attribute__((__interrupt__, auto_psv)) _T2Interrupt
#define T3_INTERRUPT        ((struct interrupt_t){&IFS0, &IEC0, 8, &IPC2, 2})
#define T3_ISR              __attribute__((__interrupt__, auto_psv)) _T3Interrupt
#define SPI1_GEN_INTERRUPT  ((struct interrupt_t){&IFS0, &IEC0, 9, &IPC2, 6})
#define SPI1_GEN_ISR        __attribute__((__interrupt__, auto_psv)) _SPI1Interrupt
#define SPI1_TX_INTERRUPT   ((struct interrupt_t){&IFS0, &IEC0, 10, &IPC2, 10})
#define SPI1_TX_ISR         __attribute__((__interrupt__, auto_psv)) _SPI1TXInterrupt
#define U1_RX_INTERRUPT     ((struct interrupt_t){&IFS0, &IEC0, 11, &IPC2, 14})
#define U1_RX_ISR           __attribute__((__interrupt__, auto_psv)) _U1RXInterrupt
#define U1_TX_INTERRUPT     ((struct interrupt_t){&IFS0, &IEC0, 12, &IPC3, 2})
#define U1_TX_ISR           __attribute__((__interrupt__, auto_psv)) _U1TXInterrupt
#define ADC1_INTERRUPT      ((struct interrupt_t){&IFS0, &IEC0, 13, &IPC3, 6})
#define ADC1_ISR            __attribute__((__interrupt__, auto_psv)) _ADC1Interrupt
#define DMA1_INTERRUPT      ((struct interrupt_t){&IFS0, &IEC0, 14, &IPC3, 10})
#define DMA1_ISR            __attribute__((__interrupt__, auto_psv)) _DMA1Interrupt
#define I2C1_S_INTERRUPT    ((struct interrupt_t){&IFS1, &IEC1, 0, &IPC4, 2})
#define I2C1_S_ISR          __attribute__((__interrupt__, auto_psv)) _SI2C1Interrupt
#define I2C1_M_INTERRUPT    ((struct interrupt_t){&IFS1, &IEC1, 1, &IPC4, 6})
#define I2C1_M_ISR          __attribute__((__interrupt__, auto_psv)) _MI2C1Interrupt
// -- More exist here in the middle but were not needed -- //
#define SPI2_GEN_INTERRUPT  ((struct interrupt_t){&IFS2, &IEC2, 0, &IPC8, 2})
#define SPI2_GEN_ISR        __attribute__((__interrupt__, auto_psv)) _SPI2Interrupt
#define SPI2_TX_INTERRUPT   ((struct interrupt_t){&IFS2, &IEC2, 1, &IPC8, 6})
#define SPI2_TX_ISR         __attribute__((__interrupt__, auto_psv)) _SPI2TXInterrupt
// -- More exist here in the middle but were not needed -- //
#define SPI1_RX_INTERRUPT   ((struct interrupt_t){&IFS3, &IEC3, 10, &IPC14, 10})
#define SPI1_RX_ISR         __attribute__((__interrupt__, auto_psv)) _SPI1RXInterrupt
#define SPI2_RX_INTERRUPT   ((struct interrupt_t){&IFS3, &IEC3, 11, &IPC14, 14})
#define SPI2_RX_ISR         __attribute__((__interrupt__, auto_psv)) _SPI2RXInterrupt
#define SPI3_RX_INTERRUPT   ((struct interrupt_t){&IFS3, &IEC3, 12, &IPC15, 2})
#define SPI3_RX_ISR         __attribute__((__interrupt__, auto_psv)) _SPI3RXInterrupt
// PUT MORE HERE IF NEEDED
void setupInterrupt(struct interrupt_t interrupt, uint8_t priority);
#define ENABLE_INTERRUPTS   INTCON2bits.GIE = 1;                // Enable the Global Interrupt Flag  
#define DISABLE_INTERRUPTS  INTCON2bits.GIE = 0;                // Disable the Global Interrupt Flag  
#define TOGGLE_INTERRUPTS   INTCON2bits.GIE = !INTCON2bits.GIE; // Toggle the Global Interrupt Flags


/**
    <p><b>Function prototype:</b></p>
 * void setupOsc(
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
void setupOsc(
    uint16_t osccon,
    uint16_t osctun,
    uint16_t clkdiv,
    uint16_t oscdiv,
    uint16_t oscfdiv
);


/**
    <p><b>Function prototype:</b></p>
 * void setupSPI1Slave(uint16_t SCLK_Pin, uint16_t CS_Pin, uint16_t MISO_Pin, uint16_t MOSI_Pin)

    <p><b>Description:</b></p>
 * Sets up SPI1 as a Slave in the following pins
 * SCLK_Pin, CS_Pin, MISO_Pin, MOSI_Pin

    <p><b>Parameters:</b></p>
 * SCLK_Pin  - Select SCLK Pin
 * CS_Pin    - Select CS Pin
 * MISO_Pin  - Select MISO Pin
 * MOSI_Pin  - Select MOSI Pin
 */
void setupSPI1Slave(uint16_t SCLK_Pin, uint16_t CS_Pin, uint16_t MISO_Pin, uint16_t MOSI_Pin);

/**
    <p><b>Function prototype:</b></p>
 * void setupSPI1Slave(uint16_t SCLK_Pin, uint16_t CS_Pin, uint16_t MISO_Pin, uint16_t MOSI_Pin)

    <p><b>Description:</b></p>
 * Sets up SPI2 as a Master in the following pins
 * SCLK_Pin, CS_Pin, MISO_Pin, MOSI_Pin

    <p><b>Parameters:</b></p>
 * SCLK_Pin  - Select SCLK Pin
 * CS_Pin    - Select CS Pin
 * MISO_Pin  - Select MISO Pin
 * MOSI_Pin  - Select MOSI Pin
 */
void setupSPI2Master(uint16_t SCLK_Pin, uint16_t CS_Pin, uint16_t MISO_Pin, uint16_t MOSI_Pin);

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* PERIPHERALS_INTERRUPTS_H */

