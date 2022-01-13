/*
 * LED.h
 *
 *  Created on: Jan 6, 2022
 *      Author: Khaled Ali
 */

#ifndef ECUAL_LED_H_
#define ECUAL_LED_H_

#include "../../LIB/Typedef.h"
#include "../../MCAL/DIO/DIO.h"

typedef struct{
	uint8_t PORT;
	uint8_t PIN;	
}LED_t;

uint8_t LED_u8Init(const LED_t* led);
uint8_t LED_u8ON(const LED_t* led);

uint8_t LED_u8OFF(const LED_t* led);

uint8_t LED_u8TOGGLE(const LED_t* led);


#endif /* ECUAL_LED_H_ */
