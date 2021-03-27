/*
 * EXTI.c
 *
 *  Created on: Dec 17, 2020
 *      Author: Karim Hussein
 */


#include "Regmap.h"
#include "util.h"
#include "EXTI.h"

// We have 16 Priority Level

void EXTI_Init(EXTI exti ,PORT port ,INTERRUPT_CONDITION int_src)
{
	// Activate AFIO
	SetBit(RCC_APB2ENR,0);

	switch(exti)
	{
	case EXTI0:
		// Choose Pin
		switch(port)
		{
		case PORTA:
			ClrBit(AFIO_EXTICR1,0);
			ClrBit(AFIO_EXTICR1,1);
			ClrBit(AFIO_EXTICR1,2);
			ClrBit(AFIO_EXTICR1,3);
			break;
		case PORTB:
			SetBit(AFIO_EXTICR1,0);
			ClrBit(AFIO_EXTICR1,1);
			ClrBit(AFIO_EXTICR1,2);
			ClrBit(AFIO_EXTICR1,3);
			break;
		case PORTC:
			ClrBit(AFIO_EXTICR1,0);
			SetBit(AFIO_EXTICR1,1);
			ClrBit(AFIO_EXTICR1,2);
			ClrBit(AFIO_EXTICR1,3);
			break;
		default:
			ClrBit(AFIO_EXTICR1,0);
			ClrBit(AFIO_EXTICR1,1);
			ClrBit(AFIO_EXTICR1,2);
			ClrBit(AFIO_EXTICR1,3);
			break;
		}
		// Interrupt source
		switch(int_src)
		{
		case RISING_EDGE:
			SetBit(EXTI_RTSR,0);
			ClrBit(EXTI_FTSR,0);
			break;
		case FALLING_EDGE:
			ClrBit(EXTI_RTSR,0);
			SetBit(EXTI_FTSR,0);
			break;
		case LEVEL_CHANGE:
			SetBit(EXTI_FTSR,0);
			SetBit(EXTI_RTSR,0);
			break;
		default:
			ClrBit(EXTI_FTSR,0);
			ClrBit(EXTI_RTSR,0);
			break;
		}
		SetBit(NVIC_ISER0,6);
		break;
	case EXTI1:
		switch(port)
		{
		case PORTA:
			ClrBit(AFIO_EXTICR1,4);
			ClrBit(AFIO_EXTICR1,5);
			ClrBit(AFIO_EXTICR1,6);
			ClrBit(AFIO_EXTICR1,7);
			break;
		case PORTB:
			SetBit(AFIO_EXTICR1,4);
			ClrBit(AFIO_EXTICR1,5);
			ClrBit(AFIO_EXTICR1,6);
			ClrBit(AFIO_EXTICR1,7);
			break;
		case PORTC:
			ClrBit(AFIO_EXTICR1,4);
			SetBit(AFIO_EXTICR1,5);
			ClrBit(AFIO_EXTICR1,6);
			ClrBit(AFIO_EXTICR1,7);
			break;
		default:
			ClrBit(AFIO_EXTICR1,4);
			ClrBit(AFIO_EXTICR1,5);
			ClrBit(AFIO_EXTICR1,6);
			ClrBit(AFIO_EXTICR1,7);
			break;
		}
		// Interrupt source
		switch(int_src)
		{
		case RISING_EDGE:
			SetBit(EXTI_RTSR,1);
			ClrBit(EXTI_FTSR,1);
			break;
		case FALLING_EDGE:
			ClrBit(EXTI_RTSR,1);
			SetBit(EXTI_FTSR,1);
			break;
		case LEVEL_CHANGE:
			SetBit(EXTI_FTSR,1);
			SetBit(EXTI_RTSR,1);
			break;
		default:
			ClrBit(EXTI_FTSR,1);
			ClrBit(EXTI_RTSR,1);
			break;
		}
		SetBit(NVIC_ISER0,7);
		break;
	case EXTI2:
		switch(port)
		{
		case PORTA:
			ClrBit(AFIO_EXTICR1,8);
			ClrBit(AFIO_EXTICR1,9);
			ClrBit(AFIO_EXTICR1,10);
			ClrBit(AFIO_EXTICR1,11);
			break;
		case PORTB:
			SetBit(AFIO_EXTICR1,8);
			ClrBit(AFIO_EXTICR1,9);
			ClrBit(AFIO_EXTICR1,10);
			ClrBit(AFIO_EXTICR1,11);
			break;
		case PORTC:
			ClrBit(AFIO_EXTICR1,8);
			SetBit(AFIO_EXTICR1,9);
			ClrBit(AFIO_EXTICR1,10);
			ClrBit(AFIO_EXTICR1,11);
			break;
		default:
			ClrBit(AFIO_EXTICR1,8);
			ClrBit(AFIO_EXTICR1,9);
			ClrBit(AFIO_EXTICR1,10);
			ClrBit(AFIO_EXTICR1,11);
			break;
		}
		// Interrupt source
		switch(int_src)
		{
		case RISING_EDGE:
			SetBit(EXTI_RTSR,2);
			ClrBit(EXTI_FTSR,2);
			break;
		case FALLING_EDGE:
			ClrBit(EXTI_RTSR,2);
			SetBit(EXTI_FTSR,2);
			break;
		case LEVEL_CHANGE:
			SetBit(EXTI_FTSR,2);
			SetBit(EXTI_RTSR,2);
			break;
		default:
			ClrBit(EXTI_FTSR,2);
			ClrBit(EXTI_RTSR,2);
			break;
		}
		SetBit(NVIC_ISER0,8);
		break;
	case EXTI3:
		switch(port)
		{
		case PORTA:
			ClrBit(AFIO_EXTICR1,12);
			ClrBit(AFIO_EXTICR1,13);
			ClrBit(AFIO_EXTICR1,14);
			ClrBit(AFIO_EXTICR1,15);
			break;
		case PORTB:
			SetBit(AFIO_EXTICR1,12);
			ClrBit(AFIO_EXTICR1,13);
			ClrBit(AFIO_EXTICR1,14);
			ClrBit(AFIO_EXTICR1,15);
			break;
		case PORTC:
			ClrBit(AFIO_EXTICR1,12);
			SetBit(AFIO_EXTICR1,13);
			ClrBit(AFIO_EXTICR1,14);
			ClrBit(AFIO_EXTICR1,15);
			break;
		default:
			ClrBit(AFIO_EXTICR1,12);
			ClrBit(AFIO_EXTICR1,13);
			ClrBit(AFIO_EXTICR1,14);
			ClrBit(AFIO_EXTICR1,15);
			break;
		}
		// Interrupt source
		switch(int_src)
		{
		case RISING_EDGE:
			SetBit(EXTI_RTSR,3);
			ClrBit(EXTI_FTSR,3);
			break;
		case FALLING_EDGE:
			ClrBit(EXTI_RTSR,3);
			SetBit(EXTI_FTSR,3);
			break;
		case LEVEL_CHANGE:
			SetBit(EXTI_FTSR,3);
			SetBit(EXTI_RTSR,3);
			break;
		default:
			ClrBit(EXTI_FTSR,3);
			ClrBit(EXTI_RTSR,3);
			break;
		}
		SetBit(NVIC_ISER0,9);
		break;
		case EXTI4:
			switch(port)
			{
			case PORTA:
				ClrBit(AFIO_EXTICR2,0);
				ClrBit(AFIO_EXTICR2,1);
				ClrBit(AFIO_EXTICR2,2);
				ClrBit(AFIO_EXTICR2,3);
				break;
			case PORTB:
				SetBit(AFIO_EXTICR2,0);
				ClrBit(AFIO_EXTICR2,1);
				ClrBit(AFIO_EXTICR2,2);
				ClrBit(AFIO_EXTICR2,3);
				break;
			case PORTC:
				ClrBit(AFIO_EXTICR2,0);
				SetBit(AFIO_EXTICR2,1);
				ClrBit(AFIO_EXTICR2,2);
				ClrBit(AFIO_EXTICR2,3);
				break;
			default:
				ClrBit(AFIO_EXTICR2,0);
				ClrBit(AFIO_EXTICR2,1);
				ClrBit(AFIO_EXTICR2,2);
				ClrBit(AFIO_EXTICR2,3);
				break;
			}
			// Interrupt source
			switch(int_src)
			{
			case RISING_EDGE:
				SetBit(EXTI_RTSR,4);
				ClrBit(EXTI_FTSR,4);
				break;
			case FALLING_EDGE:
				ClrBit(EXTI_RTSR,4);
				SetBit(EXTI_FTSR,4);
				break;
			case LEVEL_CHANGE:
				SetBit(EXTI_FTSR,4);
				SetBit(EXTI_RTSR,4);
				break;
			default:
				ClrBit(EXTI_FTSR,4);
				ClrBit(EXTI_RTSR,4);
				break;
			}
			SetBit(NVIC_ISER0,10);
			break;
		case EXTI5:
			switch(port)
			{
			case PORTA:
				ClrBit(AFIO_EXTICR2,4);
				ClrBit(AFIO_EXTICR2,5);
				ClrBit(AFIO_EXTICR2,6);
				ClrBit(AFIO_EXTICR2,7);
				break;
			case PORTB:
				SetBit(AFIO_EXTICR2,4);
				ClrBit(AFIO_EXTICR2,5);
				ClrBit(AFIO_EXTICR2,6);
				ClrBit(AFIO_EXTICR2,7);
				break;
			case PORTC:
				ClrBit(AFIO_EXTICR2,4);
				SetBit(AFIO_EXTICR2,5);
				ClrBit(AFIO_EXTICR2,6);
				ClrBit(AFIO_EXTICR2,7);
				break;
			default:
				ClrBit(AFIO_EXTICR2,4);
				ClrBit(AFIO_EXTICR2,5);
				ClrBit(AFIO_EXTICR2,6);
				ClrBit(AFIO_EXTICR2,7);
				break;
			}
			// Interrupt source
			switch(int_src)
			{
			case RISING_EDGE:
				SetBit(EXTI_RTSR,5);
				ClrBit(EXTI_FTSR,5);
				break;
			case FALLING_EDGE:
				ClrBit(EXTI_RTSR,5);
				SetBit(EXTI_FTSR,5);
				break;
			case LEVEL_CHANGE:
				SetBit(EXTI_FTSR,5);
				SetBit(EXTI_RTSR,5);
				break;
			default:
				ClrBit(EXTI_FTSR,5);
				ClrBit(EXTI_RTSR,5);
				break;
			}
			SetBit(NVIC_ISER0,23);
			break;
		case EXTI6:
			switch(port)
			{
			case PORTA:
				ClrBit(AFIO_EXTICR2,8);
				ClrBit(AFIO_EXTICR2,9);
				ClrBit(AFIO_EXTICR2,10);
				ClrBit(AFIO_EXTICR2,11);
				break;
			case PORTB:
				SetBit(AFIO_EXTICR2,8);
				ClrBit(AFIO_EXTICR2,9);
				ClrBit(AFIO_EXTICR2,10);
				ClrBit(AFIO_EXTICR2,11);
				break;
			case PORTC:
				ClrBit(AFIO_EXTICR2,8);
				SetBit(AFIO_EXTICR2,9);
				ClrBit(AFIO_EXTICR2,10);
				ClrBit(AFIO_EXTICR2,11);
				break;
			default:
				ClrBit(AFIO_EXTICR2,8);
				ClrBit(AFIO_EXTICR2,9);
				ClrBit(AFIO_EXTICR2,10);
				ClrBit(AFIO_EXTICR2,11);
				break;
			}
			// Interrupt source
			switch(int_src)
			{
			case RISING_EDGE:
				SetBit(EXTI_RTSR,6);
				ClrBit(EXTI_FTSR,6);
				break;
			case FALLING_EDGE:
				ClrBit(EXTI_RTSR,6);
				SetBit(EXTI_FTSR,6);
				break;
			case LEVEL_CHANGE:
				SetBit(EXTI_FTSR,6);
				SetBit(EXTI_RTSR,6);
				break;
			default:
				ClrBit(EXTI_FTSR,6);
				ClrBit(EXTI_RTSR,6);
				break;
			}
			SetBit(NVIC_ISER0,23);
			break;
		case EXTI7:
			switch(port)
			{
			case PORTA:
				ClrBit(AFIO_EXTICR2,12);
				ClrBit(AFIO_EXTICR2,13);
				ClrBit(AFIO_EXTICR2,14);
				ClrBit(AFIO_EXTICR2,15);
				break;
			case PORTB:
				SetBit(AFIO_EXTICR2,12);
				ClrBit(AFIO_EXTICR2,13);
				ClrBit(AFIO_EXTICR2,14);
				ClrBit(AFIO_EXTICR2,15);
				break;
			case PORTC:
				ClrBit(AFIO_EXTICR2,12);
				SetBit(AFIO_EXTICR2,13);
				ClrBit(AFIO_EXTICR2,14);
				ClrBit(AFIO_EXTICR2,15);
				break;
			default:
				ClrBit(AFIO_EXTICR2,12);
				ClrBit(AFIO_EXTICR2,13);
				ClrBit(AFIO_EXTICR2,14);
				ClrBit(AFIO_EXTICR2,15);
				break;
			}
			// Interrupt source
			switch(int_src)
			{
			case RISING_EDGE:
				SetBit(EXTI_RTSR,7);
				ClrBit(EXTI_FTSR,7);
				break;
			case FALLING_EDGE:
				ClrBit(EXTI_RTSR,7);
				SetBit(EXTI_FTSR,7);
				break;
			case LEVEL_CHANGE:
				SetBit(EXTI_FTSR,7);
				SetBit(EXTI_RTSR,7);
				break;
			default:
				ClrBit(EXTI_FTSR,7);
				ClrBit(EXTI_RTSR,7);
				break;
			}
			SetBit(NVIC_ISER0,23);
			break;
			case EXTI8:
				switch(port)
				{
				case PORTA:
					ClrBit(AFIO_EXTICR3,0);
					ClrBit(AFIO_EXTICR3,1);
					ClrBit(AFIO_EXTICR3,2);
					ClrBit(AFIO_EXTICR3,3);
					break;
				case PORTB:
					SetBit(AFIO_EXTICR3,0);
					ClrBit(AFIO_EXTICR3,1);
					ClrBit(AFIO_EXTICR3,2);
					ClrBit(AFIO_EXTICR3,3);
					break;
				case PORTC:
					ClrBit(AFIO_EXTICR3,0);
					SetBit(AFIO_EXTICR3,1);
					ClrBit(AFIO_EXTICR3,2);
					ClrBit(AFIO_EXTICR3,3);
					break;
				default:
					ClrBit(AFIO_EXTICR3,0);
					ClrBit(AFIO_EXTICR3,1);
					ClrBit(AFIO_EXTICR3,2);
					ClrBit(AFIO_EXTICR3,3);
					break;
				}
				// Interrupt source
				switch(int_src)
				{
				case RISING_EDGE:
					SetBit(EXTI_RTSR,8);
					ClrBit(EXTI_FTSR,8);
					break;
				case FALLING_EDGE:
					ClrBit(EXTI_RTSR,8);
					SetBit(EXTI_FTSR,8);
					break;
				case LEVEL_CHANGE:
					SetBit(EXTI_FTSR,8);
					SetBit(EXTI_RTSR,8);
					break;
				default:
					ClrBit(EXTI_FTSR,8);
					ClrBit(EXTI_RTSR,8);
					break;
				}
				SetBit(NVIC_ISER0,23);
				break;
			case EXTI9:
				switch(port)
				{
				case PORTA:
					ClrBit(AFIO_EXTICR3,4);
					ClrBit(AFIO_EXTICR3,5);
					ClrBit(AFIO_EXTICR3,6);
					ClrBit(AFIO_EXTICR3,7);
					break;
				case PORTB:
					SetBit(AFIO_EXTICR3,4);
					ClrBit(AFIO_EXTICR3,5);
					ClrBit(AFIO_EXTICR3,6);
					ClrBit(AFIO_EXTICR3,7);
					break;
				case PORTC:
					ClrBit(AFIO_EXTICR3,4);
					SetBit(AFIO_EXTICR3,5);
					ClrBit(AFIO_EXTICR3,6);
					ClrBit(AFIO_EXTICR3,7);
					break;
				default:
					ClrBit(AFIO_EXTICR3,4);
					ClrBit(AFIO_EXTICR3,5);
					ClrBit(AFIO_EXTICR3,6);
					ClrBit(AFIO_EXTICR3,7);
					break;
				}
				// Interrupt source
				switch(int_src)
				{
				case RISING_EDGE:
					SetBit(EXTI_RTSR,9);
					ClrBit(EXTI_FTSR,9);
					break;
				case FALLING_EDGE:
					ClrBit(EXTI_RTSR,9);
					SetBit(EXTI_FTSR,9);
					break;
				case LEVEL_CHANGE:
					SetBit(EXTI_FTSR,9);
					SetBit(EXTI_RTSR,9);
					break;
				default:
					ClrBit(EXTI_FTSR,9);
					ClrBit(EXTI_RTSR,9);
					break;
				}
				SetBit(NVIC_ISER0,23);
				break;
			case EXTI10:
				switch(port)
				{
				case PORTA:
					ClrBit(AFIO_EXTICR3,8);
					ClrBit(AFIO_EXTICR3,9);
					ClrBit(AFIO_EXTICR3,10);
					ClrBit(AFIO_EXTICR3,11);
					break;
				case PORTB:
					SetBit(AFIO_EXTICR3,8);
					ClrBit(AFIO_EXTICR3,9);
					ClrBit(AFIO_EXTICR3,10);
					ClrBit(AFIO_EXTICR3,11);
					break;
				case PORTC:
					ClrBit(AFIO_EXTICR3,8);
					SetBit(AFIO_EXTICR3,9);
					ClrBit(AFIO_EXTICR3,10);
					ClrBit(AFIO_EXTICR3,11);
					break;
				default:
					ClrBit(AFIO_EXTICR3,8);
					ClrBit(AFIO_EXTICR3,9);
					ClrBit(AFIO_EXTICR3,10);
					ClrBit(AFIO_EXTICR3,11);
					break;
				}
				// Interrupt source
				switch(int_src)
				{
				case RISING_EDGE:
					SetBit(EXTI_RTSR,10);
					ClrBit(EXTI_FTSR,10);
					break;
				case FALLING_EDGE:
					ClrBit(EXTI_RTSR,10);
					SetBit(EXTI_FTSR,10);
					break;
				case LEVEL_CHANGE:
					SetBit(EXTI_FTSR,10);
					SetBit(EXTI_RTSR,10);
					break;
				default:
					ClrBit(EXTI_FTSR,10);
					ClrBit(EXTI_RTSR,10);
					break;
				}
				SetBit(NVIC_ISER1,8);
				break;
			case EXTI11:
				switch(port)
				{
				case PORTA:
					ClrBit(AFIO_EXTICR3,12);
					ClrBit(AFIO_EXTICR3,13);
					ClrBit(AFIO_EXTICR3,14);
					ClrBit(AFIO_EXTICR3,15);
					break;
				case PORTB:
					SetBit(AFIO_EXTICR3,12);
					ClrBit(AFIO_EXTICR3,13);
					ClrBit(AFIO_EXTICR3,14);
					ClrBit(AFIO_EXTICR3,15);
					break;
				case PORTC:
					ClrBit(AFIO_EXTICR3,12);
					SetBit(AFIO_EXTICR3,13);
					ClrBit(AFIO_EXTICR3,14);
					ClrBit(AFIO_EXTICR3,15);
					break;
				default:
					ClrBit(AFIO_EXTICR3,12);
					ClrBit(AFIO_EXTICR3,13);
					ClrBit(AFIO_EXTICR3,14);
					ClrBit(AFIO_EXTICR3,15);
					break;
				}
				// Interrupt source
				switch(int_src)
				{
				case RISING_EDGE:
					SetBit(EXTI_RTSR,11);
					ClrBit(EXTI_FTSR,11);
					break;
				case FALLING_EDGE:
					ClrBit(EXTI_RTSR,11);
					SetBit(EXTI_FTSR,11);
					break;
				case LEVEL_CHANGE:
					SetBit(EXTI_FTSR,11);
					SetBit(EXTI_RTSR,11);
					break;
				default:
					ClrBit(EXTI_FTSR,11);
					ClrBit(EXTI_RTSR,11);
					break;
				}
				SetBit(NVIC_ISER1,8);
				break;
				case EXTI12:
					switch(port)
					{
					case PORTA:
						ClrBit(AFIO_EXTICR4,0);
						ClrBit(AFIO_EXTICR4,1);
						ClrBit(AFIO_EXTICR4,2);
						ClrBit(AFIO_EXTICR4,3);
						break;
					case PORTB:
						SetBit(AFIO_EXTICR4,0);
						ClrBit(AFIO_EXTICR4,1);
						ClrBit(AFIO_EXTICR4,2);
						ClrBit(AFIO_EXTICR4,3);
						break;
					case PORTC:
						ClrBit(AFIO_EXTICR4,0);
						SetBit(AFIO_EXTICR4,1);
						ClrBit(AFIO_EXTICR4,2);
						ClrBit(AFIO_EXTICR4,3);
						break;
					default:
						ClrBit(AFIO_EXTICR4,0);
						ClrBit(AFIO_EXTICR4,1);
						ClrBit(AFIO_EXTICR4,2);
						ClrBit(AFIO_EXTICR4,3);
						break;
					}
					// Interrupt source
					switch(int_src)
					{
					case RISING_EDGE:
						SetBit(EXTI_RTSR,12);
						ClrBit(EXTI_FTSR,12);
						break;
					case FALLING_EDGE:
						ClrBit(EXTI_RTSR,12);
						SetBit(EXTI_FTSR,12);
						break;
					case LEVEL_CHANGE:
						SetBit(EXTI_FTSR,12);
						SetBit(EXTI_RTSR,12);
						break;
					default:
						ClrBit(EXTI_FTSR,12);
						ClrBit(EXTI_RTSR,12);
						break;
					}
					SetBit(NVIC_ISER1,8);
					break;
				case EXTI13:
					switch(port)
					{
					case PORTA:
						ClrBit(AFIO_EXTICR4,4);
						ClrBit(AFIO_EXTICR4,5);
						ClrBit(AFIO_EXTICR4,6);
						ClrBit(AFIO_EXTICR4,7);
						break;
					case PORTB:
						SetBit(AFIO_EXTICR4,4);
						ClrBit(AFIO_EXTICR4,5);
						ClrBit(AFIO_EXTICR4,6);
						ClrBit(AFIO_EXTICR4,7);
						break;
					case PORTC:
						ClrBit(AFIO_EXTICR4,4);
						SetBit(AFIO_EXTICR4,5);
						ClrBit(AFIO_EXTICR4,6);
						ClrBit(AFIO_EXTICR4,7);
						break;
					default:
						ClrBit(AFIO_EXTICR4,4);
						ClrBit(AFIO_EXTICR4,5);
						ClrBit(AFIO_EXTICR4,6);
						ClrBit(AFIO_EXTICR4,7);
						break;
					}
					// Interrupt source
					switch(int_src)
					{
					case RISING_EDGE:
						SetBit(EXTI_RTSR,13);
						ClrBit(EXTI_FTSR,13);
						break;
					case FALLING_EDGE:
						ClrBit(EXTI_RTSR,13);
						SetBit(EXTI_FTSR,13);
						break;
					case LEVEL_CHANGE:
						SetBit(EXTI_FTSR,13);
						SetBit(EXTI_RTSR,13);
						break;
					default:
						ClrBit(EXTI_FTSR,13);
						ClrBit(EXTI_RTSR,13);
						break;
					}
					SetBit(NVIC_ISER1,8);
					break;
				case EXTI14:
					switch(port)
					{
					case PORTA:
						ClrBit(AFIO_EXTICR4,8);
						ClrBit(AFIO_EXTICR4,9);
						ClrBit(AFIO_EXTICR4,10);
						ClrBit(AFIO_EXTICR4,11);
						break;
					case PORTB:
						SetBit(AFIO_EXTICR4,8);
						ClrBit(AFIO_EXTICR4,9);
						ClrBit(AFIO_EXTICR4,10);
						ClrBit(AFIO_EXTICR4,11);
						break;
					case PORTC:
						ClrBit(AFIO_EXTICR4,8);
						SetBit(AFIO_EXTICR4,9);
						ClrBit(AFIO_EXTICR4,10);
						ClrBit(AFIO_EXTICR4,11);
						break;
					default:
						ClrBit(AFIO_EXTICR4,8);
						ClrBit(AFIO_EXTICR4,9);
						ClrBit(AFIO_EXTICR4,10);
						ClrBit(AFIO_EXTICR4,11);
						break;
					}
					// Interrupt source
					switch(int_src)
					{
					case RISING_EDGE:
						SetBit(EXTI_RTSR,14);
						ClrBit(EXTI_FTSR,14);
						break;
					case FALLING_EDGE:
						ClrBit(EXTI_RTSR,14);
						SetBit(EXTI_FTSR,14);
						break;
					case LEVEL_CHANGE:
						SetBit(EXTI_FTSR,14);
						SetBit(EXTI_RTSR,14);
						break;
					default:
						ClrBit(EXTI_FTSR,14);
						ClrBit(EXTI_RTSR,14);
						break;
					}
					SetBit(NVIC_ISER1,8);
					break;
				case EXTI15:
					switch(port)
					{
					case PORTA:
						ClrBit(AFIO_EXTICR4,12);
						ClrBit(AFIO_EXTICR4,13);
						ClrBit(AFIO_EXTICR4,14);
						ClrBit(AFIO_EXTICR4,15);
						break;
					case PORTB:
						SetBit(AFIO_EXTICR4,12);
						ClrBit(AFIO_EXTICR4,13);
						ClrBit(AFIO_EXTICR4,14);
						ClrBit(AFIO_EXTICR4,15);
						break;
					case PORTC:
						ClrBit(AFIO_EXTICR4,12);
						SetBit(AFIO_EXTICR4,13);
						ClrBit(AFIO_EXTICR4,14);
						ClrBit(AFIO_EXTICR4,15);
						break;
					default:
						ClrBit(AFIO_EXTICR4,12);
						ClrBit(AFIO_EXTICR4,13);
						ClrBit(AFIO_EXTICR4,14);
						ClrBit(AFIO_EXTICR4,15);
						break;
					}
					// Interrupt source
					switch(int_src)
					{
					case RISING_EDGE:
						SetBit(EXTI_RTSR,15);
						ClrBit(EXTI_FTSR,15);
						break;
					case FALLING_EDGE:
						ClrBit(EXTI_RTSR,15);
						SetBit(EXTI_FTSR,15);
						break;
					case LEVEL_CHANGE:
						SetBit(EXTI_FTSR,15);
						SetBit(EXTI_RTSR,15);
						break;
					default:
						ClrBit(EXTI_FTSR,15);
						ClrBit(EXTI_RTSR,15);
						break;
					}
					SetBit(NVIC_ISER1,8);
					break;
		default:break;
	}
}


void EXTI_Priority(EXTI exti,PRIORITY_LEVEL priority_level)
{
	switch(exti)
	{
	case EXTI0: //6
		InsertField(NVIC_IPR1,0xFF00FFFF,priority_level,16);
		break;
	case EXTI1: //7
		InsertField(NVIC_IPR1,0x00FFFFFF,priority_level,24);
		break;
	case EXTI2: //8
		InsertField(NVIC_IPR2,0xFFFFFF00,priority_level,0);
		break;
	case EXTI3: //9
		InsertField(NVIC_IPR2,0xFFFF00FF,priority_level,8);
		break;
	case EXTI4:
		InsertField(NVIC_IPR2,0xFFFFFF00,priority_level,0);
		break;
	case EXTI5:
		InsertField(NVIC_IPR5,0x00FFFFFF,priority_level,24);
		break;
	case EXTI6:
		InsertField(NVIC_IPR5,0x00FFFFFF,priority_level,24);
		break;
	case EXTI7:
		InsertField(NVIC_IPR5,0x00FFFFFF,priority_level,24);
		break;
	case EXTI8:
		InsertField(NVIC_IPR5,0x00FFFFFF,priority_level,24);
		break;
	case EXTI9:
		InsertField(NVIC_IPR5,0x00FFFFFF,priority_level,24);
		break;
	case EXTI10:
		InsertField(NVIC_IPR10,0xFFFFFF00,priority_level,0);
		break;
	case EXTI11:
		InsertField(NVIC_IPR10,0xFFFFFF00,priority_level,0);
		break;
	case EXTI12:
		InsertField(NVIC_IPR10,0xFFFFFF00,priority_level,0);
		break;
	case EXTI13:
		InsertField(NVIC_IPR10,0xFFFFFF00,priority_level,0);
		break;
	case EXTI14:
		InsertField(NVIC_IPR10,0xFFFFFF00,priority_level,0);
		break;
	case EXTI15:
		InsertField(NVIC_IPR10,0xFFFFFF00,priority_level,0);
		break;
	default:break;
	}
}

void EXTI_Enable(EXTI exti)
{
	switch(exti)
	{
	case EXTI0:
		SetBit(EXTI_IMR,0);
		break;
	case EXTI1:
		SetBit(EXTI_IMR,1);
		break;
	case EXTI2:
		SetBit(EXTI_IMR,2);
		break;
	case EXTI3:
		SetBit(EXTI_IMR,3);
		break;
	case EXTI4:
		SetBit(EXTI_IMR,4);
		break;
	case EXTI5:
		SetBit(EXTI_IMR,5);
		break;
	case EXTI6:
		SetBit(EXTI_IMR,6);
		break;
	case EXTI8:
		SetBit(EXTI_IMR,8);
		break;
	case EXTI9:
		SetBit(EXTI_IMR,9);
		break;
	case EXTI10:
		SetBit(EXTI_IMR,10);
		break;
	case EXTI11:
		SetBit(EXTI_IMR,11);
		break;
	case EXTI12:
		SetBit(EXTI_IMR,12);
		break;
	case EXTI13:
		SetBit(EXTI_IMR,13);
		break;
	case EXTI14:
		SetBit(EXTI_IMR,14);
		break;
	case EXTI15:
		SetBit(EXTI_IMR,15);
		break;
	default:break;
	}
}

void EXTI_Disable(EXTI exti)
{
	switch(exti)
	{
	case EXTI0:
		ClrBit(EXTI_IMR,0);
		break;
	case EXTI1:
		ClrBit(EXTI_IMR,1);
		break;
	case EXTI2:
		ClrBit(EXTI_IMR,2);
		break;
	case EXTI3:
		ClrBit(EXTI_IMR,3);
		break;
	case EXTI4:
		ClrBit(EXTI_IMR,4);
		break;
	case EXTI5:
		ClrBit(EXTI_IMR,5);
		break;
	case EXTI6:
		ClrBit(EXTI_IMR,6);
		break;
	case EXTI7:
		ClrBit(EXTI_IMR,7);
		break;
	case EXTI8:
		ClrBit(EXTI_IMR,8);
		break;
	case EXTI9:
		ClrBit(EXTI_IMR,9);
		break;
	case EXTI10:
		ClrBit(EXTI_IMR,10);
		break;
	case EXTI11:
		ClrBit(EXTI_IMR,11);
		break;
	case EXTI12:
		ClrBit(EXTI_IMR,12);
		break;
	case EXTI13:
		ClrBit(EXTI_IMR,13);
		break;
	case EXTI14:
		ClrBit(EXTI_IMR,14);
		break;
	case EXTI15:
		ClrBit(EXTI_IMR,15);
		break;
	default:break;
	}
}

void (*EXTI0_PTR)(void) = 0;
void (*EXTI1_PTR)(void) = 0;
void (*EXTI2_PTR)(void) = 0;
void (*EXTI3_PTR)(void) = 0;
void (*EXTI4_PTR)(void) = 0;

void (*EXTI5_PTR)(void) = 0;
void (*EXTI10_PTR)(void) = 0;

void EXTI_SetISR(EXTI exti,void (*ptr)(void))
{
	switch(exti)
	{
		case EXTI0:
			EXTI0_PTR = ptr;
			break;
		case EXTI1:
			EXTI1_PTR = ptr;
			break;
		case EXTI2:
			EXTI2_PTR = ptr;
			break;
		case EXTI3:
			EXTI3_PTR = ptr;
			break;
		case EXTI4:
			EXTI4_PTR = ptr;
			break;
		case EXTI5:
			EXTI5_PTR = ptr;
			break;
		case EXTI6:
			EXTI5_PTR = ptr;
			break;
		case EXTI7:
			EXTI5_PTR = ptr;
			break;
		case EXTI8:
			EXTI5_PTR = ptr;
			break;
		case EXTI9:
			EXTI5_PTR = ptr;
			break;
		case EXTI10:
			EXTI10_PTR = ptr;
			break;
		case EXTI11:
			EXTI10_PTR = ptr;
			break;
		case EXTI12:
			EXTI10_PTR = ptr;
			break;
		case EXTI13:
			EXTI10_PTR = ptr;
			break;
		case EXTI14:
			EXTI10_PTR = ptr;
			break;
		case EXTI15:
			EXTI10_PTR = ptr;
			break;
	}
}

//Interrupt Section

// Clear interrupt flag bit first then execute your code
// to avoid the problem (interrupt come while you are executing the current ISR

void EXTI0_IRQHandler(void)
{
	SetBit(EXTI_PR,0);//clear pending bit

	EXTI0_PTR();
}
void EXTI1_IRQHandler(void)
{
	SetBit(EXTI_PR,1);

	EXTI1_PTR();
}

void EXTI2_IRQHandler(void)
{
    SetBit(EXTI_PR,2);

    EXTI2_PTR();
}

void EXTI3_IRQHandler(void)
{
	SetBit(EXTI_PR,3);

	EXTI3_PTR();
}

void EXTI4_IRQHandler(void)
{
	SetBit(EXTI_PR,4);

	EXTI4_PTR();
}


void EXTI9_5_IRQHandler(void)
{
	if(GetBit(EXTI_PR,5))
		SetBit(EXTI_PR,5);
	if(GetBit(EXTI_PR,6))
		SetBit(EXTI_PR,6);
	if(GetBit(EXTI_PR,7))
		SetBit(EXTI_PR,7);
	if(GetBit(EXTI_PR,8))
		SetBit(EXTI_PR,8);
	if(GetBit(EXTI_PR,9))
		SetBit(EXTI_PR,9);

	EXTI5_PTR();
}

void EXTI15_10_IRQHandler(void)
{
	if(GetBit(EXTI_PR,10))
		SetBit(EXTI_PR,10);
	if(GetBit(EXTI_PR,11))
		SetBit(EXTI_PR,11);
	if(GetBit(EXTI_PR,12))
		SetBit(EXTI_PR,12);
	if(GetBit(EXTI_PR,13))
		SetBit(EXTI_PR,13);
	if(GetBit(EXTI_PR,14))
		SetBit(EXTI_PR,14);
	if(GetBit(EXTI_PR,15))
		SetBit(EXTI_PR,15);

	EXTI10_PTR();
}

