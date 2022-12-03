/*
 * global.h
 *
 *  Created on: Nov 23, 2022
 *      Author: pmt12
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define DEFAULT_RED_DURATION			5000
#define DEFAULT_YELLOW_DURATION			2000
#define DEFAULT_GREEN_DURATION			3000

#define DURATION_1S						1000
#define DURATION_3S						3000

#define RED_LIGHT						1
#define YELLOW_LIGHT					2
#define GREEN_LIGHT						3

#define MAX_SEGMENT_VALUE				99
#define DURATION_FOR_4HZ				250

enum TRAFFIC_STATE	{IDLE, AUTO_RED1_GREEN2, AUTO_RED1_YELLOW2,
					AUTO_GREEN1_RED2, AUTO_YELLOW1_RED2, SELECT_MODE_RED,
					SELECT_MODE_YELLOW, SELECT_MODE_GREEN, MODIFY_PRESSED,
					MODIFY_LONGPRESSED, SET_PRESSED};
extern enum TRAFFIC_STATE state;

extern int counter_red;
extern int counter_yellow;
extern int counter_green;

extern int isInManual;
extern int isRedMode;
extern int isYellowMode;
extern int isGreenMode;

extern int wasInModify;

extern int tempCounter;


#endif /* INC_GLOBAL_H_ */
