/*
 * IR_Sensor.h
 *
 *  Created on: Mar 25, 2021
 *      Author: Karim Hussein
 */

#ifndef IR_SENSOR_H_
#define IR_SENSOR_H_

typedef enum {Left_IR_Sensor , Right_IR_Sensor} IR_SENSOR;
typedef enum {LOGIC_ZERO = 0 , LOGIC_ONE = 1}IR_SENSOR_OUTPUT;

void IR_Sensor_Init(IR_SENSOR ir_sensor);
IR_SENSOR_OUTPUT IR_Sensor_Output(IR_SENSOR ir_sensor);

#endif /* IR_SENSOR_H_ */
