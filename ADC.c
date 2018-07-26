#include "ADC.h"

void ADC_Init (uint8_t Channel) {
    
    switch (Channel) {
        case 0:
            TRISAbits.TRISA0 = 1;
            ANSELAbits.ANSA0 = 1;
            WPUAbits.WPUA0   = 0;
        break;
        case 1:
            TRISAbits.TRISA1 = 1;
            ANSELAbits.ANSA1 = 1;
            WPUAbits.WPUA1   = 0;
        break;
        case 2:
            TRISAbits.TRISA2 = 1;
            ANSELAbits.ANSA2 = 1;
            WPUAbits.WPUA2   = 0;
        break;
    }
    
    ADCONbits.ADCS = 0b010;
    ADCONbits.CHS = Channel;
    ADCONbits.ADON = 1; 
}

uint8_t ADC_Read() {
        uint8_t __adcVal;
        ADCONbits.GO_nDONE = 1;       //Enable
        while (ADCONbits.GO_nDONE);   //Wait for ADC to complete
        __adcVal = ADRES;
        return __adcVal;
}