/*
 * Timer0.h
 *
 *  Created on: Dec 18, 2020
 *      Author: Karim Hussein
 */

/*
 *
 *  TMR2:TMR4 (we have only three general purpose timers in stm32f103ctg8)
  We Need PWM + Overflow interrupt

  Counter Enable Bit CEN in TIMx_CR1
  CNT_EN --> Actual counter register Enable (needs 1 clk after CEN is set to be set)

  Counting Mode --> Upcounting mode
  in upcounting mode --> the counter counts from 0 to TIMx_ARR register value
 *  Clock Selection ---> you must work in slave mode SMS 00
 *
 */

#ifndef TIMER_H_
#define TIMER_H_

typedef enum { TIMER1 , TIMER2 , TIMER3 , TIMER4 }TIMER;
typedef enum {CHANNEL0 , CHANNEL1 , CHANNEL2 , CHANNEL3}TIMER_CHANNEL;
typedef enum {RISING_EDGE_CAPTURE , FALLING_EDGE_CAPTURE , BOTH_EDGES_CAPTURE}CAPTURE_MODE;

// Recall the  external clock is 8 MHz  && internal clock is also 8 MHz

void Timer_Init (TIMER timer,unsigned short Prescaler); // you must know tick time from here
void Timer_Enable(TIMER timer);
void Timer_Disable(TIMER timer);
void Timer_Load(TIMER timer ,unsigned short val);
unsigned short Timer_Data(TIMER timer);
void Timer_SetISR(TIMER timer,void (*ptr)(void));
void Timer_InterruptEnable(TIMER timer);
unsigned char Timer_Status(TIMER timer);
unsigned char Timer_InterruptStatus(TIMER timer);


// from here
void Timer_ActivatePWM(TIMER timer,TIMER_CHANNEL timer_channel,unsigned short period,unsigned short duty_cycle);
void Timer_ActivatePWMInterrupt(TIMER timer , TIMER_CHANNEL timer_channel);
void Timer_DeactivatePWM(TIMER timer);
void Timer_DeactivatePWMInterrupt(TIMER timer , TIMER_CHANNEL timer_channel);
void Timer_PWMDutyCycle(TIMER timer,TIMER_CHANNEL timer_channel,unsigned short duty_cycle);
unsigned short Timer_GetDutyCycle(TIMER timer, TIMER_CHANNEL timer_channel) ;

void Timer_ActivateICU(TIMER timer, TIMER_CHANNEL timer_channel,CAPTURE_MODE capture_mode);
void Timer_ActivateICUInterrupt(TIMER timer, TIMER_CHANNEL timer_channel);
unsigned short Timer_GetICU_Value(TIMER timer , TIMER_CHANNEL timer_channel);


unsigned char Timer_CaptureUnits_Flags (TIMER timer , TIMER_CHANNEL timer_channel);

#endif /* TIMER0_H_ */
