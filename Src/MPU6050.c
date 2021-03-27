#include "util.h"
#include "I2C.h"
#include "MPU6050.h"

// Configuration
#define MPU6050_I2C I2C1
#define	MPU6050_DIRECTION Reciever
#define MPU6050_ADDRESS 0b01101000

unsigned char RA = 0;
unsigned char Tx_DATA = 0;
unsigned char Rx_DATA = 0;

unsigned char Read_Request = 0 , Write_Request = 0;

void I2C_Tx(void);
void I2C_Rx(void);

void MPU6050_Init(void)
{
	I2C_Init(MPU6050_I2C);
	I2C_Tx_SetISR(MPU6050_I2C, I2C_Tx);
	I2C_Rx_SetISR(MPU6050_I2C, I2C_Rx);
}

void MPU6050_Read_Request(unsigned char Register_Address)
{
	if(!Read_Request)
	{
		Read_Request = 1;
		RA = Register_Address;
		I2C_Set_ACKBit(MPU6050_I2C); // Activate ACK Bit
		I2C_Config (MPU6050_I2C,Reciever);
		I2C_Strat_Communication(MPU6050_I2C);
	}
}
void MPU6050_Write_Request(unsigned char Register_Address,unsigned char Data)
{
	if(!Write_Request)
	{
		Write_Request = 1;
		RA = Register_Address;
		Tx_DATA = Data;
		I2C_Set_ACKBit(MPU6050_I2C); // Activate ACK Bit
		I2C_Config (MPU6050_I2C,Transmitter);
		I2C_Strat_Communication(MPU6050_I2C);
	}
}

unsigned char MPU6050_Read(void)
{
	return(Rx_DATA);
}



// CALL BACK FUNCTIONS
void I2C_Tx(void)
{
	if(I2C_Start_Bit_Sent(MPU6050_I2C))
		I2C_SetData(MPU6050_I2C , MPU6050_ADDRESS<<1);

	if(I2C_ACK_Failure(MPU6050_I2C))
		I2C_Clr_ACKFailure(MPU6050_I2C);

	if(I2C_ByteTransferFinish(MPU6050_I2C))
		I2C_Clr_ByteTransferFinish(MPU6050_I2C);

	if(I2C_Address_Sent(MPU6050_I2C))
	{
		I2C_GetStatus(MPU6050_I2C); // to clear ADDR Flag
		I2C_SetData(MPU6050_I2C , RA);
	}
	if(I2C_Data_Sent(MPU6050_I2C))
	{
		I2C_SetData(MPU6050_I2C , Tx_DATA);
		I2C_Stop_Communication(MPU6050_I2C); // to close communication
		Write_Request = 0;
	}
}
void I2C_Rx(void)
{
	static unsigned char flag = 0;

	if (!flag)
	{
		if(I2C_Start_Bit_Sent(MPU6050_I2C))
			I2C_SetData(MPU6050_I2C , MPU6050_ADDRESS<<1); // AD + W

		if(I2C_ACK_Failure(MPU6050_I2C))
			I2C_Clr_ACKFailure(MPU6050_I2C);

		if(I2C_ByteTransferFinish(MPU6050_I2C))
			I2C_Clr_ByteTransferFinish(MPU6050_I2C);

		if(I2C_Address_Sent(MPU6050_I2C))
		{
			// Clear ADDR Flag
			I2C_GetStatus(MPU6050_I2C);
			I2C_SetData(MPU6050_I2C , RA);
		}
		if(I2C_Data_Sent(MPU6050_I2C))
		{
			// Stop Communication
			I2C_Start_Communication(MPU6050_I2C);
			flag = 1;
		}
	}
	else
	{
		if(I2C_Start_Bit_Sent(MPU6050_I2C))
			I2C_SetData(MPU6050_I2C , ((MPU6050_ADDRESS<<1) + 1)); // AD + R

		if(I2C_ACK_Failure(MPU6050_I2C))
			I2C_Clr_ACKFailure(MPU6050_I2C);

		if(I2C_ByteTransferFinish(MPU6050_I2C))
			I2C_Clr_ByteTransferFinish(MPU6050_I2C);

		if(I2C_Address_Sent(MPU6050_I2C))
		{
			// Clear ACK Bit Here
			I2C_Clr_ACKBit(MPU6050_I2C);
			// Clear ADDR Flag
			I2C_GetStatus(MPU6050_I2C);
			// Program Stop Communication Here
			I2C_Stop_Communication(MPU6050_I2C);
		}
		if(I2C_Data_Recieved(MPU6050_I2C))
		{
			Rx_DATA = I2C_Read(MPU6050_I2C);
			Read_Request = 0;
			flag = 0;
		}
	}
}
