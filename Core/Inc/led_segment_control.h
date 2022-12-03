/*
 * led_segment_control.h
 *
 *  Created on: Nov 24, 2022
 *      Author: pmt12
 */

#ifndef INC_LED_SEGMENT_CONTROL_H_
#define INC_LED_SEGMENT_CONTROL_H_

void display7Seg(int num);
void update7SEG(int index);
void updateSegmentBuffer();
void displayTrafficLight(int light1, int light2);
void clearTrafficDisplay();
#endif /* INC_LED_SEGMENT_CONTROL_H_ */
