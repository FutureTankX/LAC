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
#include "PWM.h"

#define ADC_CHANNEL 0
#define BATTERY_MAINTAIN_VOLTAGE 172
#define NUMBER_OF_AVERAGES 3



uint8_t ADC;
uint16_t DutyValue = 0;


void Clock_Init(void);
void Battery_Voltage_Mintain(uint8_t __Voltage);
void PWM_DutyInc(void);
void PWM_DutyDec(void);

void main(void) {
    
    Clock_Init();
    ADC_Init(ADC_CHANNEL);
    LED_Init();
    PWM_Init();
    PWM_DutyLoad(DutyValue);
    while (1) {
        Battery_Voltage_Mintain(BATTERY_MAINTAIN_VOLTAGE);
        //__delay_ms(500);
    }
}

void Clock_Init() {
    OSCCONbits.IRCF = 0b111;                            //16Mhz
    while (!OSCCONbits.HFIOFR || !OSCCONbits.HFIOFS);   //Wait for stable clock 
}

void Battery_Voltage_Mintain(uint8_t __Voltage) {
    ADC = ADC_Average(NUMBER_OF_AVERAGES);
    if (ADC > __Voltage) PWM_DutyInc();
    if (ADC < __Voltage) PWM_DutyDec();
}

