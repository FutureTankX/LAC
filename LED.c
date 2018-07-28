#include "LED.h"


void LED_Init () {
TRISAbits.TRISA2 = 0; //Enable LED GPIO as OUTPUT
}