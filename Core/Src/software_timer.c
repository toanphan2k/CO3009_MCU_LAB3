/*
 * software_timer.c
 *
 *  Created on: Nov 16, 2022
 *      Author: pmt12
 */
#include "software_timer.h"

void setTimerTraffic1(int duration){
	trafficTimer1_counter = duration/TIMER_CYCLE;
	trafficTimer1_flag = 0;
}
void setTimerTraffic2(int duration){
	trafficTimer2_counter = duration/TIMER_CYCLE;
	trafficTimer2_flag = 0;
}

void setTimerWait(int duration){
	waitTimer_counter = duration/TIMER_CYCLE;
	waitTimer_flag = 0;
}

void setTimerModify(int duration){
	modifyTimer_counter = duration/TIMER_CYCLE;
	modifyTimer_flag = 0;
}

void setTimerTriggerLed(int duration){
	timerLed_counter = duration/TIMER_CYCLE;
	timerLed_flag = 0;
}

void timer_run(){
	if(trafficTimer1_counter >= 0){
		trafficTimer1_counter --;
		if(trafficTimer1_counter == 0) trafficTimer1_flag = 1;
	}
	if(trafficTimer2_counter >= 0){
		trafficTimer2_counter --;
		if(trafficTimer2_counter == 0) trafficTimer2_flag = 1;
	}
	if(waitTimer_counter >= 0){
		waitTimer_counter --;
		if(waitTimer_counter == 0) waitTimer_flag = 1;
	}
	if(modifyTimer_counter >= 0){
		modifyTimer_counter --;
		if(modifyTimer_counter == 0) modifyTimer_flag = 1;
	}
	if(timerLed_counter >= 0){
		timerLed_counter --;
		if(timerLed_counter == 0) timerLed_flag = 1;
	}
}
