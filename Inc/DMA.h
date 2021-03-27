/*
 * DMA.h
 *
 *  Created on: Jan 26, 2021
 *      Author: Karim Hussein
 */

#ifndef DMA_H_
#define DMA_H_

typedef enum {DMA_CH1,DMA_CH2,DMA_CH3,DMA_CH4,DMA_CH5,DMA_CH6,DMA_CH7}DMA_CHANNEL;
typedef enum {Very_High,High,Medium,Low}DMA_CHANNEL_PRIORITY;
typedef enum {Peripheral,Memory}DMA_SOURCE;
typedef enum {Byte,Word,Dword}DATA_SIZE;

typedef struct{
	DMA_CHANNEL dma_channel;
	DMA_CHANNEL_PRIORITY dma_channel_priority;
	DMA_SOURCE dma_source;
	DATA_SIZE data_size;
	unsigned short No_Of_Transcations;
	unsigned long src;
	unsigned long dst;
}DMA_CONFIG;


void DMA_Init(void);
void DMA_Configuration(DMA_CONFIG dma_config);
void DMA_Enable(DMA_CHANNEL dma_channel);
void DMA_Disable(DMA_CHANNEL dma_channel);
void DMA_SetISR(DMA_CHANNEL dma_channel,void (*ptr)(void));
void DMA_EnableInterrupt(DMA_CHANNEL dma_channel);
void DMA_DisableInterrupt(DMA_CHANNEL dma_channel);

#endif /* DMA_H_ */
