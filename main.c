/*
 * File:   main.c
 * Author: Moath
 *
 * Created on July 16, 2018, 9:46 PM
 */

// CONFIG
#pragma config FOSC = INTOSC    // Oscillator Selection bits (INTOSC oscillator: CLKIN function disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable (Brown-out Reset enabled)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select bit (MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config LVP = ON         // Low-Voltage Programming Enable (Low-voltage programming enabled)
#pragma config LPBOR = ON       // Brown-out Reset Selection bits (BOR enabled)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)

#define _XTAL_FREQ 16000000

#include <xc.h>
#include "LED.h"
#include "ADC.h"

#define ADC_CHANNEL 0



uint16_t ADC;


void Clock_Init(void);

void main(void) {
    
    Clock_Init();
    ADC_Init(ADC_CHANNEL);
    LED_Init();
    ADC = ADC_Read();
    while (1) {
        ADC = ADC_Read();
        if (ADC > 127) {
        LED = 1;
        __delay_ms(500);
        LED = 0;
        __delay_ms(500);
        }
    }
}



void Clock_Init() {

    OSCCONbits.IRCF = 0b111; // 16 Mhz
    while (!OSCCONbits.HFIOFR || !OSCCONbits.HFIOFS);
}


