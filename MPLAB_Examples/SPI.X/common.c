/*
 * File:   common.c
 * Author: João Duarte
 *         Gonçalo Antunes
 *         Gonçalo Batalha
 *
 * Created on September 9, 2025, 11:38 PM
 */


#include "common.h"
#include "../../PIC24_Lib/PIC24FJ256GA702_lib.X/PIC24FJ256GA702_lib.h"
#include "spi.h"
#include "LIS3DH.h"

#define FCY 1000000
#include "libpic30.h"

LIS acc;

void setup(void){
    // Insert your setup code here, to run once:
    int8_t data;
    
    pinMode(RB3, OUTPUT);
    pinMode(RB5, OUTPUT);
    spi_config_master();
    spi2_enable();
    data = who_am();
    LISconfig();
    
    return;
}

void loop(void){
    // Insert your loop code here, to run repeatedly:
    accel(&acc);
    __delay32(5000);
    return;
}
