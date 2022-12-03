/*
 * input_processing.c
 *
 *  Created on: Nov 23, 2022
 *      Author: pmt12
 */

#include "main.h"
#include "input_processing.h"

enum ButtonState {BUTTON_IDLE, BUTTON_PRESSED, BUTTON_PRESSED_1S};
enum ButtonState buttonState = BUTTON_IDLE;

void fsm_for_input_processeing(){
	switch(buttonState){
	case BUTTON_IDLE:
		if(is_button_pressed(0) || is_button_pressed(1) || is_button_pressed(2)){
			buttonState = BUTTON_PRESSED;
		}
		break;
	case BUTTON_PRESSED:
		if(!(is_button_pressed(0) || is_button_pressed(1) || is_button_pressed(2))){
			buttonState = BUTTON_IDLE;
		}
		if(is_button_pressed_1s(0) || is_button_pressed_1s(1) || is_button_pressed_1s(2)){
			buttonState = BUTTON_PRESSED_1S;
		}
		break;
	case BUTTON_PRESSED_1S:
		if(!(is_button_pressed(0) || is_button_pressed(1) || is_button_pressed(2))){
			buttonState = BUTTON_IDLE;
		}
		break;
	default:
		break;
	}
}
