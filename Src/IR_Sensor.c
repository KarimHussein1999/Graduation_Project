/*
 * IR_Sensor.c
 *
 *  Created on: Mar 25, 2021
 *      Author: Karim Hussein
 */

#include "EXTI.h"
#include "GPIO.h"
#include "IR_Sensor.h"

#define Left_IR_Sensor_PORT  PORTA
#define Right_IR_Sensor_PORT PORTA

#define Left_IR_Sensor_PIN  PIN4
#define Right_IR_Sensor_PIN PIN5


// when there is object it gives you LOW Logic 0V

void IR_Sensor_Init(IR_SENSOR ir_sensor)
{
	switch(ir_sensor)
	{
		case Left_IR_Sensor:
			GPIO_Init(Left_IR_Sensor_PORT);
			GPIO_PinDirection(Left_IR_Sensor_PORT,Left_IR_Sensor_PIN,INPUT_PIN,Floating);// Try Pull Up Mode
			break;
		case Right_IR_Sensor:
			GPIO_Init(Right_IR_Sensor_PORT);
			GPIO_PinDirection(Right_IR_Sensor_PORT,Right_IR_Sensor_PIN,INPUT_PIN,Floating);// Try Pull Up Mode
			break;
		default:
			break;
	}
}

IR_SENSOR_OUTPUT IR_Sensor_Output(IR_SENSOR ir_sensor)
{
	switch(ir_sensor)
	{
		case Left_IR_Sensor:
			return(GPIO_PinRead(Left_IR_Sensor_PORT,Left_IR_Sensor_PIN));
			break;
		case Right_IR_Sensor:
			return(GPIO_PinRead(Left_IR_Sensor_PORT,Right_IR_Sensor_PIN));
			break;
		default:break;
	}
}
