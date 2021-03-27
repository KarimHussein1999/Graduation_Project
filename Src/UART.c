/*
 * UART.c
 *
 *  Created on: Jan 15, 2021
 *      Author: Karim Hussein
 */

/*
 *   Baud Rate Eqn = Freq / (16 * Register)
 *   Register = 52.0833333 --> Baud Rate 9600 --> Freq 8 MHz
 */

#include "UART.h"
#include "util.h"
#include "GPIO.h"
#include "Regmap.h"

unsigned char Tx1_FLAG = 0;
unsigned char Tx2_FLAG = 0;
unsigned char Tx3_FLAG = 0;

unsigned char Rx1_FLAG = 0;
unsigned char Rx2_FLAG = 0;
unsigned char Rx3_FLAG = 0;


// No Remapping Here in this version

void UART_Init(UART uart)
{
	switch(uart)
	{
		case UART1:
			// Connect Clock To GPIOA
			if(!GetBit(RCC_APB2ENR,2))
				SetBit(RCC_APB2ENR,2);
			// Connect Cloct To UART1
			SetBit(RCC_APB2ENR,14);
			// Configure Alternative Function
			GPIO_PinDirection(PORTA ,PIN9 ,OUTPUT_PIN,AF_PP); // Tx
			GPIO_PinDirection(PORTA,PIN10,INPUT_PIN,Floating); // Rx
			// Activate NVIC Bit
			SetBit(NVIC_ISER1,5);
			// Configure Baud Rate (9600) - 1 Start Bit & 8 Bits Data & 1 Stop Bit
			InsertField(UART1_BRR,0xFFFF000F,52,4);
			InsertField(UART1_BRR,0xFFFFFFF0,1,0);
			break;
		case UART2:
			// Connect Clock To GPIOA
			if(!GetBit(RCC_APB2ENR,2))
				SetBit(RCC_APB2ENR,2);
			// Connect Clock To UART2
			SetBit(RCC_APB1ENR,17);
			// Configure Alternative Function
			GPIO_PinDirection(PORTA ,PIN2 ,OUTPUT_PIN,AF_PP); // Tx
			GPIO_PinDirection(PORTA,PIN3,INPUT_PIN,Floating); // Rx
			// Activate NVIC Bit
			SetBit(NVIC_ISER1,6);
			// Configure Baud Rate (9600) - 1 Start Bit & 8 Bits Data & 1 Stop Bit
			InsertField(UART2_BRR,0xFFFF000F,52,4);
			InsertField(UART2_BRR,0xFFFFFFF0,1,0);
			break;
		case UART3:
			// Connect Clock To GPIOB
			if(!GetBit(RCC_APB2ENR,3))
				SetBit(RCC_APB2ENR,3);
			// Connect Clock To UART3
			SetBit(RCC_APB1ENR,18);
			// Configure Alternative Function
			GPIO_PinDirection(PORTB ,PIN10 ,OUTPUT_PIN,AF_PP); // Tx
			GPIO_PinDirection(PORTB,PIN11,INPUT_PIN,Floating); // Rx
			// Activate NVIC Bit
			SetBit(NVIC_ISER1,7);
			// Configure Baud Rate (9600) - 1 Start Bit & 8 Bits Data & 1 Stop Bit
			InsertField(UART3_BRR,0xFFFF000F,52,4);
			InsertField(UART3_BRR,0xFFFFFFF0,1,0);
			break;
		default:break;
	}
}


void UART_Send(UART uart,unsigned char data)
{
	switch(uart)
	{
		case UART1:
			if(Tx1_FLAG)
			{
				Tx1_FLAG = 0;
				UART1_DR = data ;
			}
			break;
		case UART2:
			if(Tx2_FLAG)
			{
				Tx2_FLAG = 0;
				UART2_DR = data;
			}
			break;
		case UART3:
			if(Tx3_FLAG)
			{
				Tx3_FLAG = 0;
				UART3_DR = data;
			}
			break;
		default:break;
	}
}
unsigned char UART_Recieve(UART uart)
{
	switch(uart)
	{
		case UART1:
			if(Rx1_FLAG)
			{
				Rx1_FLAG = 0;
				return (UART1_DR);
			}
			else
			{
				return 0;
			}
			break;
		case UART2:
			if(Rx2_FLAG)
			{
				Rx2_FLAG = 0;
				return (UART2_DR);
			}
			else
			{
				return 0;
			}
			break;
		case UART3:
			if(Rx3_FLAG)
			{
				Rx3_FLAG = 0;
				return (UART3_DR);
			}
			else
			{
				return (0);
			}
			break;
	}
}

void UART_Direction(UART uart,UART_Mode uart_mode)
{
	switch(uart)
	{
	case UART1:
		if(uart_mode == Tx)
		{
			SetBit(UART1_CR1,3);
		}
		else if (uart_mode == Rx)
		{
			SetBit(UART1_CR1,2);
		}
		else
		{
			SetBit(UART1_CR1,2);
			SetBit(UART1_CR1,3);
		}
		break;
	case UART2:
		if(uart_mode == Tx)
		{
			SetBit(UART2_CR1,3);
		}
		else if (uart_mode == Rx)
		{
			SetBit(UART2_CR1,2);
		}
		else
		{
			SetBit(UART2_CR1,2);
			SetBit(UART2_CR1,3);
		}
		break;
	case UART3:
		if(uart_mode == Tx)
		{
			SetBit(UART3_CR1,3);
		}
		else if (uart_mode == Rx)
		{
			SetBit(UART3_CR1,2);
		}
		else
		{
			SetBit(UART3_CR1,2);
			SetBit(UART3_CR1,3);
		}
		break;
	}
}
void UART_Enable(UART uart)
{
	switch(uart)
	{
	case UART1:
		SetBit(UART1_CR1,13);
		break;
	case UART2:
		SetBit(UART2_CR1,13);
		break;
	case UART3:
		SetBit(UART3_CR1,13);
		break;
	}
}
void UART_Disable(UART uart)
{
	switch(uart)
	{
	case UART1:
		ClrBit(UART1_CR1,13);
		break;
	case UART2:
		ClrBit(UART2_CR1,13);
		break;
	case UART3:
		ClrBit(UART3_CR1,13);
		break;
	}
}
///////////////////////////////////// Interrupt /////////////////////////////////
void UART_ActivateInterrupt(UART uart)
{
	switch(uart)
	{
		case UART1:
			// Transmission Complete
			SetBit(UART1_CR1,6);
			// Receiving Complete
			SetBit(UART1_CR1,5);
			break;
		case UART2:
			// Transmission Complete
			SetBit(UART2_CR1,6);
			// Receiving Complete
			SetBit(UART2_CR1,5);
			break;
		case UART3:
			// Transmission Complete
			SetBit(UART3_CR1,6);
			// Receiving Complete
			SetBit(UART3_CR1,5);
			break;
		default:break;
	}
}


void USART1_IRQHandler(void)
{
	if (GetBit(UART1_SR,5))
	{
		ClrBit(UART1_SR,5);
		Rx1_FLAG = 1;
	}
	else if(GetBit(UART1_SR,6))
	{
		ClrBit(UART1_SR,6);
		Tx1_FLAG = 1;
	}
}
void USART2_IRQHandler(void)
{
	if (GetBit(UART2_SR,5))
	{
		ClrBit(UART2_SR,5);
		Rx2_FLAG = 1;
	}
	else if(GetBit(UART2_SR,6))
	{
		ClrBit(UART2_SR,6);
		Tx2_FLAG = 1;
	}
}
void USART3_IRQHandler(void)
{
	if (GetBit(UART3_SR,5))
	{
		ClrBit(UART3_SR,5);
		Rx3_FLAG = 1;
	}
	else if(GetBit(UART3_SR,6))
	{
		ClrBit(UART3_SR,6);
		Tx3_FLAG = 1;
	}
}
