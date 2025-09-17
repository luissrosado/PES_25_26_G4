#include <xc.h>
#include <stdint.h>
#include "ldr.h"

volatile LDR_Registers_t LDR = {
    .value = 0,
    .threshold = LDR_THRESHOLD,
    .count = 0
};

void ADC_setup(void) {
    ANSB = 0x0002;               // Set RB2/AN2 as analog pin
    AD1CON1 = 0x0070;            // SSRC = 111, internal counter ends sampling and starts conversion
    AD1CHS  = 0x0002;            // Select AN2 (RB2) as input channel
    AD1CSSL = 0;                 // Disable channel scanning
    AD1CON3 = 0x0F00;            // Sample time = 15 Tad, Tad = Tcy
    AD1CON2 = 0x0004;            // Interrupt flag set after 2 samples
    AD1CON1bits.ADON = 1;        // Turn ADC module ON
}

void ADC_read(void) {
    uint16_t ldrValue;

    IFS0bits.AD1IF = 0;             // Clear flag
    AD1CON1bits.ASAM = 1;           // Start conversion

    while (!IFS0bits.AD1IF);        // Wait for 2 samples

    AD1CON1bits.ASAM = 0;       // Stop Conversion

    // Read 2 samples from the buffer 
    ldrValue  = ADC1BUF0;                
    //ldrValue += *((&ADC1BUF0) + 1);

    // 2 samples mean
    //ldrValue >>= 1;

    LDR.value = ldrValue;  
}

void ADC_check(void){
    // If the ldr value is bigger than the threshold it counts
    if (LDR.value > LDR.threshold) {
        LDR.count++;
    }
}