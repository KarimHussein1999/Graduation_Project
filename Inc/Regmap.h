/*
 * Regmap.h
 *
 *  Created on: Dec 15, 2020
 *      Author: Karim Hussein
 */

#ifndef REGMAP_
#define REGMAP_

// Base Addresses
#define GPIO_PORTA_BASE   0x40010800
#define GPIO_PORTB_BASE   0x40010C00
#define GPIO_PORTC_BASE   0x40011000
#define GPIO_PORTD_BASE   0x40011400
#define GPIO_PORTE_BASE   0x40011800
#define GPIO_PORTF_BASE   0x40011C00
#define GPIO_PORTG_BASE   0x40012000

// Offsets
#define GPIO_CRL    0x00
#define GPIO_CRH    0x04
#define GPIO_IDR    0x08
#define GPIO_ODR    0x0C
#define GPIO_BSRR   0x10
#define GPIO_BRR    0x14
#define GPIO_LCKR   0x18


#define  GPIOA_CRL *((volatile unsigned int*)(GPIO_PORTA_BASE + GPIO_CRL))
#define  GPIOB_CRL *((volatile unsigned int*)(GPIO_PORTB_BASE + GPIO_CRL))
#define  GPIOC_CRL *((volatile unsigned int*)(GPIO_PORTC_BASE + GPIO_CRL))
#define  GPIOD_CRL *((volatile unsigned int*)(GPIO_PORTD_BASE + GPIO_CRL))

#define  GPIOA_CRH *((volatile unsigned int*)(GPIO_PORTA_BASE + GPIO_CRH))
#define  GPIOB_CRH *((volatile unsigned int*)(GPIO_PORTB_BASE + GPIO_CRH))
#define  GPIOC_CRH *((volatile unsigned int*)(GPIO_PORTC_BASE + GPIO_CRH))
#define  GPIOD_CRH *((volatile unsigned int*)(GPIO_PORTD_BASE + GPIO_CRH))

#define  GPIOA_IDR *((volatile unsigned int*)(GPIO_PORTA_BASE + GPIO_IDR))
#define  GPIOB_IDR *((volatile unsigned int*)(GPIO_PORTB_BASE + GPIO_IDR))
#define  GPIOC_IDR *((volatile unsigned int*)(GPIO_PORTC_BASE + GPIO_IDR))
#define  GPIOD_IDR *((volatile unsigned int*)(GPIO_PORTD_BASE + GPIO_IDR))

#define  GPIOA_ODR *((volatile unsigned int*)(GPIO_PORTA_BASE + GPIO_ODR))
#define  GPIOB_ODR *((volatile unsigned int*)(GPIO_PORTB_BASE + GPIO_ODR))
#define  GPIOC_ODR *((volatile unsigned int*)(GPIO_PORTC_BASE + GPIO_ODR))
#define  GPIOD_ODR *((volatile unsigned int*)(GPIO_PORTD_BASE + GPIO_ODR))

#define  GPIOA_BSRR *((volatile unsigned int*)(GPIO_PORTA_BASE + GPIO_BSRR))
#define  GPIOB_BSRR *((volatile unsigned int*)(GPIO_PORTB_BASE + GPIO_BSRR))
#define  GPIOC_BSRR *((volatile unsigned int*)(GPIO_PORTC_BASE + GPIO_BSRR))
#define  GPIOD_BSRR *((volatile unsigned int*)(GPIO_PORTD_BASE + GPIO_BSRR))

#define  GPIOA_BRR *((volatile unsigned int*)(GPIO_PORTA_BASE + GPIO_BRR))
#define  GPIOB_BRR *((volatile unsigned int*)(GPIO_PORTB_BASE + GPIO_BRR))
#define  GPIOC_BRR *((volatile unsigned int*)(GPIO_PORTC_BASE + GPIO_BRR))
#define  GPIOD_BRR *((volatile unsigned int*)(GPIO_PORTD_BASE + GPIO_BRR))



// Base
#define RCC 0x40021000

// Offset
#define RCR 			0x00
#define RCFGR    	0x04
#define RCIR     	0x08
#define RAPB2RSTR 	0x0C
#define RAPB1RSTR    0x10
#define RAHBENR      0x14
#define RAPB2ENR     0x18
#define RAPB1ENR     0x1C
#define RBDCR        0x20
#define RCSR         0x24

// Register Map
#define RCC_CR     		*((volatile unsigned long*)(RCC + RCR))
#define RCC_CFGR   		*((volatile unsigned long*)(RCC + RCFGR))
#define RCC_CIR   	    *((volatile unsigned long*)(RCC + RCIR))
#define RCC_APB2RSTR    *((volatile unsigned long*)(RCC + RAPB2RSTR))
#define RCC_APB1RSTR    *((volatile unsigned long*)(RCC + RAPB1RSTR))
#define RCC_AHBENR   	*((volatile unsigned long*)(RCC + RAHBENR))
#define RCC_APB2ENR   	*((volatile unsigned long*)(RCC + RAPB2ENR))
#define RCC_APB1ENR   	*((volatile unsigned long*)(RCC + RAPB1ENR))
#define RCC_BDCR   		*((volatile unsigned long*)(RCC + RBDCR))
#define RCC_CSR   		*((volatile unsigned long*)(RCC + RCSR))



#define EXTI_BASE     (0x40010400)

#define EIMR    0x00
#define EEMR    0x04
#define ERTSR   0x08
#define EFTSR   0x0C
#define ESWIER  0x10
#define EPR     0x14

#define EXTI_IMR       *((volatile unsigned long*)(EXTI_BASE + EIMR))
#define EXTI_EMR       *((volatile unsigned long*)(EXTI_BASE + EEMR))
#define EXTI_RTSR      *((volatile unsigned long*)(EXTI_BASE + ERTSR))
#define EXTI_FTSR      *((volatile unsigned long*)(EXTI_BASE + EFTSR))
#define EXTI_SWIER     *((volatile unsigned long*)(EXTI_BASE + ESWIER))
#define EXTI_PR        *((volatile unsigned long*)(EXTI_BASE + EPR))


#define AFIO_BASE    (0x40010000)

#define EVCR      0x00
#define MAPR      0x04
#define EXTICR1   0x08
#define EXTICR2   0x0C
#define EXTICR3   0x10
#define EXTICR4   0x14
#define MAPR2     0x18


#define AFIO_EVCR      *((volatile unsigned long*)(AFIO_BASE + EVCR))
#define AFIO_MAPR      *((volatile unsigned long*)(AFIO_BASE + MAPR))
#define AFIO_EXTICR1   *((volatile unsigned long*)(AFIO_BASE + EXTICR1))
#define AFIO_EXTICR2   *((volatile unsigned long*)(AFIO_BASE + EXTICR2))
#define AFIO_EXTICR3   *((volatile unsigned long*)(AFIO_BASE + EXTICR3))
#define AFIO_EXTICR4   *((volatile unsigned long*)(AFIO_BASE + EXTICR4))
#define AFIO_MAPR2     *((volatile unsigned long*)(AFIO_BASE + MAPR2))

// NVIC
#define NVIC_ISER0    *((volatile unsigned long*)(0xE000E100))
#define NVIC_ISER1    *((volatile unsigned long*)(0xE000E104))
#define NVIC_ISER2    *((volatile unsigned long*)(0xE000E108))
#define NVIC_ICER0    *((volatile unsigned long*)(0xE000E180))
#define NVIC_ICER1    *((volatile unsigned long*)(0xE000E184))
#define NVIC_ICER2    *((volatile unsigned long*)(0xE000E188))
#define NVIC_IPR0     *((volatile unsigned long*)(0xE000E400))
#define NVIC_IPR1     *((volatile unsigned long*)(0xE000E404))
#define NVIC_IPR2     *((volatile unsigned long*)(0xE000E408))
#define NVIC_IPR3     *((volatile unsigned long*)(0xE000E40C))
#define NVIC_IPR4     *((volatile unsigned long*)(0xE000E410))
#define NVIC_IPR5     *((volatile unsigned long*)(0xE000E414))
#define NVIC_IPR6     *((volatile unsigned long*)(0xE000E418))
#define NVIC_IPR7     *((volatile unsigned long*)(0xE000E41C))
#define NVIC_IPR8     *((volatile unsigned long*)(0xE000E420))
#define NVIC_IPR9     *((volatile unsigned long*)(0xE000E424))
#define NVIC_IPR10    *((volatile unsigned long*)(0xE000E428))
#define NVIC_IPR11    *((volatile unsigned long*)(0xE000E42C))
#define NVIC_IPR12    *((volatile unsigned long*)(0xE000E430))
#define NVIC_IPR13    *((volatile unsigned long*)(0xE000E434))
#define NVIC_IPR14    *((volatile unsigned long*)(0xE000E438))
#define NVIC_IPR15    *((volatile unsigned long*)(0xE000E43C))
#define NVIC_IPR16    *((volatile unsigned long*)(0xE000E440))
#define NVIC_IPR17    *((volatile unsigned long*)(0xE000E444))
#define NVIC_IPR18    *((volatile unsigned long*)(0xE000E448))
#define NVIC_IPR19    *((volatile unsigned long*)(0xE000E44C))
#define NVIC_IPR20    *((volatile unsigned long*)(0xE000E450))
#define NVIC_ICPR0	  *((volatile unsigned long*)(0xE000E280))
#define NVIC_ICPR1	  *((volatile unsigned long*)(0xE000E284))
#define NVIC_ISPR0	  *((volatile unsigned long*)(0xE000E200))
#define NVIC_ISRP1	  *((volatile unsigned long*)(0xE000E204))


#define ADC1_BASE  0x40012400
#define ADC2_BASE  0x40012800


#define ASR     0x00
#define ACR1     0x04
#define ACR2     0x08
#define ASMPR1   0x0C
#define ASMPR2   0x10
#define AJOFR1   0x14
#define AJOFR2   0x18
#define AJOFR3   0x1C
#define AJOFR4   0x20
#define AHTR     0x24
#define ALTR     0x28
#define ASQR1    0x2C
#define ASQR2    0x30
#define ASQR3    0x34
#define AJSQR    0x38
#define AJDR1    0x3C
#define AJDR2    0x40
#define AJDR3    0x44
#define AJDR4    0x48
#define ADR      0x4C

// ADC 1
#define ADC1_SR     	*((volatile unsigned long*)(ADC1_BASE + ASR))
#define ADC1_CR1    	*((volatile unsigned long*)(ADC1_BASE + ACR1))
#define ADC1_CR2    	*((volatile unsigned long*)(ADC1_BASE + ACR2))
#define ADC1_SMPR1  	*((volatile unsigned long*)(ADC1_BASE + ASMPR1))
#define ADC1_SMPR2  	*((volatile unsigned long*)(ADC1_BASE + ASMPR2))
#define ADC1_SMPR3  	*((volatile unsigned long*)(ADC1_BASE + ASMPR3))
#define ADC1_SMPR4  	*((volatile unsigned long*)(ADC1_BASE + ASMPR4))
#define ADC1_JOFR1  	*((volatile unsigned long*)(ADC1_BASE + AJOFR1))
#define ADC1_JOFR2  	*((volatile unsigned long*)(ADC1_BASE + AJOFR2))
#define ADC1_JOFR3  	*((volatile unsigned long*)(ADC1_BASE + AJOFR3))
#define ADC1_JOFR4  	*((volatile unsigned long*)(ADC1_BASE + AJOFR4))
#define ADC1_HTR	  	*((volatile unsigned long*)(ADC1_BASE + AHTR))
#define ADC1_LTR  		*((volatile unsigned long*)(ADC1_BASE + ALTR))
#define ADC1_SQR1	  	*((volatile unsigned long*)(ADC1_BASE + ASQR1))
#define ADC1_SQR2	  	*((volatile unsigned long*)(ADC1_BASE + ASQR2))
#define ADC1_SQR3	  	*((volatile unsigned long*)(ADC1_BASE + ASQR3))
#define ADC1_SQR4	  	*((volatile unsigned long*)(ADC1_BASE + ASQR4))
#define ADC1_JSQR	  	*((volatile unsigned long*)(ADC1_BASE + AJSQR))
#define ADC1_JDR1	  	*((volatile unsigned long*)(ADC1_BASE + AJDR1))
#define ADC1_JDR2	  	*((volatile unsigned long*)(ADC1_BASE + AJDR2))
#define ADC1_JDR3	  	*((volatile unsigned long*)(ADC1_BASE + AJDR3))
#define ADC1_JDR4	  	*((volatile unsigned long*)(ADC1_BASE + AJDR4))
#define ADC1_DR		  	*((volatile unsigned long*)(ADC1_BASE + ADR))



// ADC 1
#define ADC2_SR     	*((volatile unsigned long*)(ADC2_BASE + ASR))
#define ADC2_CR1    	*((volatile unsigned long*)(ADC2_BASE + ACR1))
#define ADC2_CR2    	*((volatile unsigned long*)(ADC2_BASE + ACR2))
#define ADC2_SMPR1  	*((volatile unsigned long*)(ADC2_BASE + ASMPR1))
#define ADC2_SMPR2  	*((volatile unsigned long*)(ADC2_BASE + ASMPR2))
#define ADC2_SMPR3  	*((volatile unsigned long*)(ADC2_BASE + ASMPR3))
#define ADC2_SMPR4  	*((volatile unsigned long*)(ADC2_BASE + ASMPR4))
#define ADC2_JOFR1  	*((volatile unsigned long*)(ADC2_BASE + AJOFR1))
#define ADC2_JOFR2  	*((volatile unsigned long*)(ADC2_BASE + AJOFR2))
#define ADC2_JOFR3  	*((volatile unsigned long*)(ADC2_BASE + AJOFR3))
#define ADC2_JOFR4  	*((volatile unsigned long*)(ADC2_BASE + AJOFR4))
#define ADC2_HTR	  	*((volatile unsigned long*)(ADC2_BASE + AHTR))
#define ADC2_LTR  		*((volatile unsigned long*)(ADC2_BASE + ALTR))
#define ADC2_SQR1	  	*((volatile unsigned long*)(ADC2_BASE + ASQR1))
#define ADC2_SQR2	  	*((volatile unsigned long*)(ADC2_BASE + ASQR2))
#define ADC2_SQR3	  	*((volatile unsigned long*)(ADC2_BASE + ASQR3))
#define ADC2_SQR4	  	*((volatile unsigned long*)(ADC2_BASE + ASQR4))
#define ADC2_JSQR	  	*((volatile unsigned long*)(ADC2_BASE + AJSQR))
#define ADC2_JDR1	  	*((volatile unsigned long*)(ADC2_BASE + AJDR1))
#define ADC2_JDR2	  	*((volatile unsigned long*)(ADC2_BASE + AJDR2))
#define ADC2_JDR3	  	*((volatile unsigned long*)(ADC2_BASE + AJDR3))
#define ADC2_JDR4	  	*((volatile unsigned long*)(ADC2_BASE + AJDR4))
#define ADC2_DR		  	*((volatile unsigned long*)(ADC2_BASE + ADR))

// Advanced Timers --> Timer 1
#define TIM1_BASE 0x40012C00

// General Purpose Timers
#define TIM2_BASE  0x40000000
#define TIM3_BASE  0x40000400
#define TIM4_BASE  0x40000800

#define TCR1   	 0x00
#define TCR2 	 0x04
#define TSMCR	 0x08
#define TDIER     0x0C
#define TSR       0x10
#define TEGR      0x14
#define TCCMR1    0x18
#define TCCMR2    0x1C
#define TCCER     0x20
#define TCNT      0x24
#define TPSC      0x28
#define TARR      0x2C
#define TCCR1     0x34
#define TCCR2     0x38
#define TCCR3     0x3C
#define TCCR4     0x40
#define TDMA      0x48
#define TDMAR     0x4C


#define TIM1_CR1        *((volatile unsigned long*)(TIM1_BASE + TCR1))
#define TIM2_CR1        *((volatile unsigned long*)(TIM2_BASE + TCR1))
#define TIM3_CR1        *((volatile unsigned long*)(TIM3_BASE + TCR1))
#define TIM4_CR1        *((volatile unsigned long*)(TIM4_BASE + TCR1))
#define TIM1_CR2        *((volatile unsigned long*)(TIM1_BASE + TCR2))
#define TIM2_CR2        *((volatile unsigned long*)(TIM2_BASE + TCR2))
#define TIM3_CR2        *((volatile unsigned long*)(TIM3_BASE + TCR2))
#define TIM4_CR2        *((volatile unsigned long*)(TIM4_BASE + TCR2))
#define TIM1_SMCR       *((volatile unsigned long*)(TIM1_BASE + TSMCR))
#define TIM2_SMCR       *((volatile unsigned long*)(TIM2_BASE + TSMCR))
#define TIM3_SMCR       *((volatile unsigned long*)(TIM3_BASE + TSMCR))
#define TIM4_SMCR       *((volatile unsigned long*)(TIM4_BASE + TSMCR))
#define TIM1_DIER       *((volatile unsigned long*)(TIM1_BASE + TDIER))
#define TIM2_DIER       *((volatile unsigned long*)(TIM2_BASE + TDIER))
#define TIM3_DIER       *((volatile unsigned long*)(TIM3_BASE + TDIER))
#define TIM4_DIER       *((volatile unsigned long*)(TIM4_BASE + TDIER))
#define TIM1_SR         *((volatile unsigned long*)(TIM1_BASE + TSR))
#define TIM2_SR         *((volatile unsigned long*)(TIM2_BASE + TSR))
#define TIM3_SR         *((volatile unsigned long*)(TIM3_BASE + TSR))
#define TIM4_SR         *((volatile unsigned long*)(TIM4_BASE + TSR))
#define TIM1_EGR        *((volatile unsigned long*)(TIM1_BASE + TEGR))
#define TIM2_EGR        *((volatile unsigned long*)(TIM2_BASE + TEGR))
#define TIM3_EGR        *((volatile unsigned long*)(TIM3_BASE + TEGR))
#define TIM4_EGR        *((volatile unsigned long*)(TIM4_BASE + TEGR))
#define TIM1_CCMR1      *((volatile unsigned long*)(TIM1_BASE + TCCMR1))
#define TIM2_CCMR1      *((volatile unsigned long*)(TIM2_BASE + TCCMR1))
#define TIM3_CCMR1      *((volatile unsigned long*)(TIM3_BASE + TCCMR1))
#define TIM4_CCMR1      *((volatile unsigned long*)(TIM4_BASE + TCCMR1))
#define TIM1_CCMR2      *((volatile unsigned long*)(TIM1_BASE + TCCMR2))
#define TIM2_CCMR2      *((volatile unsigned long*)(TIM2_BASE + TCCMR2))
#define TIM3_CCMR2      *((volatile unsigned long*)(TIM3_BASE + TCCMR2))
#define TIM4_CCMR2      *((volatile unsigned long*)(TIM4_BASE + TCCMR2))
#define TIM1_CCER       *((volatile unsigned long*)(TIM1_BASE + TCCER))
#define TIM2_CCER       *((volatile unsigned long*)(TIM2_BASE + TCCER))
#define TIM3_CCER       *((volatile unsigned long*)(TIM3_BASE + TCCER))
#define TIM4_CCER       *((volatile unsigned long*)(TIM4_BASE + TCCER))
#define TIM1_CNT        *((volatile unsigned long*)(TIM1_BASE + TCNT))
#define TIM2_CNT        *((volatile unsigned long*)(TIM2_BASE + TCNT))
#define TIM3_CNT        *((volatile unsigned long*)(TIM3_BASE + TCNT))
#define TIM4_CNT        *((volatile unsigned long*)(TIM4_BASE + TCNT))
#define TIM1_PSC        *((volatile unsigned long*)(TIM1_BASE + TPSC))
#define TIM2_PSC        *((volatile unsigned long*)(TIM2_BASE + TPSC))
#define TIM3_PSC        *((volatile unsigned long*)(TIM3_BASE + TPSC))
#define TIM4_PSC        *((volatile unsigned long*)(TIM4_BASE + TPSC))
#define TIM1_ARR        *((volatile unsigned long*)(TIM1_BASE + TARR))
#define TIM2_ARR        *((volatile unsigned long*)(TIM2_BASE + TARR))
#define TIM3_ARR        *((volatile unsigned long*)(TIM3_BASE + TARR))
#define TIM4_ARR        *((volatile unsigned long*)(TIM4_BASE + TARR))
#define TIM1_CCR1       *((volatile unsigned long*)(TIM1_BASE + TCCR1))
#define TIM2_CCR1       *((volatile unsigned long*)(TIM2_BASE + TCCR1))
#define TIM3_CCR1       *((volatile unsigned long*)(TIM3_BASE + TCCR1))
#define TIM4_CCR1       *((volatile unsigned long*)(TIM4_BASE + TCCR1))
#define TIM1_CCR2       *((volatile unsigned long*)(TIM1_BASE + TCCR2))
#define TIM2_CCR2       *((volatile unsigned long*)(TIM2_BASE + TCCR2))
#define TIM3_CCR2       *((volatile unsigned long*)(TIM3_BASE + TCCR2))
#define TIM4_CCR2       *((volatile unsigned long*)(TIM4_BASE + TCCR2))
#define TIM1_CCR3       *((volatile unsigned long*)(TIM1_BASE + TCCR3))
#define TIM2_CCR3       *((volatile unsigned long*)(TIM2_BASE + TCCR3))
#define TIM3_CCR3       *((volatile unsigned long*)(TIM3_BASE + TCCR3))
#define TIM4_CCR3       *((volatile unsigned long*)(TIM4_BASE + TCCR3))
#define TIM1_CCR4       *((volatile unsigned long*)(TIM1_BASE + TCCR4))
#define TIM2_CCR4       *((volatile unsigned long*)(TIM2_BASE + TCCR4))
#define TIM3_CCR4       *((volatile unsigned long*)(TIM3_BASE + TCCR4))
#define TIM4_CCR4       *((volatile unsigned long*)(TIM4_BASE + TCCR4))
#define TIM1_DMA        *((volatile unsigned long*)(TIM1_BASE + TDMA))
#define TIM2_DMA        *((volatile unsigned long*)(TIM2_BASE + TDMA))
#define TIM3_DMA        *((volatile unsigned long*)(TIM3_BASE + TDMA))
#define TIM4_DMA        *((volatile unsigned long*)(TIM4_BASE + TDMA))
#define TIM1_DMAR       *((volatile unsigned long*)(TIM1_BASE + TDMAR))
#define TIM2_DMAR       *((volatile unsigned long*)(TIM2_BASE + TDMAR))
#define TIM3_DMAR       *((volatile unsigned long*)(TIM3_BASE + TDMAR))
#define TIM4_DMAR       *((volatile unsigned long*)(TIM4_BASE + TDMAR))



#define UART1_BASE  0x40013800
#define UART2_BASE  0x40004400
#define UART3_BASE  0x40004800


#define UART_SR 	0x00
#define UART_DR     0x04
#define UART_BRR    0x08
#define UART_CR1    0x0C
#define UART_CR2    0x10
#define UART_CR3    0x14
#define UART_GTPR   0x18


#define UART1_SR     *((volatile unsigned long*)(UART1_BASE + UART_SR))
#define UART1_DR     *((volatile unsigned long*)(UART1_BASE + UART_DR))
#define UART1_BRR    *((volatile unsigned long*)(UART1_BASE + UART_BRR))
#define UART1_CR1    *((volatile unsigned long*)(UART1_BASE + UART_CR1))
#define UART1_CR2    *((volatile unsigned long*)(UART1_BASE + UART_CR2))
#define UART1_CR3    *((volatile unsigned long*)(UART1_BASE + UART_CR3))
#define UART1_GTPR   *((volatile unsigned long*)(UART1_BASE + UART_GTPR))


#define UART2_SR     *((volatile unsigned long*)(UART2_BASE + UART_SR))
#define UART2_DR     *((volatile unsigned long*)(UART2_BASE + UART_DR))
#define UART2_BRR    *((volatile unsigned long*)(UART2_BASE + UART_BRR))
#define UART2_CR1    *((volatile unsigned long*)(UART2_BASE + UART_CR1))
#define UART2_CR2    *((volatile unsigned long*)(UART2_BASE + UART_CR2))
#define UART2_CR3    *((volatile unsigned long*)(UART2_BASE + UART_CR3))
#define UART2_GTPR   *((volatile unsigned long*)(UART2_BASE + UART_GTPR))


#define UART3_SR     *((volatile unsigned long*)(UART3_BASE + UART_SR))
#define UART3_DR     *((volatile unsigned long*)(UART3_BASE + UART_DR))
#define UART3_BRR    *((volatile unsigned long*)(UART3_BASE + UART_BRR))
#define UART3_CR1    *((volatile unsigned long*)(UART3_BASE + UART_CR1))
#define UART3_CR2    *((volatile unsigned long*)(UART3_BASE + UART_CR2))
#define UART3_CR3    *((volatile unsigned long*)(UART3_BASE + UART_CR3))
#define UART3_GTPR   *((volatile unsigned long*)(UART3_BASE + UART_GTPR))



// DMA Registers (DMA1)
#define DMA1_BASE  	0x40020000
// DMA Offsets (DMA1)
#define DMA_ISR 	0x000
#define DMA_IFCR    0x004
#define DMA_CCR1    0x008
#define DMA_CNDTR1  0x00C
#define DMA_CPAR1   0x010
#define DMA_CMAR1   0x014
#define DMA_CCR2    0x018
#define DMA_CNDTR2  0x01C
#define DMA_CPAR2   0x020
#define DMA_CMAR2   0x024
#define DMA_CCR3    0x028
#define DMA_CNDTR3  0x02C
#define DMA_CPAR3   0x030
#define DMA_CMAR3   0x034
#define DMA_CCR4    0x038
#define DMA_CNDTR4  0x03C
#define DMA_CPAR4   0x040
#define DMA_CMAR4   0x044
#define DMA_CCR5    0x048
#define DMA_CNDTR5  0x04C
#define DMA_CPAR5   0x050
#define DMA_CMAR5   0x054
#define DMA_CCR6    0x058
#define DMA_CNDTR6  0x05C
#define DMA_CPAR6   0x060
#define DMA_CMAR6   0x064
#define DMA_CCR7    0x068
#define DMA_CNDTR7  0x06C
#define DMA_CPAR7   0x070
#define DMA_CMAR7   0x074


#define DMA1_IFCR	*((volatile unsigned long*)(DMA1_BASE + DMA_IFCR))

#define DMA1_CCR1    *((volatile unsigned long*)(DMA1_BASE + DMA_CCR1))
#define DMA1_CNDTR1  *((volatile unsigned long*)(DMA1_BASE + DMA_CNDTR1))
#define DMA1_CPAR1   *((volatile unsigned long*)(DMA1_BASE + DMA_CPAR1))
#define DMA1_CMAR1   *((volatile unsigned long*)(DMA1_BASE + DMA_CMAR1))


#define DMA1_CCR2    *((volatile unsigned long*)(DMA1_BASE + DMA_CCR2))
#define DMA1_CNDTR2  *((volatile unsigned long*)(DMA1_BASE + DMA_CNDTR2))
#define DMA1_CPAR2   *((volatile unsigned long*)(DMA1_BASE + DMA_CPAR2))
#define DMA1_CMAR2   *((volatile unsigned long*)(DMA1_BASE + DMA_CMAR2))


#define DMA1_CCR3    *((volatile unsigned long*)(DMA1_BASE + DMA_CCR3))
#define DMA1_CNDTR3  *((volatile unsigned long*)(DMA1_BASE + DMA_CNDTR3))
#define DMA1_CPAR3   *((volatile unsigned long*)(DMA1_BASE + DMA_CPAR3))
#define DMA1_CMAR3   *((volatile unsigned long*)(DMA1_BASE + DMA_CMAR3))

#define DMA1_CCR4    *((volatile unsigned long*)(DMA1_BASE + DMA_CCR4))
#define DMA1_CNDTR4  *((volatile unsigned long*)(DMA1_BASE + DMA_CNDTR4))
#define DMA1_CPAR4   *((volatile unsigned long*)(DMA1_BASE + DMA_CPAR4))
#define DMA1_CMAR4   *((volatile unsigned long*)(DMA1_BASE + DMA_CMAR4))

#define DMA1_CCR5    *((volatile unsigned long*)(DMA1_BASE + DMA_CCR5))
#define DMA1_CNDTR5  *((volatile unsigned long*)(DMA1_BASE + DMA_CNDTR5))
#define DMA1_CPAR5   *((volatile unsigned long*)(DMA1_BASE + DMA_CPAR5))
#define DMA1_CMAR5   *((volatile unsigned long*)(DMA1_BASE + DMA_CMAR5))

#define DMA1_CCR6    *((volatile unsigned long*)(DMA1_BASE + DMA_CCR6))
#define DMA1_CNDTR6  *((volatile unsigned long*)(DMA1_BASE + DMA_CNDTR6))
#define DMA1_CPAR6   *((volatile unsigned long*)(DMA1_BASE + DMA_CPAR6))
#define DMA1_CMAR6   *((volatile unsigned long*)(DMA1_BASE + DMA_CMAR6))

#define DMA1_CCR7    *((volatile unsigned long*)(DMA1_BASE + DMA_CCR7))
#define DMA1_CNDTR7  *((volatile unsigned long*)(DMA1_BASE + DMA_CNDTR7))
#define DMA1_CPAR7   *((volatile unsigned long*)(DMA1_BASE + DMA_CPAR7))
#define DMA1_CMAR7   *((volatile unsigned long*)(DMA1_BASE + DMA_CMAR7))



#define I2C1_BASE  0x40005400
#define I2C2_BASE  0x40005800

#define I2C_CR1    0x00
#define I2C_CR2    0x04
#define I2C_OAR1   0x08
#define I2C_OAR2   0x0C
#define I2C_DR     0x10
#define I2C_SR1    0x14
#define I2C_SR2    0x18
#define I2C_CCR    0x1C
#define I2C_TRISE  0x20


#define I2C1_CR1	*((volatile unsigned long*)(I2C1_BASE + I2C_CR1))
#define I2C1_CR2	*((volatile unsigned long*)(I2C1_BASE + I2C_CR2))
#define I2C1_OAR1	*((volatile unsigned long*)(I2C1_BASE + I2C_OAR1))
#define I2C1_OAR2	*((volatile unsigned long*)(I2C1_BASE + I2C_OAR2))
#define I2C1_DR 	*((volatile unsigned long*)(I2C1_BASE + I2C_DR))
#define I2C1_SR1	*((volatile unsigned long*)(I2C1_BASE + I2C_SR1))
#define I2C1_SR2	*((volatile unsigned long*)(I2C1_BASE + I2C_SR2))
#define I2C1_CCR	*((volatile unsigned long*)(I2C1_BASE + I2C_CCR))
#define I2C1_TRISE	*((volatile unsigned long*)(I2C1_BASE + I2C_TRISE))

#define I2C2_CR1	*((volatile unsigned long*)(I2C2_BASE + I2C_CR1))
#define I2C2_CR2	*((volatile unsigned long*)(I2C2_BASE + I2C_CR2))
#define I2C2_OAR1	*((volatile unsigned long*)(I2C2_BASE + I2C_OAR1))
#define I2C2_OAR2	*((volatile unsigned long*)(I2C2_BASE + I2C_OAR2))
#define I2C2_DR 	*((volatile unsigned long*)(I2C2_BASE + I2C_DR))
#define I2C2_SR1	*((volatile unsigned long*)(I2C2_BASE + I2C_SR1))
#define I2C2_SR2	*((volatile unsigned long*)(I2C2_BASE + I2C_SR2))
#define I2C2_CCR	*((volatile unsigned long*)(I2C2_BASE + I2C_CCR))
#define I2C2_TRISE	*((volatile unsigned long*)(I2C2_BASE + I2C_TRISE))


#endif /* REGMAP_ */
