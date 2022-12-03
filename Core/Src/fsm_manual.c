/*
 * fsm_manual.c
 *
 *  Created on: Nov 23, 2022
 *      Author: pmt12
 */

#include "fsm_manual.h"
#include "fsm_automatic.h"
#include "global.h"
#include "button.h"
#include "software_timer.h"
#include "led_segment_control.h"

void trafficLight_manual(){
	switch(state){
	case SELECT_MODE_RED:
		isRedMode = 1;
		isYellowMode = 0;
		isGreenMode = 0;
		if(isPressedAndReleased(BTN_SELECT_INDEX)){
			state = SELECT_MODE_YELLOW;
		}
		if(isPressedAndReleased(BTN_MODIFY_INDEX)){
			state = MODIFY_PRESSED;
			tempCounter = counter_red;
		}
		if(is_button_pressed(BTN_MODIFY_INDEX)){
			if(is_button_pressed_3s(BTN_MODIFY_INDEX)){
				state = MODIFY_LONGPRESSED;
				tempCounter = counter_red;
				tempCounter += 10;
				if(tempCounter > MAX_SEGMENT_VALUE) {
					tempCounter = 0;
				}
				setTimerModify(DURATION_1S);
			}
		}
		if(isPressedAndReleased(BTN_SET_INDEX)){
			state = SET_PRESSED;
			setTimerWait(DURATION_3S);
		}
		break;
	case SELECT_MODE_YELLOW:
		isRedMode = 0;
		isYellowMode = 1;
		isGreenMode = 0;
		if(isPressedAndReleased(BTN_SELECT_INDEX)){
			state = SELECT_MODE_GREEN;
		}
		if(isPressedAndReleased(BTN_MODIFY_INDEX)){
			state = MODIFY_PRESSED;
			tempCounter = counter_yellow;
		}
		if(is_button_pressed(BTN_MODIFY_INDEX)){
			if(is_button_pressed_3s(BTN_MODIFY_INDEX)){
				state = MODIFY_LONGPRESSED;
				tempCounter = counter_yellow;
				tempCounter += 10;
				if(tempCounter > MAX_SEGMENT_VALUE) {
					tempCounter = 0;
				}
			}
			setTimerModify(DURATION_1S);
		}
		if(isPressedAndReleased(BTN_SET_INDEX)){
			state = SET_PRESSED;
			setTimerWait(DURATION_3S);
		}
		break;
	case SELECT_MODE_GREEN:
		isRedMode = 0;
		isYellowMode = 0;
		isGreenMode = 1;
		if(isPressedAndReleased(BTN_SELECT_INDEX)){
			state = SELECT_MODE_RED;
		}
		if(isPressedAndReleased(BTN_MODIFY_INDEX)){
			state = MODIFY_PRESSED;
			tempCounter = counter_green;
		}
		if(is_button_pressed(BTN_MODIFY_INDEX)){
			if(is_button_pressed_3s(BTN_MODIFY_INDEX)){
				state = MODIFY_LONGPRESSED;
				tempCounter = counter_green;
				tempCounter += 10;
				if(tempCounter > MAX_SEGMENT_VALUE) {
					tempCounter = 0;
				}
			}
			setTimerModify(DURATION_1S);
		}
		if(isPressedAndReleased(BTN_SET_INDEX)){
			state = SET_PRESSED;
			setTimerWait(DURATION_3S);
		}
		break;
	case MODIFY_PRESSED:
		if(isRedMode == 1){
			tempCounter += 1;
			if(tempCounter > MAX_SEGMENT_VALUE){
				tempCounter =0;
			}
			state = SELECT_MODE_RED;
		}
		else if(isYellowMode == 1){
			tempCounter += 1;
			if(tempCounter > MAX_SEGMENT_VALUE){
				tempCounter =0;
			}
			state = SELECT_MODE_YELLOW;
		}
		else if(isGreenMode == 1){
			tempCounter += 1;
			if(tempCounter > MAX_SEGMENT_VALUE){
				tempCounter = 0;
			}
			state = SELECT_MODE_GREEN;
		}
		break;
	case MODIFY_LONGPRESSED:
		if(modifyTimer_flag == 1){
			tempCounter += 10;
			if(tempCounter > MAX_SEGMENT_VALUE) {
				tempCounter = 0;
			}
		}

		if(!is_button_pressed(BTN_MODIFY_INDEX)){
			if(isRedMode == 1) state = SELECT_MODE_RED;
			else if(isYellowMode == 1) state = SELECT_MODE_YELLOW;
			else if(isGreenMode == 1) state = SELECT_MODE_GREEN;
		}

		break;
	case SET_PRESSED:
		if(isRedMode == 1) counter_red = tempCounter;
		else if (isYellowMode == 1) counter_yellow = tempCounter;
		else if (isGreenMode == 1) counter_green = tempCounter;
		isRedMode = 0;
		isYellowMode = 0;
		isGreenMode = 0;
		isInManual = 0;

		if(waitTimer_flag == 1){
			state = IDLE;
		}
		break;
	default:
		break;
	}
}

void triggerLed(){
	if(timerLed_flag == 1){
		if (isRedMode == 1 && isInManual == 1){
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_TogglePin(LED_RED1_GPIO_Port, LED_RED1_Pin);
			HAL_GPIO_TogglePin(LED_RED2_GPIO_Port, LED_RED2_Pin);
			setTimerTriggerLed(DURATION_FOR_4HZ);
		}
		if (isYellowMode == 1 && isInManual == 1){
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_TogglePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin);
			HAL_GPIO_TogglePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin);
			setTimerTriggerLed(DURATION_FOR_4HZ);
		}
		if (isGreenMode == 1 && isInManual == 1){
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_RED1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_RED2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_TogglePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin);
			HAL_GPIO_TogglePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin);
			setTimerTriggerLed(DURATION_FOR_4HZ);
		}
	}
}
