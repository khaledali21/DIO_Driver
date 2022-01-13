/*
 * LED.c
 *
 *  Created on: Jan 6, 2022
 *      Author: Khaled Ali
 */


#include "LED.h"


uint8_t LED_u8Init(const LED_t* led){
	return DIO_u8SetPinDirection(led->PORT, led->PIN, OUTPUT_PIN);
}

uint8_t LED_u8ON(const LED_t* led){
	return DIO_u8SetPinData(led->PORT, led->PIN, HIGH);
}

uint8_t LED_u8OFF(const LED_t* led){
	return DIO_u8SetPinData(led->PORT, led->PIN, LOW);
}

uint8_t LED_u8TOGGLE(const LED_t* led){
	return DIO_u8TogglePinData(led->PORT, led->PIN);
}
