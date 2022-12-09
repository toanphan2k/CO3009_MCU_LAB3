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
		segment1Counter = counter_red / DIVISION_NUMBER;
		segment2Counter	= counter_green / DIVISION_NUMBER;
		setTimerTraffic1(counter_green);
		setTimerCounter1(DURATION_1S);
		setTimerScanFreq(DURATION_FOR_5HZ);
		update7SegBufferAuto();
		timeCounter = 0;
		break;
	case AUTO_RED1_GREEN2:
		display7SegAuto(segmentIndexAuto);
		displayTrafficLight(RED_LIGHT, GREEN_LIGHT);
		if(scanFreqTimer_flag == 1){
			update7SegBufferAuto();
			segmentIndexAuto++;
			if(segmentIndexAuto >= SEGMENT_IN_A_ROW) segmentIndexAuto = 0;
			setTimerScanFreq(DURATION_FOR_5HZ);
		}
		if(isPressedAndReleased(BTN_SELECT_INDEX)){
			state = SELECT_MODE_RED;
			isInManual = 1;
			setTimerTriggerLed(DURATION_FOR_4HZ);
			setTimerScanFreq(DURATION_FOR_5HZ);
			clearTrafficDisplay();
			tempCounter = counter_red/DIVISION_NUMBER;
			update7SegBufferManual();
		}
		if(countDownTimer1_counter == 1){
			segment1Counter --;
			segment2Counter --;
			if(segment2Counter  == 0) {
				segment2Counter = counter_yellow / DIVISION_NUMBER;
				state = AUTO_RED1_YELLOW2;
			}
			update7SegBufferAuto();
			setTimerCounter1(DURATION_1S);
		}
		break;
	case AUTO_RED1_YELLOW2:
		display7SegAuto(segmentIndexAuto);
		displayTrafficLight(RED_LIGHT, YELLOW_LIGHT);
		if(scanFreqTimer_flag == 1){
			update7SegBufferAuto();
			segmentIndexAuto++;
			if(segmentIndexAuto >= SEGMENT_IN_A_ROW) segmentIndexAuto = 0;
			setTimerScanFreq(DURATION_FOR_5HZ);
		}
		if(isPressedAndReleased(BTN_SELECT_INDEX)){
			state = SELECT_MODE_RED;
			isInManual = 1;
			setTimerTriggerLed(DURATION_FOR_4HZ);
			setTimerScanFreq(DURATION_FOR_5HZ);
			clearTrafficDisplay();
			tempCounter = counter_red/DIVISION_NUMBER;
			update7SegBufferManual();
		}
		if(countDownTimer1_counter == 1){
			segment1Counter --;
			segment2Counter --;
			if (segment2Counter <= 0){
				segment1Counter = counter_green / DIVISION_NUMBER;
				segment2Counter = counter_red / DIVISION_NUMBER;
				state = AUTO_GREEN1_RED2;
			}
			update7SegBufferAuto();
			setTimerCounter1(DURATION_1S);
		}
		break;
	case AUTO_GREEN1_RED2:
		display7SegAuto(segmentIndexAuto);
		displayTrafficLight(GREEN_LIGHT, RED_LIGHT);
		if(scanFreqTimer_flag == 1){
			update7SegBufferAuto();
			segmentIndexAuto++;
			if(segmentIndexAuto >= SEGMENT_IN_A_ROW) segmentIndexAuto = 0;
			setTimerScanFreq(DURATION_FOR_5HZ);
		}
		if(isPressedAndReleased(BTN_SELECT_INDEX)){
			state = SELECT_MODE_RED;
			isInManual = 1;
			setTimerTriggerLed(DURATION_FOR_4HZ);
			setTimerScanFreq(DURATION_FOR_5HZ);
			clearTrafficDisplay();
			tempCounter = counter_red/DIVISION_NUMBER;
			update7SegBufferManual();
		}
		if(countDownTimer1_counter == 1){
			segment1Counter --;
			segment2Counter --;
			if (segment1Counter <= 0){
				segment1Counter = counter_yellow / DIVISION_NUMBER;
				state = AUTO_YELLOW1_RED2;
			}
			update7SegBufferAuto();
			setTimerCounter1(DURATION_1S);
		}

		break;
	case AUTO_YELLOW1_RED2:
		display7SegAuto(segmentIndexAuto);
		displayTrafficLight(YELLOW_LIGHT, RED_LIGHT);
		if(scanFreqTimer_flag == 1){
			update7SegBufferAuto();
			segmentIndexAuto++;
			if(segmentIndexAuto >= SEGMENT_IN_A_ROW) segmentIndexAuto = 0;
			setTimerScanFreq(DURATION_FOR_5HZ);
		}
		if(isPressedAndReleased(BTN_SELECT_INDEX)){
			state = SELECT_MODE_RED;
			isInManual = 1;
			setTimerTriggerLed(DURATION_FOR_4HZ);
			setTimerScanFreq(DURATION_FOR_5HZ);
			clearTrafficDisplay();
			tempCounter = counter_red/DIVISION_NUMBER;
			update7SegBufferManual();
		}
		if(countDownTimer1_counter == 1){
			segment1Counter --;
			segment2Counter --;
			if (segment1Counter <= 0){
				segment1Counter = counter_red / DIVISION_NUMBER;
				segment2Counter = counter_green / DIVISION_NUMBER;
				state = AUTO_RED1_GREEN2;
			}
			update7SegBufferAuto();
			setTimerCounter1(DURATION_1S);
		}

		break;
	default:
		break;
	}
}
