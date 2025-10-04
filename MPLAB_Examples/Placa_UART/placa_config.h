
#ifndef PLACA_CONFIG
#define PLACA_CONFIG

#include <xc.h>
#include <stdint.h>

// Clock definitions
#define FOSC 8000000UL                  // Oscillator frequency 8MHz
#define FCY  (FOSC/2)                   // Cycle frequency FOSC/2
#define BAUDRATE 9600
#define BRGVAL 103

#include <libpic30.h>
#include "p24FJ1024GB610.h"

#endif	//PLACA_CONFIG
