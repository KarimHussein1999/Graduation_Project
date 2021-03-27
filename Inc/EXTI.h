/*
 * EXTI.h
 *
 *  Created on: Dec 17, 2020
 *      Author: Karim Hussein
 */

#ifndef EXTI_H_
#define EXTI_H_

#ifndef GPIO_H
#include "GPIO.h"
#endif

// EXTI0 --> PA0 , PB0 , PC0
// EXTI1 --> PA1 , PB1 , PC1
// EXTI2 --> PA2 , PB2 , PC2

typedef enum {EXTI0 , EXTI1 , EXTI2 , EXTI3 , EXTI4 , EXTI5 , EXTI6 ,
	EXTI7 , EXTI8 , EXTI9 , EXTI10 , EXTI11 , EXTI12 , EXTI13 , EXTI14,
	EXTI15
}EXTI;

typedef enum {LEVEL0 = 0,LEVEL1 = 16,LEVEL2 = 32,LEVEL3 = 48,LEVEL4 = 64,LEVEL5 = 80,LEVEL6 = 96,LEVEL7 = 112,LEVEL8 = 128,
	LEVEL9 = 144,LEVEL10 = 160,LEVEL11 = 176,LEVEL12 = 192,LEVEL13 = 208,LEVEL14 = 224,LEVEL15 = 240
}PRIORITY_LEVEL;

typedef enum {RISING_EDGE , FALLING_EDGE , LEVEL_CHANGE}INTERRUPT_CONDITION;

// You must configure  the External interrupt pin as Input GPIO Pin
void EXTI_Init(EXTI exti ,PORT port ,INTERRUPT_CONDITION int_src);
void EXTI_Priority(EXTI exti,PRIORITY_LEVEL priority_level); // the lower number the higher priority
void EXTI_Enable(EXTI exti);
void EXTI_Disable(EXTI exti);
void EXTI_SetISR(EXTI exti,void (*ptr)(void));


#endif /* EXTI_H_ */
