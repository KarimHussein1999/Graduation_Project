/*
 * I2C.h
 *
 *  Created on: Jan 31, 2021
 *      Author: Karim Hussein
 */

#ifndef I2C_H_
#define I2C_H_

typedef enum {I2C1 , I2C2}I2C;
typedef enum {Transmitter , Reciever}DIRECTION;

void I2C_Init(I2C i2c);
void I2C_Config (I2C i2c,DIRECTION direction);
void I2C_Tx_SetISR(I2C i2c, void (*ptr)(void));
void I2C_Rx_SetISR(I2C i2c, void (*ptr)(void));
void I2C_Strat_Communication(I2C i2c);
void I2C_Stop_Communication(I2C i2c);
void I2C_Set_ACKBit(I2C i2c);
void I2C_Clr_ACKBit(I2C i2c);
void I2C_Clr_ACKFailure(I2C i2c);
void I2C_Clr_ByteTransferFinish(I2C i2c);
void I2C_SetData(I2C i2c , unsigned char data);
unsigned char I2C_Read(I2C i2c);

unsigned char I2C_GetStatus(I2C i2c);
unsigned char I2C_Start_Bit_Sent(I2C i2c);
unsigned char I2C_ACK_Failure(I2C i2c);
unsigned char I2C_ByteTransferFinish(I2C i2c);
unsigned char I2C_Address_Sent(I2C i2c);
unsigned char I2C_Data_Sent(I2C i2c);
unsigned char I2C_Data_Recieved(I2C i2c);


#endif /* I2C_H_ */
