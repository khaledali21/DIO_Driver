/*
 * LED.c
 *
 *  Created on: Jan 6, 2022
 *      Author: Khaled Ali
 */


#include "LED.h"


LED_ERR_STATE LED_u8Init(const LED_t* led){
	LED_ERR_STATE state = LED_OK;
	if(led == NULL){
		state = LED_ERR;
	}
	else{
		state = DIO_u8SetPinDirection(led->PORT, led->PIN, OUTPUT_PIN);
	}
	return state;
}

LED_ERR_STATE LED_u8ON(const LED_t* led){
	LED_ERR_STATE state = LED_OK;
	if(led == NULL){
		state = LED_ERR;
	}
	else{
		state = DIO_u8SetPinData(led->PORT, led->PIN, HIGH);
	}
	return state;
}

LED_ERR_STATE LED_u8OFF(const LED_t* led){
	LED_ERR_STATE state = LED_OK;
	if(led == NULL){
		state = LED_ERR;
	}
	else{
		state = DIO_u8SetPinData(led->PORT, led->PIN, LOW);
	}
	return state;
}

LED_ERR_STATE LED_u8TOGGLE(const LED_t* led){
	LED_ERR_STATE state = LED_OK;
	if(led == NULL){
		state = LED_ERR;
	}
	else{
		state = DIO_u8TogglePinData(led->PORT, led->PIN);
	}
	return state;
}
