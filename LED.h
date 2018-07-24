/* 
 * File:   LED.h
 * Author: Moath
 *
 * Created on July 23, 2018, 10:18 PM
 */

#ifndef LED_H
#define	LED_H

#include <xc.h>
#include <stdint.h>


#define LED PORTAbits.RA2


void LED_Init (void);

#endif	/* LED_H */

