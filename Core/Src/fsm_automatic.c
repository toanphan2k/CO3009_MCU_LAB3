/*
 * fsm_automatic.c
 *
 *  Created on: Nov 23, 2022
 *      Author: pmt12
 */


#include "fsm_automatic.h"
#include "fsm_manual.h"
#include "global.h"
#include "software_timer.h"
#include "led_segment_control.h"
#include "button.h"


void trafficLight_automatic(){
	switch(state){
	case IDLE:
		state = AUTO_RED1_GREEN2;
		clearTrafficDisplay();
		setTimerTraffic1(counter_red);
		setTimerTraffic2(counter_green);
		break;
	case AUTO_RED1_GREEN2:
		displayTrafficLight(RED_LIGHT, GREEN_LIGHT);
		if(trafficTimer2_flag == 1){
			setTimerTraffic2(counter_yellow);
			state = AUTO_RED1_YELLOW2;
		}
		if(isPressedAndReleased(BTN_SELECT_INDEX)){
			state = SELECT_MODE_RED;
			isInManual = 1;
			setTimerTriggerLed(DURATION_FOR_4HZ);
			clearTrafficDisplay();
		}

		break;
	case AUTO_RED1_YELLOW2:
		displayTrafficLight(RED_LIGHT, YELLOW_LIGHT);
		if(trafficTimer1_flag == 1
				|| trafficTimer2_flag == 1
				|| (trafficTimer1_flag == 1 && trafficTimer2_flag == 1) ){
			setTimerTraffic1(counter_green);
			setTimerTraffic2(counter_red);
			state = AUTO_GREEN1_RED2;
		}
		if(isPressedAndReleased(BTN_SELECT_INDEX)){
			state = SELECT_MODE_RED;
			isInManual = 1;
			setTimerTriggerLed(DURATION_FOR_4HZ);
			clearTrafficDisplay();
		}
		break;
	case AUTO_GREEN1_RED2:
		displayTrafficLight(GREEN_LIGHT, RED_LIGHT);
		if(trafficTimer1_flag == 1){
			setTimerTraffic1(counter_yellow);
			state = AUTO_YELLOW1_RED2;
		}
		if(isPressedAndReleased(BTN_SELECT_INDEX)){
			state = SELECT_MODE_RED;
			isInManual = 1;
			setTimerTriggerLed(DURATION_FOR_4HZ);
			clearTrafficDisplay();
		}
		break;
	case AUTO_YELLOW1_RED2:
		displayTrafficLight(YELLOW_LIGHT, RED_LIGHT);
		if(trafficTimer1_flag == 1
				|| trafficTimer2_flag == 1
				|| (trafficTimer1_flag == 1 && trafficTimer2_flag == 1) ){
			setTimerTraffic1(counter_green);
			setTimerTraffic2(counter_red);
			state = AUTO_RED1_GREEN2;
		}
		if(isPressedAndReleased(BTN_SELECT_INDEX)){
			state = SELECT_MODE_RED;
			isInManual = 1;
			setTimerTriggerLed(DURATION_FOR_4HZ);
			clearTrafficDisplay();
		}
		break;
}
