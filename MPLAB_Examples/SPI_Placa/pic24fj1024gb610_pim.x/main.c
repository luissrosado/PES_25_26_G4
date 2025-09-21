#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

#define FCY 16000000UL
#include <libpic30.h>      // Para __delay_ms()
#include "bsp/lcd.h"       // LCD driver

//---------------------------
// Pino CS
//---------------------------
#define CS_LAT _LATB11
#define CS_TRIS _TRISB11

//---------------------------
// Controle CS
//---------------------------
#define CS_LOW()  (CS_LAT = 0)
#define CS_HIGH() (CS_LAT = 1)

//---------------------------
// Inicializa PPS e direção dos pinos SPI1
//---------------------------
void SPI1_PPS_Init(void)
{
    // Desbloqueia PPS
    __builtin_write_OSCCONL(OSCCON & 0xBF);

    // Mapear pinos SPI1
    RPOR4bits.RP8R   = 0x0007;  // RP8 -> SDO1
    RPINR20bits.SDI1R = 0x0009; // RP9 -> SDI1
    RPOR5bits.RP10R  = 0x0008;  // RP10 -> SCK1OUT

    // Bloqueia PPS
    __builtin_write_OSCCONL(OSCCON | 0x40);

    // Configura direção
    _TRISB8 = 0;   // SDO1 saída
    _TRISB9 = 1;   // SDI1 entrada
    _TRISB10 = 0;  // SCK1 saída
    CS_TRIS  = 0;  // CS saída
    CS_HIGH();     // CS inativo
}

//---------------------------
// Inicializa SPI1 Master
//---------------------------
void SPI1_Init(void)
{
    uint16_t dummy;

    SPI1CON1Lbits.SPIEN = 0;  // Desativa SPI antes de configurar

    IFS0bits.SPI1IF = 0;
    IEC0bits.SPI1IE = 0;

    // Limpa buffer
    while(SPI1STATLbits.SPIRBF) dummy = SPI1BUFL;
    SPI1STATLbits.SPIROV = 0;  // limpa overflow

    // Configura SPI1
    SPI1CON1bits.DISSCK = 0;  // clock interno
    SPI1CON1bits.DISSDO = 0;  // SDO ativo
    SPI1CON1bits.MODE16 = 1;  // 16 bits
    SPI1CON1bits.SMP = 0;     // sample no meio
    SPI1CON1bits.CKP = 0;     // idle low
    SPI1CON1bits.CKE = 1;     // transição na borda de subida
    SPI1CON1bits.MSTEN = 1;   // master mode

    SPI1CON2 = 0;              // frame mode desativado
    SPI1BRGL = 3;              // F_SCK ? 2 MHz

    SPI1CON1Lbits.SPIEN = 1;   // habilita SPI
}

//---------------------------
// Transferência SPI 16 bits
//---------------------------
uint16_t SPI1_Transfer16(uint16_t data)
{
    SPI1BUFL = data;
    while(!SPI1STATLbits.SPIRBF); // espera terminar
    return SPI1BUFL;
}

//---------------------------
// Programa principal
//---------------------------
int main(void)
{
    uint16_t command = 0x0055;
    uint16_t response;

    // Inicializa PPS e pinos SPI1
    SPI1_PPS_Init();

    // Inicializa SPI1
    SPI1_Init();

    // Inicializa LCD
    LCD_Initialize();

    while(1)
    {
        // Ativa CS
        CS_LOW();
        response = SPI1_Transfer16(command);
        CS_HIGH();  // Desativa CS

        // Mostra mensagem no LCD
        printf("\fAI ZE DA MANGA");

        // Verifica resposta do slave
        if(response == 0x00AA)
        {
            printf("\nSLAVE OK");
        }

        __delay_ms(500);
    }

    return 0;
}
