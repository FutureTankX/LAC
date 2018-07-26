/* 
 * File:   PWM.h
 * Author: Moath
 *
 * Created on July 16, 2018, 9:47 PM
 */

#ifndef PWM_H
#define	PWM_H

#include <xc.h>
#include <stdint.h>


void PWM_Init(void);
void PWM_LoadDutyValue(uint16_t dutyValue);

#endif	/* PWM_H */

