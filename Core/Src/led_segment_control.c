/*
 * led_segment_control.c
 *
 *  Created on: Nov 24, 2022
 *      Author: pmt12
 */


#include "led_segment_control.h"
#include "main.h"
#include "global.h"
#include "software_timer.h"

void display7Seg(int num){
	switch(num){
	case 0:
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, GPIO_PIN_SET);
		break;
	case 1:
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, GPIO_PIN_SET);
		break;
	case 2:
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, GPIO_PIN_RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, GPIO_PIN_RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, GPIO_PIN_RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, GPIO_PIN_RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, GPIO_PIN_RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, GPIO_PIN_SET);
		break;
	case 8:
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, GPIO_PIN_RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, GPIO_PIN_RESET);
		break;
	default:
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, GPIO_PIN_SET);
		break;
	}
}

void update7Seg(int index){
//	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
	switch(index){
	case 0:
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_SET);
		break;
	case 1:
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_SET);
		break;
	case 2:
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_SET);
		break;
	case 3:
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_RESET);
		break;
	default:
		break;
	}
	//display7Seg(led_buffer[index]);
}


void clearTrafficDisplay(){
	HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, GPIO_PIN_RESET);

	HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, GPIO_PIN_RESET);
}

void displayTrafficLight(int light1, int light2){
	switch(light1){
	case RED_LIGHT:
		HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, GPIO_PIN_RESET);
		break;
	case YELLOW_LIGHT:
		HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, GPIO_PIN_SET);
		break;
	case GREEN_LIGHT:
		HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, GPIO_PIN_RESET);
		break;
	}
	switch(light2){
	case RED_LIGHT:
		HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, GPIO_PIN_RESET);
		break;
	case YELLOW_LIGHT:
		HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, GPIO_PIN_SET);
		break;
	case GREEN_LIGHT:
		HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, GPIO_PIN_RESET);
		break;
	}
}

//void change7SegIndexInManual(){
//	segmentIndexManual++;
//	if(segmentIndexManual >= SEGMENT_IN_A_ROW) segmentIndexManual = 0;
//}
//void change7SegIndexInAuto(){
//	segmentIndexAuto++;
//	if(segmentIndexAuto >= MAX_LED_SEGMENT) segmentIndexAuto = 0;
//}
void update7SegBufferAuto(){
	if( segment1Counter < 10) led_buffer_auto[0] = 0;
	else led_buffer_auto[0] = segment1Counter / 10;
	led_buffer_auto[1] = segment1Counter % 10;
	if( segment2Counter < 10) led_buffer_auto[2] = 0;
	else led_buffer_auto[2] = segment2Counter / 10;
	led_buffer_auto[3] = segment2Counter % 10;
}
void update7SegBufferManual(){
	led_buffer_manual[0] = tempCounter / 10;
	led_buffer_manual[1] = tempCounter % 10;
}

void display7SegAuto(int index){
	switch(index){
	case 0:
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_SET);
		break;
	case 1:
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_SET);
		break;
	case 2:
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_SET);
		break;
	case 3:
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_RESET);
		break;
	default:
		break;
	}
	display7Seg(led_buffer_auto[index]);
}
void display7SegManual(int index){
	switch(index){
	case 0:
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_SET);
		break;
	case 1:
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_SET);
		break;
	default:
		break;
	}
	display7Seg(led_buffer_manual[index]);
}
void clear7Seg(){
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_SET);
}







