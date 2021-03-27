/*
 * DC_MOTOR.c
 *
 *  Created on: Dec 26, 2020
 *      Author: Karim Hussein
 */


// create function to drive the car (Turn Left - Right - Up - Down)
// use the four channels of the timer to control two motors in two directions

#include "DC_MOTOR.h"
#include "Timer.h"

// Setting --> Freq 100 Hz
#define DC_MOTOR_TIMER TIMER4
#define DC_MOTOR1_CHANNEL1 CHANNEL0 //PB6
#define DC_MOTOR1_CHANNEL2 CHANNEL1 //PB7
#define DC_MOTOR2_CHANNEL1 CHANNEL2
#define DC_MOTOR2_CHANNEL2 CHANNEL3

// 100 Hz frequency
#define PERIOD 10000
#define DUTY_CYCLE 500
#define GND 0 // test this value


// we use 8 MHz External Crystal & Prescaler 8

void Car_Init()
{
	Timer_Init (DC_MOTOR_TIMER,8); // 1 MHz
	Timer_ActivatePWM(DC_MOTOR_TIMER,DC_MOTOR1_CHANNEL1,PERIOD,DUTY_CYCLE);
	Timer_ActivatePWM(DC_MOTOR_TIMER,DC_MOTOR1_CHANNEL2,PERIOD,GND);
	Timer_ActivatePWM(DC_MOTOR_TIMER,DC_MOTOR2_CHANNEL1,PERIOD,DUTY_CYCLE);
	Timer_ActivatePWM(DC_MOTOR_TIMER,DC_MOTOR2_CHANNEL2,PERIOD,GND);
	if(!(Timer_Status(DC_MOTOR_TIMER)))
		Timer_Enable(DC_MOTOR_TIMER);
}

void Car_Drive(Car_State car_state,Car_Dir car_dir,unsigned short dutycycle)
{
	if(car_state == STOP)
	{
		Timer_PWMDutyCycle(DC_MOTOR_TIMER,DC_MOTOR1_CHANNEL1,GND);
		Timer_PWMDutyCycle(DC_MOTOR_TIMER,DC_MOTOR1_CHANNEL2,GND);
		Timer_PWMDutyCycle(DC_MOTOR_TIMER,DC_MOTOR2_CHANNEL1,GND);
		Timer_PWMDutyCycle(DC_MOTOR_TIMER,DC_MOTOR2_CHANNEL2,GND);
	}
	else if (car_state == GO)
	{
		switch(car_dir)
		{
			case Forward:
				Timer_PWMDutyCycle(DC_MOTOR_TIMER,DC_MOTOR1_CHANNEL1,dutycycle);
				Timer_PWMDutyCycle(DC_MOTOR_TIMER,DC_MOTOR1_CHANNEL2,GND);
				Timer_PWMDutyCycle(DC_MOTOR_TIMER,DC_MOTOR2_CHANNEL1,dutycycle);
				Timer_PWMDutyCycle(DC_MOTOR_TIMER,DC_MOTOR2_CHANNEL2,GND);
				break;
			case Backward:
				Timer_PWMDutyCycle(DC_MOTOR_TIMER,DC_MOTOR1_CHANNEL1,GND);
				Timer_PWMDutyCycle(DC_MOTOR_TIMER,DC_MOTOR1_CHANNEL2,dutycycle);
				Timer_PWMDutyCycle(DC_MOTOR_TIMER,DC_MOTOR2_CHANNEL1,GND);
				Timer_PWMDutyCycle(DC_MOTOR_TIMER,DC_MOTOR2_CHANNEL2,dutycycle);
				break;
			case Left:
				Timer_PWMDutyCycle(DC_MOTOR_TIMER,DC_MOTOR1_CHANNEL1,dutycycle);
				Timer_PWMDutyCycle(DC_MOTOR_TIMER,DC_MOTOR1_CHANNEL2,GND);
				Timer_PWMDutyCycle(DC_MOTOR_TIMER,DC_MOTOR2_CHANNEL1,GND);
				Timer_PWMDutyCycle(DC_MOTOR_TIMER,DC_MOTOR2_CHANNEL2,GND);
				break;
			case Right:
				Timer_PWMDutyCycle(DC_MOTOR_TIMER,DC_MOTOR1_CHANNEL1,GND);
				Timer_PWMDutyCycle(DC_MOTOR_TIMER,DC_MOTOR1_CHANNEL2,GND);
				Timer_PWMDutyCycle(DC_MOTOR_TIMER,DC_MOTOR2_CHANNEL1,dutycycle);
				Timer_PWMDutyCycle(DC_MOTOR_TIMER,DC_MOTOR2_CHANNEL2,GND);
				break;
			default:break;
		}
	}
}
