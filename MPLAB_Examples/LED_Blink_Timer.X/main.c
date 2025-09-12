/*
 * File:   main.c
 * Author: Jo�o Duarte
 *         Gon�alo Antunes
 *         Gon�alo Batalha
 */


#include "xc.h"
#include "common.h"

// Always runs this to start some key registers at key values
void alwaysSetup(void){
    ANSELA = 0;
    ANSELB = 0;
    
    TRISA = 0;
    TRISB = 0;
    
    LATA = 0;
    LATB = 0;
    
    return;
}

int main(void){
    alwaysSetup();
    
    setup();
    
    while(1){
        loop();
    }
    
    return 0;
}
