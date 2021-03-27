/*
 * RotarySwitchEncoder.c
 *
 *  Created on: Dec 29, 2020
 *      Author: Karim Hussein
 */


/*
 We use only single pin from encoder to know the speed
 We use External interrupt + timer to know the number of complete cycle
 https://www.youtube.com/watch?v=CpwGXZX-5Ug
*/

/*
 * Note That the timer counts from zero to TIMx_ARR then give Overflow Interrupt
 */

// Use TIMER1 For Switch Encoder & Use Input Capture unit to score rising edge

#include "RotarySwitchEncoder.h"
#include "GPIO.h"
#include "EXTI.h"
#include "Timer.h"

#define PI 3.141592
#define Wheel_Diameter 7 //cm

/*
 * Important Relations
 *
 * V = w x r
 * w = 2 * pi * N / 60
 * V = 2 * PI * N * R / 60
 *
 * Try to use Timer 1
 */

// Setting
#define EncoderPort PORTA
#define EncoderPin PIN2
#define Encoder_EXTI EXTI2
#define Encoder_Timer TIMER4

unsigned long RotarySwitchEncoder_counter = 0; // 32 Bit Variable
unsigned short velocity_counter=0;
unsigned short RPM = 0;
unsigned short velocity = 0;

void RotarySwitchEncoder_Event(void);
void RotarySwitchEncoder_Time(void);


void RotarySwitchEncoder_Init (void)
{
	GPIO_Init(EncoderPort);
	GPIO_PinDirection(EncoderPort ,EncoderPin,INPUT_PIN,Pull_Down);

	EXTI_Init(Encoder_EXTI , EncoderPort ,RISING_EDGE);
	EXTI_SetISR(Encoder_EXTI , RotarySwitchEncoder_Event);
	// External Interrupt Priority
	EXTI_Priority(Encoder_EXTI,LEVEL8);
	EXTI_Enable(Encoder_EXTI);

	Timer_Init(Encoder_Timer,8); // Tick Time --> 1 us
	Timer_SetISR(Encoder_Timer,RotarySwitchEncoder_Time);
	Timer_Enable(Encoder_Timer);
}

unsigned short RotarySwitchEncoder_GetRPM(void)
{
	return(RPM);
}

// CALLBACK Functions

void RotarySwitchEncoder_Event(void)
{
	if(!RotarySwitchEncoder_counter)
		Timer_InterruptEnable(Encoder_Timer);

	++RotarySwitchEncoder_counter;
	++velocity_counter;
}
void RotarySwitchEncoder_Time(void)
{
	static unsigned short flag = 0;
	if(RotarySwitchEncoder_counter)
	{
		++flag;
		if(!(flag%10)) // Get Velocity each 100ms
		{
			//(v) =   (r) ( 2 x pi x N / 60 ) --> Wheel Diameter is 7 Cm
			velocity =  Wheel_Diameter * PI *  ((float)velocity_counter/500.0) * 10; // (cm/s)
			velocity_counter = 0;
		}
		if (flag == 6000) // for one minute calculation
		{
			Timer_Disable(Encoder_Timer);
			RPM = RotarySwitchEncoder_counter / 500;
			RotarySwitchEncoder_counter = 0;
			flag = 0;
		}
	}
}

unsigned short Car_velocity(void)
{
	return(velocity);
}
