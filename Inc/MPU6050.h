/*
 * MPU6050.h
 *
 *  Created on: Mar 26, 2021
 *      Author: Karim Hussein
 */

#ifndef MPU6050_H_
#define MPU6050_H_

void MPU6050_Init(void);
void MPU6050_Read_Request(unsigned char Register_Address);
void MPU6050_Write_Request(unsigned char Register_Address,unsigned char Data); // Used To Configure MPU6050
unsigned char MPU6050_Read(void);

#endif /* MPU6050_H_ */
