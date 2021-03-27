/*
 * I2C.c
 *
 *  Created on: Jan 31, 2021
 *      Author: Karim Hussein
 */


// Master Mode 7Bit Address Mode with ACK Bit & CLK Stretching
// Search for I2C Bus Pull Up Resistance Calculation
// Pull Up Resistor --> 2.2Kohm to 10Kohm


#include "Regmap.h"
#include "util.h"
#include "I2C.h"

unsigned char flag1,flag2;

void (*I2C_Tx1)(void) = 0;
void (*I2C_Rx1)(void) = 0;
void (*I2C_Tx2)(void) = 0;
void (*I2C_Rx2)(void) = 0;

void I2C_Init(I2C i2c)
{
	switch(i2c)
	{
		case I2C1:
			// Connect GPIO Clock
			if(!GetBit(RCC_APB2ENR,3))
				SetBit(RCC_APB2ENR,3);

			// Connect I2C1 Clock
			SetBit(RCC_APB1ENR,21);

			// GPIO Configurations
			GPIOB_CRL |= 0xFF000000;


			// Timing Setting
			I2C1_CR2 = 8; // 8 MHz  -- 8
			I2C1_CCR = 40; //for  100 KHz -->   40  &&  for 50 KHz --> 160
			I2C1_TRISE = 9;// maximum rise time 1000ns -->  9

			//Enable Interrupt
			SetBit(I2C1_CR2,9);
			// Enable Interrupt
			SetBit(NVIC_ISER0,31);


			// Enable Peripheral
			I2C1_CR1 |= 1<<0;


			break;
		case I2C2:
			// Connect GPIO Clock
			if(!GetBit(RCC_APB2ENR,3))
				SetBit(RCC_APB2ENR,3);

			// Connect I2C2 Clock
			SetBit(RCC_APB1ENR,22);

			// GPIO Configurations
			GPIOB_CRH |= 0x0000FF00;

			// Timing Setting
			I2C2_CR2 = 8; // 8 MHz
			I2C2_CCR = 40; // 100 KHz
			I2C2_TRISE = 9;// maximum rise time 1000ns

			//Enable Interrupt
			SetBit(I2C2_CR2,9);
			// Enable Interrupt
			SetBit(NVIC_ISER1,1);

			// Enable Peripheral
			I2C2_CR1 |= 1<<0;

			break;
		default:break;
	}
}
void I2C_Config (I2C i2c,DIRECTION direction)
{
	switch(i2c)
	{
		case I2C1:
			if (direction == Transmitter)
				flag1 = 1;
			else if (direction == Reciever)
				flag1 = 0;
			break;
		case I2C2:
			if (direction == Transmitter)
				flag2 = 1;
			else if (direction == Reciever)
				flag2 = 0;
			break;
		default:break;
	}
}
void I2C_Tx_SetISR(I2C i2c, void (*ptr)(void))
{
	switch(i2c)
	{
		case I2C1:
			I2C_Tx1 = ptr;
			break;
		case I2C2:
			I2C_Tx2 = ptr;
			break;
		default:break;
	}
}
void I2C_Rx_SetISR(I2C i2c, void (*ptr)(void))
{
	switch(i2c)
	{
		case I2C1:
			I2C_Rx1 = ptr;
			break;
		case I2C2:
			I2C_Rx2 = ptr;
			break;
		default:break;
	}
}
void I2C_Strat_Communication(I2C i2c)
{
	switch(i2c)
	{
		case I2C1:
			// Start Transmission
			SetBit(I2C1_CR1,8);
			break;
		case I2C2:
			// Start Transmission
			SetBit(I2C2_CR1,8);
			break;
	}
}
void I2C_Stop_Communication(I2C i2c)
{
	switch(i2c)
	{
		case I2C1:
			// Stop Transmission
			SetBit(I2C1_CR1,9);
			break;
		case I2C2:
			// Stop Transmission
			SetBit(I2C2_CR1,9);
			break;
	}
}
void I2C_Set_ACKBit(I2C i2c)
{
	switch(i2c)
	{
		case I2C1:
			// Set ACK Bit
			SetBit(I2C1_CR1,10);
			break;
		case I2C2:
			// Set ACK Bit
			SetBit(I2C2_CR1,10);
			break;
	}
}
void I2C_Clr_ACKBit(I2C i2c)
{
	switch(i2c)
	{
		case I2C1:
			// Clear ACK Bit
			ClrBit(I2C1_CR1,10);
			break;
		case I2C2:
			// Clear ACK Bit
			ClrBit(I2C2_CR1,10);
			break;
	}
}
void I2C_Clr_ACKFailure(I2C i2c)
{
	switch(i2c)
	{
		case I2C1:
			// Clear ACK Failure Bit
			ClrBit(I2C1_SR1,10);
			break;
		case I2C2:
			// Clear ACK Failure Bit
			ClrBit(I2C2_SR1,10);
			break;
	}
}
void I2C_Clr_ByteTransferFinish(I2C i2c)
{
	switch(i2c)
	{
		case I2C1:
			I2C1_SR1; // Read SR1
			I2C1_DR; // Read DR
			break;
		case I2C2:
			I2C2_SR1; // Read SR1
			I2C2_DR; // Read DR
			break;
	}
}
void I2C_SetData(I2C i2c , unsigned char data)
{
	switch(i2c)
	{
		case I2C1:
			I2C1_DR = data;
			break;
		case I2C2:
			I2C2_DR = data;
			break;
		default:break;
	}
}
unsigned char I2C_Read(I2C i2c)
{
	switch(i2c)
	{
		case I2C1:return(I2C1_DR);
		case I2C2:return(I2C2_DR);
	}
}
unsigned char I2C_GetStatus(I2C i2c)
{
	switch(i2c)
	{
		case I2C1:
			return(I2C1_SR2);
			break;
		case I2C2:
			return(I2C2_SR2);
			break;
		default:break;
	}
}
unsigned char I2C_Start_Bit_Sent(I2C i2c)
{
	switch(i2c)
	{
		case I2C1:
			return(GetBit(I2C1_SR1,0));
			break;
		case I2C2:
			return(GetBit(I2C2_SR1,0));
			break;
		default:break;
	}
}
unsigned char I2C_ACK_Failure(I2C i2c)
{
	switch(i2c)
	{
		case I2C1:
			return(GetBit(I2C1_SR1,10));
			break;
		case I2C2:
			return(GetBit(I2C2_SR1,10));
			break;
		default:break;
	}
}
unsigned char I2C_ByteTransferFinish(I2C i2c)
{
	switch(i2c)
	{
		case I2C1:
			return(GetBit(I2C1_SR1,2));
			break;
		case I2C2:
			return(GetBit(I2C2_SR1,2));
			break;
		default:break;
	}
}
unsigned char I2C_Address_Sent(I2C i2c)
{
	switch(i2c)
	{
		case I2C1:
			return(GetBit(I2C1_SR1,1));
			break;
		case I2C2:
			return(GetBit(I2C2_SR1,1));
			break;
		default:break;
	}
}
unsigned char I2C_Data_Sent(I2C i2c)
{
	switch(i2c)
	{
		case I2C1:
			return(GetBit(I2C1_SR1,7));
			break;
		case I2C2:
			return(GetBit(I2C2_SR1,7));
			break;
		default:break;
	}
}
unsigned char I2C_Data_Recieved(I2C i2c)
{
	switch(i2c)
	{
		case I2C1:
			return(GetBit(I2C1_SR1,6));
			break;
		case I2C2:
			return(GetBit(I2C2_SR1,6));
			break;
		default:break;
	}
}
void I2C1_EV_IRQHandler (void)
{
	if(flag1)
		I2C_Tx1();
	else
		I2C_Rx1();
}
void I2C2_EV_IRQHandler (void)
{
	if(flag2)
		I2C_Tx2();
	else
		I2C_Rx2();
}
