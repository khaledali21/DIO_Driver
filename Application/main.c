/*
 * main.c
 *
 *  Created on: Jan 6, 2022
 *      Author: Khaled Ali
 */

#include "main.h"
LED_t led0 = {PORTB, PIN5};
LED_t led_err = {PORTB, PIN7};
BTN_t btn0 = {PORTB, PIN2};
int main(void){
	uint8_t status = OK;
	LED_u8Init(&led_err);
	status = LED_u8Init(&led0);
	if(status != OK){
		errorHandler();
	}
	status = BTN_u8Init(&btn0);
	if(status != OK){
		errorHandler();
	}
	status = TIMER0_u8Init();
	if(status != OK){
		errorHandler();		
	}
	while(1){
		status = TIMER0_u8InterruptDelay(10, btn0_callBack);
		if(status == ERR){
			errorHandler();
		}
	}
}

void btn0_callBack(void){
	uint8_t pressed;
	uint8_t status = BTN_u8State(&btn0, &pressed);
	if(status){
		if(pressed){
			LED_u8TOGGLE(&led0);
		}	
	}
}

void errorHandler(void){
	LED_u8ON(&led_err);
	while(1); //trap program
}