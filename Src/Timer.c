/*
 * Timer0.c
 *
 *  Created on: Dec 18, 2020
 *      Author: Karim Hussein
 */



#include "Timer.h"
#include "util.h"
#include "Regmap.h"
#include "GPIO.h"



void Timer_Init (TIMER timer,unsigned short Prescaler)
{
	switch(timer)
	{
		case TIMER1:
			// Connect Clock to GPIOA
			if(!GetBit(RCC_APB2ENR,2))
				SetBit(RCC_APB2ENR,2);

			// Connect Clock to TMR1
			SetBit(RCC_APB2ENR,11);
			//Up Count
			ClrBit(TIM1_CR1,4);
			ClrBit(TIM1_CR1,5);
			ClrBit(TIM1_CR1,6);
			//Only counter Overflow/Underflow generates interrupt
			SetBit(TIM1_CR1,2);
			ClrBit(TIM1_CR1,1);
			//Disable Slave Mode
			ClrBit(TIM1_SMCR,0);
			ClrBit(TIM1_SMCR,1);
			ClrBit(TIM1_SMCR,2);
			//Timer Prescaler
			TIM1_PSC = Prescaler-1;
			SetBit(NVIC_ISER0,25);
			break;
		case TIMER2:
			// Connect Clock to GPIOA
			if(!GetBit(RCC_APB2ENR,2))
				SetBit(RCC_APB2ENR,2);

			// Connect Clock to TMR2
			SetBit(RCC_APB1ENR,0);
			//Up Count
			ClrBit(TIM2_CR1,4);
			ClrBit(TIM2_CR1,5);
			ClrBit(TIM2_CR1,6);
			//Only counter Overflow/Underflow generates interrupt
			SetBit(TIM2_CR1,2);
			ClrBit(TIM2_CR1,1);
			//Disable Slave Mode
			ClrBit(TIM2_SMCR,0);
			ClrBit(TIM2_SMCR,1);
			ClrBit(TIM2_SMCR,2);
			//Timer Prescaler
			TIM2_PSC = Prescaler-1;
			SetBit(NVIC_ISER0,28);
			break;
		case TIMER3:
			// Connect Clock to GPIOA
			if(!GetBit(RCC_APB2ENR,2))
				SetBit(RCC_APB2ENR,2);
			// Connect Clock to GPIOB
			if(!GetBit(RCC_APB2ENR,3))
				SetBit(RCC_APB2ENR,3);
			// Connect Clock to TMR3
			SetBit(RCC_APB1ENR,1);
			//Up Count
			ClrBit(TIM3_CR1,4);
			ClrBit(TIM3_CR1,5);
			ClrBit(TIM3_CR1,6);
			//Only counter Overflow/Underflow generates interrupt
			SetBit(TIM3_CR1,2);
			ClrBit(TIM3_CR1,1);
			//Disable Slave Mode
			ClrBit(TIM3_SMCR,0);
			ClrBit(TIM3_SMCR,1);
			ClrBit(TIM3_SMCR,2);
			//Timer Prescaler
			TIM3_PSC = Prescaler-1;
			SetBit(NVIC_ISER0,29);
			break;
		case TIMER4:
			// Connect Clock to GPIOB
			if(!GetBit(RCC_APB2ENR,3))
				SetBit(RCC_APB2ENR,3);

			// Connect Clock to TMR4
			SetBit(RCC_APB1ENR,2);
			//Up Count
			ClrBit(TIM4_CR1,4);
			ClrBit(TIM4_CR1,5);
			ClrBit(TIM4_CR1,6);
			//Only counter Overflow/Underflow generates interrupt
			SetBit(TIM4_CR1,2);
			ClrBit(TIM4_CR1,1);
			//Disable Slave Mode
			ClrBit(TIM4_SMCR,0);
			ClrBit(TIM4_SMCR,1);
			ClrBit(TIM4_SMCR,2);
			//Timer Prescaler
			TIM4_PSC = Prescaler-1;
			SetBit(NVIC_ISER0,30);
			break;
		default:break;
	}
}

unsigned char Timer_Status(TIMER timer)
{
	switch(timer)
	{
		case TIMER1:
			return(GetBit(TIM1_CR1,0));
		case TIMER2:
			return(GetBit(TIM2_CR1,0));
			break;
		case TIMER3:
			return (GetBit(TIM3_CR1,0));
			break;
		case TIMER4:
			return (SetBit(TIM4_CR1,0));
			break;
	}
}

unsigned char Timer_InterruptStatus(TIMER timer)
{
	switch(timer)
	{
		case TIMER1:
			return(GetBit(TIM1_SR,0));
			break;
		case TIMER2:
			return(GetBit(TIM2_SR,0));
			break;
		case TIMER3:
			return (GetBit(TIM3_SR,0));
			break;
		case TIMER4:
			return (SetBit(TIM4_SR,0));
			break;
	}
}

void Timer_Enable(TIMER timer)
{
	switch(timer)
	{
		case TIMER1:
			SetBit(TIM1_CR1,0);
			break;
		case TIMER2:
			SetBit(TIM2_CR1,0);
			break;
		case TIMER3:
			SetBit(TIM3_CR1,0);
			break;
		case TIMER4:
			SetBit(TIM4_CR1,0);
			break;
	}
}
void Timer_Disable(TIMER timer)
{
	switch(timer)
	{
		case TIMER1:
			ClrBit(TIM1_CR1,0);
			break;
		case TIMER2:
			ClrBit(TIM2_CR1,0);
			break;
		case TIMER3:
			ClrBit(TIM3_CR1,0);
			break;
		case TIMER4:
			ClrBit(TIM4_CR1,0);
			break;
	}
}

unsigned short Timer_Data(TIMER timer)
{
	switch(timer)
	{
		case TIMER1:
			return(TIM2_CNT);
			break;
		case TIMER2:
			return(TIM2_CNT);
			break;
		case TIMER3:
			return(TIM3_CNT);
			break;
		case TIMER4:
			return(TIM4_CNT);
			break;
	}
}

void Timer_Load(TIMER timer ,unsigned short val)
{
	switch(timer)
	{
		case TIMER1:
			TIM1_CNT = val;
			break;
		case TIMER2:
			TIM2_CNT = val;
			break;
		case TIMER3:
			TIM3_CNT = val;
			break;
		case TIMER4:
			TIM4_CNT = val;
			break;
	}
}

void (*TIMER1_ISR)(void) = 0;
void (*TIMER2_ISR)(void) = 0;
void (*TIMER3_ISR)(void) = 0;
void (*TIMER4_ISR)(void) = 0;


void Timer_SetISR(TIMER timer,void (*ptr)(void))
{
	switch(timer)
	{
		case TIMER1:
			TIMER1_ISR = ptr;
			break;
		case TIMER2:
			TIMER2_ISR = ptr;
			break;
		case TIMER3:
			TIMER3_ISR = ptr;
			break;
		case TIMER4:
			TIMER4_ISR = ptr;
			break;
	}
}

void Timer_InterruptEnable(TIMER timer)
{
	switch(timer)
	{
	case TIMER1:
		ClrBit(TIM1_SR,0);
		SetBit(TIM1_DIER,0);
		break;
	case TIMER2:
		ClrBit(TIM2_SR,0);
		SetBit(TIM2_DIER,0);
		break;
	case TIMER3:
		ClrBit(TIM3_SR,0);
		SetBit(TIM3_DIER,0);
		break;
	case TIMER4:
		ClrBit(TIM4_SR,0);
		SetBit(TIM4_DIER,0);
		break;
	}
}

void Timer_InterruptDisable(TIMER timer)
{
	switch(timer)
	{
	case TIMER1:
		ClrBit(TIM1_DIER,0);
		break;
	case TIMER2:
		ClrBit(TIM2_DIER,0);
		break;
	case TIMER3:
		ClrBit(TIM3_DIER,0);
		break;
	case TIMER4:
		ClrBit(TIM4_DIER,0);
		break;
	}
}



void Timer_PWMDutyCycle(TIMER timer,TIMER_CHANNEL timer_channel,unsigned short duty_cycle)
{
	switch(timer)
	{
	case TIMER1:
		switch(timer_channel)
		{
		case CHANNEL0:
			TIM1_CCR1 = duty_cycle;
			break;
		case CHANNEL1:
			TIM1_CCR2 = duty_cycle;
			break;
		case CHANNEL2:
			TIM1_CCR3 = duty_cycle;
			break;
		case CHANNEL3:
			TIM1_CCR4 = duty_cycle;
			break;
		}
		break;
	case TIMER2:
		switch(timer_channel)
		{
		case CHANNEL0:
			TIM2_CCR1 = duty_cycle;
			break;
		case CHANNEL1:
			TIM2_CCR2 = duty_cycle;
			break;
		case CHANNEL2:
			TIM2_CCR3 = duty_cycle;
			break;
		case CHANNEL3:
			TIM2_CCR4 = duty_cycle;
			break;
		}
		break;
	case TIMER3:
		switch(timer_channel)
		{
		case CHANNEL0:
			TIM3_CCR1 = duty_cycle;
			break;
		case CHANNEL1:
			TIM3_CCR2 = duty_cycle;
			break;
		case CHANNEL2:
			TIM3_CCR3 = duty_cycle;
			break;
		case CHANNEL3:
			TIM3_CCR4 = duty_cycle;
			break;
		}
		break;
	case TIMER4:
		switch(timer_channel)
		{
		case CHANNEL0:
			TIM4_CCR1 = duty_cycle;
			break;
		case CHANNEL1:
			TIM4_CCR2 = duty_cycle;
			break;
		case CHANNEL2:
			TIM4_CCR3 = duty_cycle;
			break;
		case CHANNEL3:
			TIM4_CCR4 = duty_cycle;
			break;
		}
		break;
	}
}

unsigned short Timer_GetDutyCycle(TIMER timer , TIMER_CHANNEL timer_channel)
{
	switch(timer)
	{
		case TIMER1:
			switch(timer_channel)
			{
			case CHANNEL0:
				return(TIM1_CCR1);
				break;
			case CHANNEL1:
				return(TIM1_CCR2);
				break;
			case CHANNEL2:
				return(TIM1_CCR3);
				break;
			case CHANNEL3:
				return(TIM1_CCR4);
				break;
			}
			break;
		case TIMER2:
			switch(timer_channel)
			{
			case CHANNEL0:
				return(TIM2_CCR1);
				break;
			case CHANNEL1:
				return(TIM2_CCR2);
				break;
			case CHANNEL2:
				return(TIM2_CCR3);
				break;
			case CHANNEL3:
				return(TIM2_CCR4);
				break;
			}
			break;
		case TIMER3:
			switch(timer_channel)
			{
			case CHANNEL0:
				return(TIM3_CCR1);
				break;
			case CHANNEL1:
				return(TIM3_CCR2);
				break;
			case CHANNEL2:
				return(TIM3_CCR3);
				break;
			case CHANNEL3:
				return(TIM3_CCR4);
				break;
			}
			break;
		case TIMER4:
			switch(timer_channel)
			{
			case CHANNEL0:
				return(TIM4_CCR1);
				break;
			case CHANNEL1:
				return(TIM4_CCR2);
				break;
			case CHANNEL2:
				return(TIM4_CCR3);
				break;
			case CHANNEL3:
				return(TIM4_CCR4);
				break;
			}
			break;
	}
}

void Timer_ActivatePWM(TIMER timer,TIMER_CHANNEL timer_channel,unsigned short period,unsigned short duty_cycle)
{
	// by default DIR is Upcounting from 0 to TIMx_ARR
	switch(timer)
	{
		case TIMER2:
			// Store the signal period in TIMx_ARR
			TIM2_ARR = period; // - 1
			// Store the signal duty cycle in TIMx_CCRx
			// if TIMx_CCRx < TIMx_CNT --> Channel inactive
			switch(timer_channel)
			{
				case CHANNEL0:
					TIM2_CCR1 = duty_cycle - 1;
					// GPIO Configuration(AF PP)
					SetBit(GPIOA_CRL,3);
					ClrBit(GPIOA_CRL,2);
					SetBit(GPIOA_CRL,1);
					ClrBit(GPIOA_CRL,0);
					// Choose pin direction
					ClrBit(TIM2_CCMR1,0);
					ClrBit(TIM2_CCMR1,1);
					// Choose the PWM mode for the chosen timer channel
					SetBit(TIM2_CCMR1,6);
					SetBit(TIM2_CCMR1,5);
					ClrBit(TIM2_CCMR1,4);
					// Enable the preload register (OCxPE bit in TIMx_CCRx)
					SetBit(TIM2_CCMR1,3);
					// Polarity Configuration (CCxP bit in TIMx_CCER)
					ClrBit(TIM2_CCER,1);
					// Enable OCx output  (CCxE bit in TIMx_CCER)
					SetBit(TIM2_CCER,0);
					break;
				case CHANNEL1:
					TIM2_CCR2 = duty_cycle - 1;
					// GPIO Configuration(AF PP)
					SetBit(GPIOA_CRL,7);
					ClrBit(GPIOA_CRL,6);
					SetBit(GPIOA_CRL,5);
					ClrBit(GPIOA_CRL,4);
					// Choose pin direction
					ClrBit(TIM2_CCMR1,8);
					ClrBit(TIM2_CCMR1,9);
					// Choose the PWM mode for the chosen timer channel
					SetBit(TIM2_CCMR1,14);
					SetBit(TIM2_CCMR1,13);
					ClrBit(TIM2_CCMR1,12);
					// Enable the preload register (OCxPE bit in TIMx_CCRx)
					SetBit(TIM2_CCMR1,11);
					// Polarity Configuration (CCxP bit in TIMx_CCER)
					ClrBit(TIM2_CCER,5);
					// Enable OCx output  (CCxE bit in TIMx_CCER)
					SetBit(TIM2_CCER,4);
					break;
				case CHANNEL2:
					TIM2_CCR3 = duty_cycle - 1;
					// GPIO Configuration(AF PP)
					SetBit(GPIOA_CRL,11);
					ClrBit(GPIOA_CRL,10);
					SetBit(GPIOA_CRL,9);
					ClrBit(GPIOA_CRL,8);
					// Choose pin direction
					ClrBit(TIM2_CCMR2,0);
					ClrBit(TIM2_CCMR2,1);
					// Choose the PWM mode for the chosen timer channel
					SetBit(TIM2_CCMR2,6);
					SetBit(TIM2_CCMR2,5);
					ClrBit(TIM2_CCMR2,4);
					// Enable the preload register (OCxPE bit in TIMx_CCRx)
					SetBit(TIM2_CCMR2,3);
					// Polarity Configuration (CCxP bit in TIMx_CCER)
					ClrBit(TIM2_CCER,9);
					// Enable OCx output  (CCxE bit in TIMx_CCER)
					SetBit(TIM2_CCER,8);
					break;
				case CHANNEL3:
					TIM2_CCR4 = duty_cycle - 1;
					// GPIO Configuration(AF PP)
					SetBit(GPIOA_CRL,15);
					ClrBit(GPIOA_CRL,14);
					SetBit(GPIOA_CRL,13);
					ClrBit(GPIOA_CRL,12);
					// Choose pin direction
					ClrBit(TIM2_CCMR2,8);
					ClrBit(TIM2_CCMR2,9);
					// Choose the PWM mode for the chosen timer channel
					SetBit(TIM2_CCMR2,14);
					SetBit(TIM2_CCMR2,13);
					ClrBit(TIM2_CCMR2,12);
					// Enable the preload register (OCxPE bit in TIMx_CCRx)
					SetBit(TIM2_CCMR2,11);
					// Polarity Configuration (CCxP bit in TIMx_CCER)
					ClrBit(TIM2_CCER,13);
					// Enable OCx output  (CCxE bit in TIMx_CCER)
					SetBit(TIM2_CCER,12);
					break;
				default:break;
			}
			// Enable the auto reload preload register (ARPE in TIMx_CR1)
			SetBit(TIM2_CR1,7);
			break;
		case TIMER3:
			// Store the signal period in TIMx_ARR
			TIM3_ARR = period ;
			// Store the signal duty cycle in TIMx_CCRx
			switch(timer_channel)
			{
				case CHANNEL0:
					TIM3_CCR1 = duty_cycle - 1;
					// GPIO Configuration(AF PP)
					SetBit(GPIOA_CRL,27);
					ClrBit(GPIOA_CRL,26);
					SetBit(GPIOA_CRL,25);
					ClrBit(GPIOA_CRL,24);
					// Choose pin direction
					ClrBit(TIM3_CCMR1,0);
					ClrBit(TIM3_CCMR1,1);
					// Choose the PWM mode for the chosen timer channel
					SetBit(TIM3_CCMR1,6);
					SetBit(TIM3_CCMR1,5);
					ClrBit(TIM3_CCMR1,4);
					// Enable the preload register (OCxPE bit in TIMx_CCRx)
					SetBit(TIM3_CCMR1,3);
					// Polarity Configuration (CCxP bit in TIMx_CCER)
					ClrBit(TIM3_CCER,1);
					// Enable OCx output  (CCxE bit in TIMx_CCER)
					SetBit(TIM3_CCER,0);
					break;
				case CHANNEL1:
					TIM3_CCR2 = duty_cycle - 1;
					// GPIO Configuration(AF PP)
					SetBit(GPIOA_CRL,31);
					ClrBit(GPIOA_CRL,30);
					SetBit(GPIOA_CRL,29);
					ClrBit(GPIOA_CRL,28);
					// Choose pin direction
					ClrBit(TIM3_CCMR1,8);
					ClrBit(TIM3_CCMR1,9);
					// Choose the PWM mode for the chosen timer channel
					SetBit(TIM3_CCMR1,14);
					SetBit(TIM3_CCMR1,13);
					ClrBit(TIM3_CCMR1,12);
					// Enable the preload register (OCxPE bit in TIMx_CCRx)
					SetBit(TIM3_CCMR1,11);
					// Polarity Configuration (CCxP bit in TIMx_CCER)
					ClrBit(TIM3_CCER,5);
					// Enable OCx output  (CCxE bit in TIMx_CCER)
					SetBit(TIM3_CCER,4);
					break;
				case CHANNEL2:
					TIM3_CCR3 = duty_cycle - 1;
					// GPIO Configuration(AF PP)
					SetBit(GPIOB_CRL,3);
					ClrBit(GPIOB_CRL,2);
					SetBit(GPIOB_CRL,1);
					ClrBit(GPIOB_CRL,0);
					// Choose pin direction
					ClrBit(TIM3_CCMR2,0);
					ClrBit(TIM3_CCMR2,1);
					// Choose the PWM mode for the chosen timer channel
					SetBit(TIM3_CCMR2,6);
					SetBit(TIM3_CCMR2,5);
					ClrBit(TIM3_CCMR2,4);
					// Enable the preload register (OCxPE bit in TIMx_CCRx)
					SetBit(TIM3_CCMR2,3);
					// Polarity Configuration (CCxP bit in TIMx_CCER)
					ClrBit(TIM3_CCER,9);
					// Enable OCx output  (CCxE bit in TIMx_CCER)
					SetBit(TIM3_CCER,8);
					break;
				case CHANNEL3:
					TIM3_CCR4 = duty_cycle - 1;
					// GPIO Configuration(AF PP)
					SetBit(GPIOB_CRL,7);
					ClrBit(GPIOB_CRL,6);
					SetBit(GPIOB_CRL,5);
					ClrBit(GPIOB_CRL,4);
					// Choose pin direction
					ClrBit(TIM3_CCMR2,8);
					ClrBit(TIM3_CCMR2,9);
					// Choose the PWM mode for the chosen timer channel
					SetBit(TIM3_CCMR2,14);
					SetBit(TIM3_CCMR2,13);
					ClrBit(TIM3_CCMR2,12);
					// Enable the preload register (OCxPE bit in TIMx_CCRx)
					SetBit(TIM3_CCMR2,11);
					// Polarity Configuration (CCxP bit in TIMx_CCER)
					ClrBit(TIM3_CCER,13);
					// Enable OCx output  (CCxE bit in TIMx_CCER)
					SetBit(TIM3_CCER,12);
					break;
				default:break;
			}
			// Enable the auto reload preload register (ARPE in TIMx_CR1)
			SetBit(TIM3_CR1,7);
			break;
		case TIMER4:
			// Store the signal period in TIMx_ARR
			TIM4_ARR = period ;
			// Store the signal duty cycle in TIMx_CCRx
			switch(timer_channel)
			{
				case CHANNEL0:
					TIM4_CCR1 = duty_cycle;
					// GPIO Configuration(AF PP)
					SetBit(GPIOB_CRL,27);
					ClrBit(GPIOB_CRL,26);
					SetBit(GPIOB_CRL,25);
					ClrBit(GPIOB_CRL,24);
					// Choose pin direction
					ClrBit(TIM4_CCMR1,0);
					ClrBit(TIM4_CCMR1,1);
					// Choose the PWM mode for the chosen timer channel
					SetBit(TIM4_CCMR1,6);
					SetBit(TIM4_CCMR1,5);
					ClrBit(TIM4_CCMR1,4);
					// Enable the preload register (OCxPE bit in TIMx_CCRx)
					SetBit(TIM4_CCMR1,3);
					// Polarity Configuration (CCxP bit in TIMx_CCER)
					ClrBit(TIM4_CCER,1);
					// Enable OCx output  (CCxE bit in TIMx_CCER)
					SetBit(TIM4_CCER,0);
					break;
				case CHANNEL1:
					TIM4_CCR2 = duty_cycle;
					// GPIO Configuration(AF PP)
					SetBit(GPIOB_CRL,31);
					ClrBit(GPIOB_CRL,30);
					SetBit(GPIOB_CRL,29);
					ClrBit(GPIOB_CRL,28);
					// Choose pin direction
					ClrBit(TIM4_CCMR1,8);
					ClrBit(TIM4_CCMR1,9);
					// Choose the PWM mode for the chosen timer channel
					SetBit(TIM4_CCMR1,14);
					SetBit(TIM4_CCMR1,13);
					ClrBit(TIM4_CCMR1,12);
					// Enable the preload register (OCxPE bit in TIMx_CCRx)
					SetBit(TIM4_CCMR1,11);
					// Polarity Configuration (CCxP bit in TIMx_CCER)
					ClrBit(TIM4_CCER,5);
					// Enable OCx output  (CCxE bit in TIMx_CCER)
					SetBit(TIM4_CCER,4);
					break;
				case CHANNEL2:
					TIM4_CCR3 = duty_cycle;
					// GPIO Configuration(AF PP)
					SetBit(GPIOB_CRH,3);
					ClrBit(GPIOB_CRH,2);
					SetBit(GPIOB_CRH,1);
					ClrBit(GPIOB_CRH,0);
					// Choose pin direction
					ClrBit(TIM4_CCMR2,0);
					ClrBit(TIM4_CCMR2,1);
					// Choose the PWM mode for the chosen timer channel
					SetBit(TIM4_CCMR2,6);
					SetBit(TIM4_CCMR2,5);
					ClrBit(TIM4_CCMR2,4);
					// Enable the preload register (OCxPE bit in TIMx_CCRx)
					SetBit(TIM4_CCMR2,3);
					// Polarity Configuration (CCxP bit in TIMx_CCER)
					ClrBit(TIM4_CCER,9);
					// Enable OCx output  (CCxE bit in TIMx_CCER)
					SetBit(TIM4_CCER,8);
					break;
				case CHANNEL3:
					TIM4_CCR4 = duty_cycle;
					// GPIO Configuration(AF PP)
					SetBit(GPIOB_CRL,27);
					ClrBit(GPIOB_CRL,26);
					SetBit(GPIOB_CRL,25);
					ClrBit(GPIOB_CRL,24);
					// Choose pin direction
					ClrBit(TIM4_CCMR2,8);
					ClrBit(TIM4_CCMR2,9);
					// Choose the PWM mode for the chosen timer channel
					SetBit(TIM4_CCMR2,14);
					SetBit(TIM4_CCMR2,13);
					ClrBit(TIM4_CCMR2,12);
					// Enable the preload register (OCxPE bit in TIMx_CCRx)
					SetBit(TIM4_CCMR2,11);
					// Polarity Configuration (CCxP bit in TIMx_CCER)
					ClrBit(TIM4_CCER,13);
					// Enable OCx output  (CCxE bit in TIMx_CCER)
					SetBit(TIM4_CCER,12);
					break;
				default:break;
			}
			// Enable the auto reload preload register (ARPE in TIMx_CR1)
			SetBit(TIM4_CR1,7);
			break;
		default:break;
	}
}
void Timer_DeactivatePWM(TIMER timer)
{
	switch(timer)
	{
		case TIMER2:
			ClrBit(TIM2_CCER,4);
			break;
		case TIMER3:
			ClrBit(TIM3_CCER,8);
			break;
		case TIMER4:
			ClrBit(TIM4_CCER,12);
			break;
		default:break;
	}
}

void Timer_ActivatePWMInterrupt(TIMER timer,TIMER_CHANNEL timer_channel)
{
	switch(timer)
	{
		case TIMER2:
			// NVIC
			SetBit(NVIC_ISER0,28);
			switch(timer_channel)
			{
				case CHANNEL0:
					SetBit(TIM2_SR,1);
					SetBit(TIM2_DIER,1);
					break;
				case CHANNEL1:
					SetBit(TIM2_SR,2);
					SetBit(TIM2_DIER,2);
					break;
				case CHANNEL2:
					SetBit(TIM2_SR,3);
					SetBit(TIM2_DIER,3);
					break;
				case CHANNEL3:
					SetBit(TIM2_SR,4);
					SetBit(TIM2_DIER,4);
					break;
			}
			break;
		case TIMER3:
			// NVIC
			SetBit(NVIC_ISER0,29);
			switch(timer_channel)
			{
				case CHANNEL0:
					SetBit(TIM3_SR,1);
					SetBit(TIM3_DIER,1);
					break;
				case CHANNEL1:
					SetBit(TIM3_SR,2);
					SetBit(TIM3_DIER,2);
					break;
				case CHANNEL2:
					SetBit(TIM3_SR,3);
					SetBit(TIM3_DIER,3);
					break;
				case CHANNEL3:
					SetBit(TIM3_SR,4);
					SetBit(TIM3_DIER,4);
					break;
			}
			break;
		case TIMER4:
			// NVIC
			SetBit(NVIC_ISER0,30);
			switch(timer_channel)
			{
				case CHANNEL0:
					SetBit(TIM4_SR,1);
					SetBit(TIM4_DIER,1);
					break;
				case CHANNEL1:
					SetBit(TIM4_SR,2);
					SetBit(TIM4_DIER,2);
					break;
				case CHANNEL2:
					SetBit(TIM4_SR,3);
					SetBit(TIM4_DIER,3);
					break;
				case CHANNEL3:
					SetBit(TIM4_SR,4);
					SetBit(TIM4_DIER,4);
					break;
			}
			break;
	}
}

void Timer_DeactivatePWMInterrupt(TIMER timer , TIMER_CHANNEL timer_channel)
{
	switch(timer)
	{
		case TIMER2:
			switch(timer_channel)
			{
				case CHANNEL0:
					ClrBit(TIM2_DIER,1);
					break;
				case CHANNEL1:
					ClrBit(TIM2_DIER,2);
					break;
				case CHANNEL2:
					ClrBit(TIM2_DIER,3);
					break;
				case CHANNEL3:
					ClrBit(TIM2_DIER,4);
					break;
			}
			break;
		case TIMER3:
			switch(timer_channel)
			{
				case CHANNEL0:
					ClrBit(TIM3_DIER,1);
					break;
				case CHANNEL1:
					ClrBit(TIM3_DIER,2);
					break;
				case CHANNEL2:
					ClrBit(TIM3_DIER,3);
					break;
				case CHANNEL3:
					ClrBit(TIM3_DIER,4);
					break;
			}
			break;
		case TIMER4:
			switch(timer_channel)
			{
				case CHANNEL0:
					ClrBit(TIM4_DIER,1);
					break;
				case CHANNEL1:
					ClrBit(TIM4_DIER,2);
					break;
				case CHANNEL2:
					ClrBit(TIM4_DIER,3);
					break;
				case CHANNEL3:
					ClrBit(TIM4_DIER,4);
					break;
			}
			break;
	}
}

void Timer_ActivateICU(TIMER timer, TIMER_CHANNEL timer_channel,CAPTURE_MODE capture_mode)
{
	switch(timer)
	{
		case TIMER2:
				switch(timer_channel)
				{
					case CHANNEL0:

						// Input Floating
						GPIO_PinDirection(PORTA,PIN0,INPUT_PIN,Floating);

						SetBit(TIM2_CCMR1,0);
						ClrBit(TIM2_CCMR1,1);

						// Digital Filter Setting (4 samples & internal clock)
						SetBit(TIM2_CCMR1,5);

						switch(capture_mode)
						{
							case RISING_EDGE_CAPTURE:
								ClrBit(TIM2_CCER,1);
								break;
							case FALLING_EDGE_CAPTURE:
								SetBit(TIM2_CCER,1);
								break;
							case BOTH_EDGES_CAPTURE:
								ClrBit(TIM2_SMCR,4);
								ClrBit(TIM2_SMCR,5);
								SetBit(TIM2_SMCR,6);
								SetBit(TIM2_CCMR1,0);
								SetBit(TIM2_CCMR1,1);
								break;
							default:break;
						}
						SetBit(TIM2_CCER,0); // Enable Capture Mode
						break;
					case CHANNEL1:


						// Input Floating
						GPIO_PinDirection(PORTA,PIN1,INPUT_PIN,Floating);

						SetBit(TIM2_CCMR1,8);
						ClrBit(TIM2_CCMR1,9);

						// Digital Filter Setting (4 samples & internal clock)
						SetBit(TIM2_CCMR1,13);

						switch(capture_mode)
						{
							case RISING_EDGE_CAPTURE:
								ClrBit(TIM2_CCER,5);
								break;
							case FALLING_EDGE_CAPTURE:
								SetBit(TIM2_CCER,5);
								break;
							default:break;
						}
						SetBit(TIM2_CCER,4);
						break;
					case CHANNEL2:

						// Input Floating
						GPIO_PinDirection(PORTA,PIN2,INPUT_PIN,Floating);

						SetBit(TIM2_CCMR2,0);
						ClrBit(TIM2_CCMR2,1);

						// Digital Filter Setting (4 samples & internal clock)
						SetBit(TIM2_CCMR2,5);

						switch(capture_mode)
						{
							case RISING_EDGE_CAPTURE:
								ClrBit(TIM2_CCER,9);
								break;
							case FALLING_EDGE_CAPTURE:
								SetBit(TIM2_CCER,9);
								break;
							default:break;
						}
						SetBit(TIM2_CCER,8);
						break;
					case CHANNEL3:

						// Input Floating
						GPIO_PinDirection(PORTA,PIN3,INPUT_PIN,Floating);

						SetBit(TIM2_CCMR2,8);
						ClrBit(TIM2_CCMR2,9);

						// Digital Filter Setting (4 samples & internal clock)
						SetBit(TIM2_CCMR2,13);

						switch(capture_mode)
						{
							case RISING_EDGE_CAPTURE:
								ClrBit(TIM2_CCER,13);
								break;
							case FALLING_EDGE_CAPTURE:
								SetBit(TIM2_CCER,13);
								break;
							default:break;
						}
						SetBit(TIM2_CCER,12);
						break;
					default:break;
				}
			break;
		case TIMER3:
			switch(timer_channel)
			{
				case CHANNEL0:

					// Input Floating
					GPIO_PinDirection(PORTA,PIN6,INPUT_PIN,Floating);


					SetBit(TIM3_CCMR1,0);
					ClrBit(TIM3_CCMR1,1);

					// Doesn't Have Great Effect in case of Ultrasonic

					// Digital Filter Setting (8 samples & internal clock)
					SetBit(TIM3_CCMR1,4);
					SetBit(TIM3_CCMR1,5);
					SetBit(TIM3_CCMR1,6);

					switch(capture_mode)
					{
						case RISING_EDGE_CAPTURE:
							ClrBit(TIM3_CCER,1);
							break;
						case FALLING_EDGE_CAPTURE:
							SetBit(TIM3_CCER,1);
							break;
						case BOTH_EDGES_CAPTURE:
							ClrBit(TIM3_SMCR,4);
							ClrBit(TIM3_SMCR,5);
							SetBit(TIM3_SMCR,6);
							SetBit(TIM3_CCMR1,0);
							SetBit(TIM3_CCMR1,1);
							break;
						default:break;
					}
					SetBit(TIM3_CCER,0);
					break;
				case CHANNEL1:

					// Input Floating
					GPIO_PinDirection(PORTA,PIN7,INPUT_PIN,Floating);

					SetBit(TIM3_CCMR1,8);
					ClrBit(TIM3_CCMR1,9);

					// Digital Filter Setting (8 samples & internal clock)
					SetBit(TIM3_CCMR1,12);
					SetBit(TIM3_CCMR1,13);
					SetBit(TIM3_CCMR1,14);

					switch(capture_mode)
					{
						case RISING_EDGE_CAPTURE:
							ClrBit(TIM3_CCER,5);
							break;
						case FALLING_EDGE_CAPTURE:
							SetBit(TIM3_CCER,5);
							break;
						default:break;
					}
					SetBit(TIM3_CCER,4);
					break;
				case CHANNEL2:

					// Input Floating
					GPIO_PinDirection(PORTB,PIN0,INPUT_PIN,Floating);

					SetBit(TIM3_CCMR2,0);
					ClrBit(TIM3_CCMR2,1);

					// Digital Filter Setting (4 samples & internal clock)
					SetBit(TIM3_CCMR2,5);

					switch(capture_mode)
					{
						case RISING_EDGE_CAPTURE:
							ClrBit(TIM3_CCER,9);
							break;
						case FALLING_EDGE_CAPTURE:
							SetBit(TIM3_CCER,9);
							break;
						default:break;
					}
					SetBit(TIM3_CCER,8);
					break;
				case CHANNEL3:

					// Input Floating
					GPIO_PinDirection(PORTB,PIN1,INPUT_PIN,Floating);

					SetBit(TIM3_CCMR2,8);
					ClrBit(TIM3_CCMR2,9);

					// Digital Filter Setting (4 samples & internal clock)
					SetBit(TIM3_CCMR2,13);

					switch(capture_mode)
					{
						case RISING_EDGE_CAPTURE:
							ClrBit(TIM3_CCER,13);
							break;
						case FALLING_EDGE_CAPTURE:
							SetBit(TIM3_CCER,13);
							break;
						default:break;
					}
					SetBit(TIM3_CCER,12);
					break;
				default:break;
			}
			break;
		case TIMER4:
			switch(timer_channel)
			{
				case CHANNEL0:


					// Input Floating
					GPIO_PinDirection(PORTB,PIN6,INPUT_PIN,Floating);

					SetBit(TIM4_CCMR1,0);
					ClrBit(TIM4_CCMR1,1);

					// Digital Filter Setting (4 samples & internal clock)
					SetBit(TIM4_CCMR1,5);

					switch(capture_mode)
					{
						case RISING_EDGE_CAPTURE:
							ClrBit(TIM4_CCER,1);
							break;
						case FALLING_EDGE_CAPTURE:
							SetBit(TIM4_CCER,1);
							break;
						case BOTH_EDGES_CAPTURE:
							ClrBit(TIM4_SMCR,4);
							ClrBit(TIM4_SMCR,5);
							SetBit(TIM4_SMCR,6);
							SetBit(TIM4_CCMR1,0);
							SetBit(TIM4_CCMR1,1);
							break;
						default:break;
					}
					SetBit(TIM4_CCER,0);
					break;
				case CHANNEL1:

					// Input Floating
					GPIO_PinDirection(PORTB,PIN7,INPUT_PIN,Floating);

					SetBit(TIM4_CCMR1,8);
					ClrBit(TIM4_CCMR1,9);

					// Digital Filter Setting (4 samples & internal clock)
					SetBit(TIM4_CCMR1,13);

					switch(capture_mode)
					{
						case RISING_EDGE_CAPTURE:
							ClrBit(TIM4_CCER,5);
							break;
						case FALLING_EDGE_CAPTURE:
							SetBit(TIM4_CCER,5);
							break;
						default:break;
					}
					SetBit(TIM4_CCER,4);
					break;
				case CHANNEL2:

					// Input Floating
					GPIO_PinDirection(PORTB,PIN8,INPUT_PIN,Floating);

					SetBit(TIM4_CCMR2,0);
					ClrBit(TIM4_CCMR2,1);

					// Digital Filter Setting (4 samples & internal clock)
					SetBit(TIM4_CCMR2,5);

					switch(capture_mode)
					{
						case RISING_EDGE_CAPTURE:
							ClrBit(TIM4_CCER,9);
							break;
						case FALLING_EDGE_CAPTURE:
							SetBit(TIM4_CCER,9);
							break;
						default:break;
					}
					SetBit(TIM4_CCER,8);
					break;
				case CHANNEL3:

					// Input Floating
					GPIO_PinDirection(PORTB,PIN9,INPUT_PIN,Floating);


					SetBit(TIM4_CCMR2,8);
					ClrBit(TIM4_CCMR2,9);

					// Digital Filter Setting (4 samples & internal clock)
					SetBit(TIM4_CCMR2,13);

					switch(capture_mode)
					{
						case RISING_EDGE_CAPTURE:
							ClrBit(TIM4_CCER,13);
							break;
						case FALLING_EDGE_CAPTURE:
							SetBit(TIM4_CCER,13);
							break;
						default:break;
					}
					SetBit(TIM4_CCER,12);
					break;
				default:break;
			}
			break;
		default:break;
	}
}


void Timer_ActivateICUInterrupt(TIMER timer, TIMER_CHANNEL timer_channel)
{
	switch(timer)
	{
		case TIMER2:
			switch(timer_channel)
			{
				case CHANNEL0:
					SetBit(TIM2_DIER,1);
					break;
				case CHANNEL1:
					SetBit(TIM2_DIER,2);
					break;
				case CHANNEL2:
					SetBit(TIM2_DIER,3);
					break;
				case CHANNEL3:
					SetBit(TIM2_DIER,4);
					break;
				default:break;
			}
			break;
		case TIMER3:
			switch(timer_channel)
			{
				case CHANNEL0:
					SetBit(TIM3_DIER,1);
					break;
				case CHANNEL1:
					SetBit(TIM3_DIER,2);
					break;
				case CHANNEL2:
					SetBit(TIM3_DIER,3);
					break;
				case CHANNEL3:
					SetBit(TIM3_DIER,4);
					break;
				default:break;
			}
			break;
		case TIMER4:
			switch(timer_channel)
			{
				case CHANNEL0:
					SetBit(TIM4_DIER,1);
					break;
				case CHANNEL1:
					SetBit(TIM4_DIER,2);
					break;
				case CHANNEL2:
					SetBit(TIM4_DIER,3);
					break;
				case CHANNEL3:
					SetBit(TIM4_DIER,4);
					break;
				default:break;
			}
			break;
	}
}

unsigned short Timer_GetICU_Value(TIMER timer , TIMER_CHANNEL timer_channel)
{
	switch(timer)
	{
		case TIMER2:
			switch(timer_channel)
			{
				case CHANNEL0:
					return(TIM2_CCR1);
					break;
				case CHANNEL1:
					return(TIM2_CCR2);
					break;
				case CHANNEL2:
					return(TIM2_CCR3);
					break;
				case CHANNEL3:
					return(TIM2_CCR4);
					break;
				default:break;
			}
			break;
		case TIMER3:
			switch(timer_channel)
			{
				case CHANNEL0:
					return(TIM3_CCR1);
					break;
				case CHANNEL1:
					return(TIM3_CCR2);
					break;
				case CHANNEL2:
					return(TIM3_CCR3);
					break;
				case CHANNEL3:
					return(TIM3_CCR4);
					break;
				default:break;
			}
			break;
		case TIMER4:
			switch(timer_channel)
			{
				case CHANNEL0:
					return(TIM4_CCR1);
					break;
				case CHANNEL1:
					return(TIM4_CCR2);
					break;
				case CHANNEL2:
					return(TIM4_CCR3);
					break;
				case CHANNEL3:
					return(TIM4_CCR4);
					break;
				default:break;
			}
			break;
		default:break;
	}
}


unsigned char Timer_CaptureUnits_Flags (TIMER timer, TIMER_CHANNEL timer_channel)
{
	switch(timer)
	{
		case TIMER2:
			return(GetBit(TIM2_SR,timer_channel+1));
			break;
		case TIMER3:
			return(GetBit(TIM3_SR,timer_channel+1));
			break;
		case TIMER4:
			return(GetBit(TIM4_SR,timer_channel+1));
			break;
		default:break;
	}
}
void TIM1_IRQHandler (void)
{
	TIMER1_ISR();
	// Clear Flag
	if(GetBit(TIM1_SR,0))
		ClrBit(TIM1_SR,0);
	if(GetBit(TIM1_SR,1))
		ClrBit(TIM1_SR,1);
	if(GetBit(TIM1_SR,2))
		ClrBit(TIM1_SR,2);
	if(GetBit(TIM1_SR,3))
		ClrBit(TIM1_SR,3);
	if(GetBit(TIM1_SR,4))
		ClrBit(TIM1_SR,4);

}
void TIM2_IRQHandler (void)
{
	TIMER2_ISR();
	// Clear Flag
	if(GetBit(TIM2_SR,0))
		ClrBit(TIM2_SR,0);
	if(GetBit(TIM2_SR,1))
		ClrBit(TIM2_SR,1);
	if(GetBit(TIM2_SR,2))
		ClrBit(TIM2_SR,2);
	if(GetBit(TIM2_SR,3))
		ClrBit(TIM2_SR,3);
	if(GetBit(TIM2_SR,4))
		ClrBit(TIM2_SR,4);

}
void TIM3_IRQHandler (void)
{
	TIMER3_ISR();
	// Clear Flag
	if(GetBit(TIM3_SR,0))
		ClrBit(TIM3_SR,0);
	if(GetBit(TIM3_SR,1))
		ClrBit(TIM3_SR,1);
	if(GetBit(TIM3_SR,2))
		ClrBit(TIM3_SR,2);
	if(GetBit(TIM3_SR,3))
		ClrBit(TIM3_SR,3);
	if(GetBit(TIM3_SR,4))
		ClrBit(TIM3_SR,4);
}
void TIM4_IRQHandler (void)
{
	TIMER4_ISR();
	// Clear Flag
	if(GetBit(TIM4_SR,0))
		ClrBit(TIM4_SR,0);
	if(GetBit(TIM4_SR,1))
		ClrBit(TIM4_SR,1);
	if(GetBit(TIM4_SR,2))
		ClrBit(TIM4_SR,2);
	if(GetBit(TIM4_SR,3))
		ClrBit(TIM4_SR,3);
	if(GetBit(TIM4_SR,4))
		ClrBit(TIM4_SR,4);
}


