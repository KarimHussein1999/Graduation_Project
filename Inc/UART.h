/*
 * UART.h
 *
 *  Created on: Jan 15, 2021
 *      Author: Karim Hussein
 */

#ifndef UART_H_
#define UART_H_

typedef enum {UART1 , UART2 , UART3}UART;
typedef enum {Tx , Rx , Tx_Rx}UART_Mode;


void UART_Init(UART uart);
void UART_Send(UART uart,unsigned char data);
unsigned char UART_Recieve(UART uart);
void UART_Direction(UART uart,UART_Mode uart_mode);
void UART_ActivateInterrupt(UART uart);
void UART_Enable(UART uart);
void UART_Disable(UART uart);



#endif /* UART_H_ */
