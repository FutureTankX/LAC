#include "PWM.h"


void PWM_Init() {
    TRISAbits.TRISA1 = 1;
    PWM2CON = 0;
    PR2 = 0x40;
    PWM2DCHbits.PWM2DCH = 0;
    PWM2DCLbits.PWM2DCL = 0;
    PIR1bits.TMR2IF     = 0;
    T2CONbits.T2CKPS    = 0b11; //prescaler 1
    T2CONbits.TMR2ON    = 1; //Turn on TIMER 2
    PWM2CONbits.PWM2OUT = 1;
    TRISAbits.TRISA1    = 0;
    PWM2CONbits.PWM2EN  = 1;
    PWM2CONbits.PWM2OE  = 1;
    PWM2CONbits.PWM2POL = 1;
}

void PWM_DutyLoad(uint16_t __DutyValue) {
     // Writing to 8 MSBs of PWM duty cycle in PWMDCH register
     PWM2DCH = (__DutyValue & 0x03FC)>>2;
     
     // Writing to 2 LSBs of PWM duty cycle in PWMDCL register
     PWM2DCL = (__DutyValue & 0x0003)<<6;
 }

void PWM_DutyInc() {
    if (DutyValue < 255) DutyValue++;
    PWM_DutyLoad(DutyValue);
}

void PWM_DutyDec() {
    if (DutyValue > 0) DutyValue--;
    PWM_DutyLoad(DutyValue);
}




