/*
 * Button.c
 *
 * Created: 1/7/2022 8:07:33 PM
 *  Author: Khaled Ali
 */ 


#include "BUTTON.h"

BTN_ERR_STATE BTN_u8Init(const BTN_t* btn){
	BTN_ERR_STATE status = BTN_OK;
	if(btn == NULL){
		status = BTN_ERR;
	}
	else{
		status = DIO_u8SetPinDirection(btn->PORT, btn->PIN, INPUT_PIN_PULLUP);
	}
	return status;
}

BTN_ERR_STATE BTN_u8State(const BTN_t* btn, uint8_t* pressed){
	BTN_ERR_STATE status = BTN_OK;
	static uint16_t buttonDebouncer = 0;
	if(btn == NULL){
		status = BTN_ERR;
	}
	else{
		uint8_t getBTN = HIGH;
		status = DIO_u8GetPinData(btn->PORT, btn->PIN, &getBTN);
		if(status == BTN_OK){
			buttonDebouncer = (buttonDebouncer << 1) | getBTN | 0xe000;
			if (buttonDebouncer == 0xf000){
				*pressed = 1;
			}
			else{
				*pressed = 0;
			}
		}
	}
	return status;
}