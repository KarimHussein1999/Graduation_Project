/*
 * Bluetooth_HC05.h
 *
 *  Created on: Jan 16, 2021
 *      Author: Karim Hussein
 */

#ifndef BLUETOOTH_HC05_H_
#define BLUETOOTH_HC05_H_

void Bluetooth_Init(void);
void Bluetooth_Send(unsigned char data);
unsigned char Bluetooth_Read(void);

#endif /* BLUETOOTH_HC05_H_ */
