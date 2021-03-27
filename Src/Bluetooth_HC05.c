/*
 * Bluetooth_HC05.c
 *
 *  Created on: Jan 16, 2021
 *      Author: Karim Hussein
 */


#include "Bluetooth_HC05.h"
#include "UART.h"
#include "GPIO.h"

// Setting
#define Bluetooth_UART  UART1

// Note That The Baud Rate For COMMAND Mode is 38400 bps (Program Using TeraTerminal + RST Button)
// Note	That The Baud Rate for DATA Mode is 9600 bps (You Can Change)

void Bluetooth_Init(void)
{
	UART_Init(Bluetooth_UART);
	UART_Direction(Bluetooth_UART,Tx_Rx);
	UART_ActivateInterrupt(Bluetooth_UART);
	UART_Enable(Bluetooth_UART);

}
void Bluetooth_Send(unsigned char data)
{
	UART_Send(Bluetooth_UART,data);
}
unsigned char Bluetooth_Read(void)
{
	return(UART_Recieve(Bluetooth_UART));
}
