/*
 * Button.c
 *
 * Created: 1/7/2022 8:07:33 PM
 *  Author: Khaled Ali
 */ 


#include "BUTTON.h"

uint8_t BTN_u8Init(const BTN_t* btn){
	return DIO_u8SetPinDirection(btn->PORT, btn->PIN, INPUT_PIN_PULLUP);
}

uint8_t BTN_u8State(const BTN_t* btn, uint8_t* pressed){
	static uint16_t buttonDebouncer = 0;
	uint8_t getBTN = HIGH;
	uint8_t status = DIO_u8GetPinData(btn->PORT, btn->PIN, &getBTN);
	if(status == OK){
		buttonDebouncer = (buttonDebouncer << 1) | getBTN | 0xe000;
		if (buttonDebouncer == 0xf000){
			*pressed = 1;
		}
		else{
			*pressed = 0;
		}
	}
	return status;
}