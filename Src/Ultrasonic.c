/*
 * Ultrasonic.c
 *
 *  Created on: Dec 25, 2020
 *      Author: Karim Hussein
 */


#include "GPIO.h"
#include "Timer.h"
#include "Ultrasonic.h"

#define ULTRASONIC1_TIMER TIMER3
#define ULTRASONIC2_TIMER TIMER2

#define TRIGGER1_PORT PORTA
#define TRIGGER1_PIN  PIN1
#define TRIGGER2_PORT PORTA
#define TRIGGER2_PIN  PIN2
#define TRIGGER3_PORT PORTA
#define TRIGGER3_PIN  PIN3
#define TRIGGER4_PORT PORTA
#define TRIGGER4_PIN  PIN4

unsigned short Ultrasonic1_Reading = 0;
unsigned short Ultrasonic2_Reading = 0;
unsigned short Ultrasonic3_Reading = 0;
unsigned short Ultrasonic4_Reading = 0;

unsigned short Ultrasonic1_Finish = 1;
unsigned short Ultrasonic2_Finish = 1;
unsigned short Ultrasonic3_Finish = 1;
unsigned short Ultrasonic4_Finish = 1;


void Ultrasonic (void);

void Ultrasonic_Init(ULTRASONIC_SENSOR ultrasonic_sensor)
{
	switch(ultrasonic_sensor)
	{
		case FRONT_ULTRASONIC:
			// Trigger Port Initialization
			GPIO_Init(TRIGGER1_PORT);
			// Trigger Pin Configuration
			GPIO_PinDirection(TRIGGER1_PORT ,TRIGGER1_PIN ,OUTPUT_PIN , Open_Drain);
			GPIO_PinWrite(TRIGGER1_PORT,TRIGGER1_PIN,PIN_LOW);

			// Timer Setting
			Timer_Init (ULTRASONIC1_TIMER,8); // Tick time --> 1 us

			Timer_ActivateICU(ULTRASONIC1_TIMER, CHANNEL0 ,RISING_EDGE_CAPTURE);
			Timer_ActivateICU(ULTRASONIC1_TIMER, CHANNEL1 ,FALLING_EDGE_CAPTURE);

			// Try to replace this part by DMA & execute analysis in the main
			Timer_SetISR(ULTRASONIC1_TIMER,Ultrasonic);

			Timer_ActivateICUInterrupt(ULTRASONIC1_TIMER, CHANNEL1);

		    Timer_Enable(ULTRASONIC1_TIMER);
			break;
		case BACK_ULTRASONIC:
			// Trigger Port Initialization
			GPIO_Init(TRIGGER2_PORT);
			// Trigger Pin Configuration
			GPIO_PinDirection(TRIGGER2_PORT ,TRIGGER2_PIN ,OUTPUT_PIN , Open_Drain);
			GPIO_PinWrite(TRIGGER2_PORT,TRIGGER2_PIN,PIN_LOW);

			// Timer Setting
			Timer_Init (ULTRASONIC1_TIMER,8); // Tick time --> 1 us

			Timer_ActivateICU(ULTRASONIC1_TIMER, CHANNEL2 ,RISING_EDGE_CAPTURE);
			Timer_ActivateICU(ULTRASONIC1_TIMER, CHANNEL3 ,FALLING_EDGE_CAPTURE);

			// Try to replace this part by DMA & execute analysis in the main
			Timer_SetISR(ULTRASONIC1_TIMER,Ultrasonic);

			Timer_ActivateICUInterrupt(ULTRASONIC1_TIMER, CHANNEL3);

		    Timer_Enable(ULTRASONIC1_TIMER);
			break;
		case UPPER_RIGHT_ULTRASONIC:
			// Trigger Port Initialization
			GPIO_Init(TRIGGER3_PORT);
			// Trigger Pin Configuration
			GPIO_PinDirection(TRIGGER3_PORT ,TRIGGER3_PIN ,OUTPUT_PIN , Open_Drain);
			GPIO_PinWrite(TRIGGER3_PORT,TRIGGER3_PIN,PIN_LOW);

			// Timer Setting
			Timer_Init (ULTRASONIC2_TIMER,8); // Tick time --> 1 us

			Timer_ActivateICU(ULTRASONIC2_TIMER, CHANNEL0 ,RISING_EDGE_CAPTURE);
			Timer_ActivateICU(ULTRASONIC2_TIMER, CHANNEL1 ,FALLING_EDGE_CAPTURE);

			// Try to replace this part by DMA & execute analysis in the main
			Timer_SetISR(ULTRASONIC2_TIMER,Ultrasonic);

			Timer_ActivateICUInterrupt(ULTRASONIC2_TIMER, CHANNEL1);

		    Timer_Enable(ULTRASONIC2_TIMER);
			break;
		case LOWER_RIGHT_ULTRASONIC:
			// Trigger Port Initialization
			GPIO_Init(TRIGGER4_PORT);
			// Trigger Pin Configuration
			GPIO_PinDirection(TRIGGER4_PORT ,TRIGGER4_PIN ,OUTPUT_PIN , Open_Drain);
			GPIO_PinWrite(TRIGGER4_PORT,TRIGGER4_PIN,PIN_LOW);

			// Timer Setting
			Timer_Init (ULTRASONIC2_TIMER,8); // Tick time --> 1 us

			Timer_ActivateICU(ULTRASONIC2_TIMER, CHANNEL2 ,RISING_EDGE_CAPTURE);
			Timer_ActivateICU(ULTRASONIC2_TIMER, CHANNEL3 ,FALLING_EDGE_CAPTURE);

			// Try to replace this part by DMA & execute analysis in the main
			Timer_SetISR(ULTRASONIC2_TIMER,Ultrasonic);

			Timer_ActivateICUInterrupt(ULTRASONIC2_TIMER, CHANNEL3);

		    Timer_Enable(ULTRASONIC2_TIMER);
			break;
		default:
			break;
	}
}
void Ultrasonic_Start(ULTRASONIC_SENSOR ultrasonic_sensor)
{
	// I think we need to work sequentially
	switch(ultrasonic_sensor)
	{
		case FRONT_ULTRASONIC:
			if (Ultrasonic1_Finish)
			{
				Ultrasonic1_Finish = 0;

			    GPIO_PinWrite(TRIGGER1_PORT,TRIGGER1_PIN,PIN_HIGH);

			    // increase this time for more stability (1000 is good)
			    for(int i=0;i<1000;i++)
			    	asm("NOP");

			    GPIO_PinWrite(TRIGGER1_PORT,TRIGGER1_PIN,PIN_LOW);
			}
			break;
		case BACK_ULTRASONIC:
			if (Ultrasonic2_Finish)
			{
				Ultrasonic2_Finish = 0;

			    GPIO_PinWrite(TRIGGER2_PORT,TRIGGER2_PIN,PIN_HIGH);

			    // increase this time for more stability
			    for(int i=0;i<1000;i++)
			    	asm("NOP");

			    GPIO_PinWrite(TRIGGER2_PORT,TRIGGER2_PIN,PIN_LOW);
			}
			break;
		case UPPER_RIGHT_ULTRASONIC:
			if (Ultrasonic3_Finish)
			{
				Ultrasonic3_Finish = 0;

			    GPIO_PinWrite(TRIGGER3_PORT,TRIGGER3_PIN,PIN_HIGH);

			    // increase this time for more stability
			    for(int i=0;i<1000;i++)
			    	asm("NOP");

			    GPIO_PinWrite(TRIGGER3_PORT,TRIGGER3_PIN,PIN_LOW);
			}
			break;
		case LOWER_RIGHT_ULTRASONIC:
			if (Ultrasonic4_Finish)
			{
				Ultrasonic4_Finish = 0;

			    GPIO_PinWrite(TRIGGER4_PORT,TRIGGER4_PIN,PIN_HIGH);

			    // increase this time for more stability
			    for(int i=0;i<1000;i++)
			    	asm("NOP");

			    GPIO_PinWrite(TRIGGER4_PORT,TRIGGER4_PIN,PIN_LOW);
			}
			break;
		default:
			break;
	}
}
unsigned short Ultrasonic_Time(ULTRASONIC_SENSOR ultrasonic_sensor)
{

	switch(ultrasonic_sensor)
	{
		case FRONT_ULTRASONIC:
			return(Ultrasonic1_Reading * 0.017);
			break;
		case BACK_ULTRASONIC:
			return(Ultrasonic2_Reading * 0.017);
			break;
		case UPPER_RIGHT_ULTRASONIC:
			return(Ultrasonic3_Reading * 0.017);
			break;
		case LOWER_RIGHT_ULTRASONIC:
			return(Ultrasonic4_Reading * 0.017);
			break;
		default:
			break;
	}
}

// Try to insert overflow code here
void Ultrasonic (void)
{
	unsigned short X1 = 0 , X2 = 0;
	if (!Ultrasonic1_Finish)
	{
		Ultrasonic1_Finish = 1;
		X1 = Timer_GetICU_Value(ULTRASONIC1_TIMER ,CHANNEL0);
		X2 = Timer_GetICU_Value(ULTRASONIC1_TIMER ,CHANNEL1);

		if (X2 > X1)
		{
			Ultrasonic1_Reading = X2 - X1;
		}
		else
		{
			Ultrasonic1_Reading = X2 + (0xFFFF - X1);
		}
	}
	if (!Ultrasonic2_Finish)
	{
		Ultrasonic2_Finish = 1;
		X1 = Timer_GetICU_Value(ULTRASONIC1_TIMER ,CHANNEL2);
		X2 = Timer_GetICU_Value(ULTRASONIC1_TIMER ,CHANNEL3);

		if (X2 > X1)
		{
			Ultrasonic2_Reading = X2 - X1;
		}
		else
		{
			Ultrasonic2_Reading = X2 + (0xFFFF - X1);
		}
	}
	if (!Ultrasonic3_Finish)
	{
		Ultrasonic3_Finish = 1;
		X1 = Timer_GetICU_Value(ULTRASONIC2_TIMER ,CHANNEL0);
		X2 = Timer_GetICU_Value(ULTRASONIC2_TIMER ,CHANNEL1);

		if (X2 > X1)
		{
			Ultrasonic3_Reading = X2 - X1;
		}
		else
		{
			Ultrasonic3_Reading = X2 + (0xFFFF - X1);
		}
	}
	if (!Ultrasonic4_Finish)
	{
		Ultrasonic4_Finish = 1;
		X1 = Timer_GetICU_Value(ULTRASONIC2_TIMER ,CHANNEL2);
		X2 = Timer_GetICU_Value(ULTRASONIC2_TIMER ,CHANNEL3);

		if (X2 > X1)
		{
			Ultrasonic4_Reading = X2 - X1;
		}
		else
		{
			Ultrasonic4_Reading = X2 + (0xFFFF - X1);
		}
	}
}
