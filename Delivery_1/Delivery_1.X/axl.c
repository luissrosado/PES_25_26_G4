/*
 * File:   axl.c
 * Author: João Duarte
 *         Gonçalo Antunes
 *         Gonçalo Batalha
 *
 */


#include "xc.h"
#include "axl.h"


uint16_t SPI2_Pool_Transfer(uint16_t dataOut) {
    while (SPI2STATLbits.SPITBF);   // Espera que o buffer TX fique livre
    SPI2BUFL = dataOut;             // Envia 16 bits, o HIGH BYTE e o address, o low byte é os dados po addr
    
    while (!SPI2STATLbits.SPIRBF);  // Espera receção
    return SPI2BUFL;                // Retorna dado recebido
}

void LISconfig(void){
    int16_t tx;
    tx = (CTRL_REG0<<8 | 0x90) | WRITE; // pull up disable on SD0 line
    digitalWrite(RB3, LOW);     // Chip Select
    SPI2_Pool_Transfer(tx);
    digitalWrite(RB3, HIGH);    // Chip Deselect
    
    tx = (CTRL_REG1<<8 | 0x47); // 50hz output data rate (ODR)
    digitalWrite(RB3, LOW);     // Chip Select
    SPI2_Pool_Transfer(tx);
    digitalWrite(RB3, HIGH);    // Chip Deselect
    
    tx = (CTRL_REG4<<8 | 0x00); // full scale +-2g (~20 m/s2)
    digitalWrite(RB3, LOW);     // Chip Select
    SPI2_Pool_Transfer(tx);
    digitalWrite(RB3, HIGH);    // Chip Deselect
    
    return;
}

void readAXL(LIS *accel){ //saida dos valores não esta convertido, fazer conversao apos enviar devboard (multiplicar por 39)
    int16_t accx_l=0x2800, tx;
    int8_t accL, accH;      //valores LOW e HIGH byte da accelaracao respetivamente
    
    // Read X Axis
    tx = accx_l | READ;
    digitalWrite(RB3, LOW);     // Chip Select
    accL = SPI2_Pool_Transfer(tx);
    digitalWrite(RB3, HIGH);    // Chip Deselect
    
    tx += 0x0100;
    digitalWrite(RB3, LOW);     // Chip Select
    accH = SPI2_Pool_Transfer(tx);
    digitalWrite(RB3, HIGH);    // Chip Deselect
    accel->accelX = ((int16_t)accH << 8) | accL;
    
    
    // Read Y Axis
    tx += 0x0100;
    digitalWrite(RB3, LOW);     // Chip Select
    accL = SPI2_Pool_Transfer(tx);
    digitalWrite(RB3, HIGH);    // Chip Deselect
    
    tx += 0x0100;
    digitalWrite(RB3, LOW);     // Chip Select
    accH = SPI2_Pool_Transfer(tx);
    digitalWrite(RB3, HIGH);    // Chip Deselect
    accel->accelY = ((int16_t)accH << 8) | accL;
    
    
    // Read Z Axis
    tx += 0x0100;
    digitalWrite(RB3, LOW);     // Chip Select
    accL = SPI2_Pool_Transfer(tx);
    digitalWrite(RB3, HIGH);    // Chip Deselect
    
    tx += 0x0100;
    digitalWrite(RB3, LOW);     // Chip Select
    accH = SPI2_Pool_Transfer(tx);
    digitalWrite(RB3, HIGH);    // Chip Deselect
    accel->accelZ = ((int16_t)accH << 8) | accL;
    
    
    return;
}