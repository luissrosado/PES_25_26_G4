#include <xc.h>
#include <stdio.h>
#include "placa_config.h"
#include "io_mapping.h"

#include "commands.h"

#include "bsp/lcd.h"
#include "bsp/timer_1ms.h"
#include "bsp/rtcc.h"
#include "bsp/leds.h"

// ===== SPI1 Setup =====
void init_spi1(void)
{
    SPI1CON1Lbits.SPIEN = 0;   // Disable SPI before configuring

    // Disable interrupts
    IEC0bits.SPI1IE = 0;
    IFS0bits.SPI1IF = 0;

    // SPI configuration
    SPI1CON1bits.DISSCK = 0;   // Enable internal SPI clock
    SPI1CON1bits.DISSDO = 0;   // Enable SDO
    SPI1CON1bits.MODE16 = 1;   // 16-bit communication
    SPI1CON1bits.SMP = 0;      // Sample in middle of output time
    SPI1CON1bits.CKP = 0;      // Clock idle state = low
    SPI1CON1bits.CKE = 1;      // Data changes on falling edge
    SPI1CON1bits.MSTEN = 1;    // Master mode enabled

    // Baud rate: Fcy / (2 * (BRG+1))
    SPI1BRGL = 4;              // ~4 MHz se Fcy = 40 MHz

    SPI1CON2 = 0;              // Disable framed mode

    // Pin mapping
    RPINR20bits.SDI1R = 26;    // SDI (MISO) -> RP26
    RPOR9bits.RP19R   = 7;     // SDO (MOSI) -> RP19
    RPOR10bits.RP21R  = 8;     // SCK -> RP21 
    ANSGbits.ANSELG7 = 0;

    // Chip Select pin (RB1)
    ANSELGbits.ANSG9 = 0;      // Set RB1 as digital
    TRISGbits.TRISG9 = 0;      // Configure as output
    LATGbits.LATG9 = 1;        // CS high (inactive)

    SPI1CON1Lbits.SPIEN = 1;   // Enable SPI module
}

// ===== SPI Transfer (single 16-bit word) =====
uint16_t SPI1_Transfer16(uint16_t data)
{
    uint16_t rx;

    LATGbits.LATG9 = 0;        // Assert CS (active low)
    __delay_us(5);

    SPI1BUFL = data;                    // Send
    while (!SPI1STATLbits.SPIRBF);      // Wait receive complete
    rx = SPI1BUFL;                      // Read response
    
    __delay_us(5);
    LATGbits.LATG9 = 1;        // De-assert CS
    
    return rx;
}



// ===== Main Program =====
int main(void)
{
    const uint16_t commands[] = {
        COMMANDS_VALS
    };
    uint16_t replies[CMD_NUM];
    
    // Inicializa o vetor de respostas
    for(int i = 0; i < CMD_NUM; i++){
        replies[i] = i;
    }
    
    // Inicializa periféricos básicos da placa
    SYS_Initialize();
    
    // Limpa tela do LCD
    printf("\f");
    printf("Starting SPI...\r\n");

    // Inicializa SPI1
    init_spi1();        
    
    BUTTON_Enable(BUTTON_S3);
    LED_Enable(LED_D3);
    
    __delay_ms(10000);
    
    printf("\f");

    while(1)
    {
        /*
        for(int i = 0; i < CMD_NUM; i++){
            replies[i] = SPI1_Transfer16(commands[i]);
            __delay_ms(500);
        }
        */
        replies[0] = SPI1_Transfer16(commands[0]);
        
        // Escreve no LCD os valores do LDR
        printf(
            "LDR: 0x%04X\r\nCNT: 0x%04X\r\n",
            replies[LDR_VAL_POS],
            replies[LDR_CNT_POS]
        );

        // Escreve no LCD os valores do AXL
        /*
        printf(
            "X:%d;Y:%d;Z:%d\r\n",
            replies[AXL_X_POS],
            replies[AXL_Y_POS],
            replies[AXL_Z_POS]
        );
        */

        
        if (BUTTON_IsPressed(BUTTON_S3)){
            LED_On(LED_BLINK_ALIVE);
        }
        else{
            LED_Off(LED_BLINK_ALIVE);
        }

        __delay_ms(500);
    }

    return 0;
}
