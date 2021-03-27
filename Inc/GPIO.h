/*
 * GPIO.h
 *
 *  Created on: Dec 15, 2020
 *      Author: Karim Hussein
 */

#ifndef GPIO_H_
#define GPIO_H_

typedef enum {PORTA , PORTB , PORTC ,PORTD}PORT;
typedef enum {PIN0 , PIN1 , PIN2 , PIN3 , PIN4 , PIN5 ,PIN6 ,
	PIN7 , PIN8 , PIN9 , PIN10 , PIN11 , PIN12 , PIN13 , PIN14 ,
	PIN15
}PIN;
typedef enum {INPUT_PIN , OUTPUT_PIN}PIN_DIR;
typedef enum { PIN_LOW = 0 , PIN_HIGH = 1 }PIN_STATE;
// Output --> Open Drain && Push Pull   ||  Input --> Analog && Floating && Pull up && Pull down
typedef enum {AF_OD,AF_PP,Open_Drain,Push_Pull,Analog,Floating,Pull_Up,Pull_Down}PIN_MODE;

void GPIO_Init(PORT port);
void GPIO_PinDirection(PORT port,PIN pin,PIN_DIR pin_dir,PIN_MODE pin_mode);
void GPIO_PinWrite(PORT port,PIN pin,PIN_STATE pin_state);
unsigned char GPIO_PinRead(PORT port, PIN pin);
void GPIO_PortWrite(PORT port,unsigned short data);
unsigned short GPIO_PortRead(PORT port);

#endif /* GPIO_H_ */
