#ifndef LDR_H
#define LDR_H

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

#define LDR_THRESHOLD 500 // ~10 bit half range

// LDR Registers
typedef struct {
    uint16_t value;     
    uint16_t threshold; 
    uint16_t count;   
} LDR_Registers_t;

extern volatile LDR_Registers_t LDR;

void ADC_setup(void);
void ADC_read(void);
void ADC_check(void);

#endif // LDR_H
