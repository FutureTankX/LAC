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

extern uint16_t DutyValue;

void PWM_Init(void);
void PWM_DutyLoad(uint16_t __DutyValue);
void PWM_DutyInc(void);
void PWM_DutyDec(void);
#endif	/* PWM_H */

