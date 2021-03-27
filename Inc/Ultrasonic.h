/*
 * Ultrasonic.h
 *
 *  Created on: Dec 25, 2020
 *      Author: Karim Hussein
 */

/**
 *  Connect Echo pin to PA0 (External interrupt 0)(PORTA)
 */


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

typedef enum {FRONT_ULTRASONIC , BACK_ULTRASONIC , UPPER_RIGHT_ULTRASONIC , LOWER_RIGHT_ULTRASONIC}ULTRASONIC_SENSOR;

void Ultrasonic_Init(ULTRASONIC_SENSOR ultrasonic_sensor);
void Ultrasonic_Start(ULTRASONIC_SENSOR ultrasonic_sensor);
unsigned short Ultrasonic_Time(ULTRASONIC_SENSOR ultrasonic_sensor);


#endif /* ULTRASONIC_H_ */

