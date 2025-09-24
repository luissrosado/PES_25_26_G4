/*
 * File:   main.c
 * Author: João Duarte
 *         Gonçalo Antunes
 *         Gonçalo Batalha
 */


#include "xc.h"
#include "common.h"
#include "spi.h"
#include "LIS3DH.h"


// Always runs this to start some key registers at key values
void alwaysSetup(void){
    ANSELA = 0;
    ANSELB = 0;
    
    TRISA = 0;
    TRISB = 0;
    
    LATA = 0;
    LATB = 0;
    
    // Disable every peripheral
    // Check pages 116 to 123 of the datasheet if you need to enable any
    // The setup functions already enable them
    PMD1 = 0xFFFF;
    PMD2 = 0xFFFF;
    PMD3 = 0xFFFF;
    PMD4 = 0xFFFF;
    PMD5 = 0xFFFF;
    PMD6 = 0xFFFF;
    PMD7 = 0xFFFF;
    PMD8 = 0xFFFF;
    pinMode(RB3, OUTPUT);
    return;
}

int main(void){
    alwaysSetup();
    int8_t data;
    setup();
    spi_config_master();
    data=who_am();
    while(1){
        //loop();
    }
    
    return 0;
}
