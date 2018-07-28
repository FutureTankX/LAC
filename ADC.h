/* 
 * File:   ADC.h
 * Author: Moath
 *
 * Created on July 16, 2018, 9:47 PM
 */

#ifndef ADC_H
#define	ADC_H

#include <xc.h>
#include <stdint.h>


void ADC_Init (uint8_t Channel);
uint8_t ADC_Read(void);
uint8_t ADC_Average(uint8_t Average_Rounds);
#endif	/* ADC_H */

