/*
 * DC_MOTOR.h
 *
 *  Created on: Dec 26, 2020
 *      Author: Karim Hussein
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_


typedef enum {
	Forward, Backward , Left , Right
}Car_Dir;

typedef enum {
	GO , STOP
}Car_State;

void Car_Init(void);
void Car_Drive(Car_State car_state,Car_Dir car_dir,unsigned short dutycycle);

#endif /* DC_MOTOR_H_ */

