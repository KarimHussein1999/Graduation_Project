/*
 * DMA.c
 *
 *  Created on: Jan 26, 2021
 *      Author: Karim Hussein
 */


#include "Regmap.h"
#include "util.h"
#include "DMA.h"


void DMA_No_Of_Transactions(DMA_CHANNEL dma_channel,unsigned short No_Of_Transactions);
void DMA_Channel_Priority(DMA_CHANNEL dma_channel,DMA_CHANNEL_PRIORITY dma_channel_priority);
void DMA_Source_Address(DMA_CHANNEL dma_channel ,DMA_SOURCE dma_source, unsigned long src);
void DMA_Destination_Address(DMA_CHANNEL dma_channel ,DMA_SOURCE dma_source,unsigned long dst);
void DMA_Destination_Size(DMA_CHANNEL dma_channel,DMA_SOURCE dma_source,DATA_SIZE data_size);
void DMA_Source_Size(DMA_CHANNEL dma_channel,DMA_SOURCE dma_source,DATA_SIZE data_size);
void DMA_Direction(DMA_CHANNEL dma_channel,DMA_SOURCE dma_source);
void DMA_Mode(DMA_CHANNEL dma_channel);

void DMA_Init(void)
{
	SetBit(RCC_AHBENR,0);
}

void DMA_Configuration(DMA_CONFIG dma_config)
{
	DMA_Source_Address(dma_config.dma_channel ,dma_config.dma_source, dma_config.src);
	DMA_Destination_Address(dma_config.dma_channel ,dma_config.dma_source,dma_config.dst);
	DMA_No_Of_Transactions(dma_config.dma_channel,dma_config.No_Of_Transcations);
	DMA_Channel_Priority(dma_config.dma_channel,dma_config.dma_channel_priority);
	DMA_Destination_Size(dma_config.dma_channel,dma_config.dma_source,dma_config.data_size);
	DMA_Source_Size(dma_config.dma_channel,dma_config.dma_source,dma_config.data_size);
	DMA_Direction(dma_config.dma_channel,dma_config.dma_source);
	DMA_Mode(dma_config.dma_channel);
}
void DMA_Enable(DMA_CHANNEL dma_channel)
{
	switch(dma_channel)
	{
		case DMA_CH1:
			SetBit(DMA1_CCR1,0);
			break;
		case DMA_CH2:
			SetBit(DMA1_CCR2,0);
			break;
		case DMA_CH3:
			SetBit(DMA1_CCR3,0);
			break;
		case DMA_CH4:
			SetBit(DMA1_CCR4,0);
			break;
		case DMA_CH5:
			SetBit(DMA1_CCR5,0);
			break;
		case DMA_CH6:
			SetBit(DMA1_CCR6,0);
			break;
		case DMA_CH7:
			SetBit(DMA1_CCR7,0);
			break;
		default:break;
	}
}
void DMA_Disable(DMA_CHANNEL dma_channel)
{
	switch(dma_channel)
	{
		case DMA_CH1:
			ClrBit(DMA1_CCR1,0);
			break;
		case DMA_CH2:
			ClrBit(DMA1_CCR2,0);
			break;
		case DMA_CH3:
			ClrBit(DMA1_CCR3,0);
			break;
		case DMA_CH4:
			ClrBit(DMA1_CCR4,0);
			break;
		case DMA_CH5:
			ClrBit(DMA1_CCR5,0);
			break;
		case DMA_CH6:
			ClrBit(DMA1_CCR6,0);
			break;
		case DMA_CH7:
			ClrBit(DMA1_CCR7,0);
			break;
		default:break;
	}
}

void (*DMA_CH1_ISR)(void) = 0;
void (*DMA_CH2_ISR)(void) = 0;
void (*DMA_CH3_ISR)(void) = 0;
void (*DMA_CH4_ISR)(void) = 0;
void (*DMA_CH5_ISR)(void) = 0;
void (*DMA_CH6_ISR)(void) = 0;
void (*DMA_CH7_ISR)(void) = 0;

void DMA_SetISR(DMA_CHANNEL dma_channel,void (*ptr)(void))
{
	switch(dma_channel)
	{
		case DMA_CH1:
			SetBit(NVIC_ISER0,11);
			DMA_CH1_ISR = ptr;
			break;
		case DMA_CH2:
			SetBit(NVIC_ISER0,12);
			DMA_CH2_ISR = ptr;
			break;
		case DMA_CH3:
			SetBit(NVIC_ISER0,13);
			DMA_CH3_ISR = ptr;
			break;
		case DMA_CH4:
			SetBit(NVIC_ISER0,14);
			DMA_CH4_ISR = ptr;
			break;
		case DMA_CH5:
			SetBit(NVIC_ISER0,15);
			DMA_CH5_ISR = ptr;
			break;
		case DMA_CH6:
			SetBit(NVIC_ISER0,16);
			DMA_CH6_ISR = ptr;
			break;
		case DMA_CH7:
			SetBit(NVIC_ISER0,17);
			DMA_CH7_ISR = ptr;
			break;
		default:break;
	}
}

void DMA_EnableInterrupt(DMA_CHANNEL dma_channel)
{
	// Transfer Complete Interrupt
	switch(dma_channel)
	{
		case DMA_CH1:
			SetBit(DMA1_CCR1,1);
			break;
		case DMA_CH2:
			SetBit(DMA1_CCR2,1);
			break;
		case DMA_CH3:
			SetBit(DMA1_CCR3,1);
			break;
		case DMA_CH4:
			SetBit(DMA1_CCR4,1);
			break;
		case DMA_CH5:
			SetBit(DMA1_CCR5,1);
			break;
		case DMA_CH6:
			SetBit(DMA1_CCR6,1);
			break;
		case DMA_CH7:
			SetBit(DMA1_CCR7,1);
			break;
	}
}
void DMA_DisableInterrupt(DMA_CHANNEL dma_channel)
{
	// Transfer Complete Interrupt
	switch(dma_channel)
	{
		case DMA_CH1:
			ClrBit(DMA1_CCR1,1);
			break;
		case DMA_CH2:
			ClrBit(DMA1_CCR2,1);
			break;
		case DMA_CH3:
			ClrBit(DMA1_CCR3,1);
			break;
		case DMA_CH4:
			ClrBit(DMA1_CCR4,1);
			break;
		case DMA_CH5:
			ClrBit(DMA1_CCR5,1);
			break;
		case DMA_CH6:
			ClrBit(DMA1_CCR6,1);
			break;
		case DMA_CH7:
			ClrBit(DMA1_CCR7,1);
			break;
	}
}


void DMA_No_Of_Transactions(DMA_CHANNEL dma_channel,unsigned short No_Of_Transactions)
{
	switch(dma_channel)
	{
		case DMA_CH1:
			DMA1_CNDTR1 = No_Of_Transactions;
			break;
		case DMA_CH2:
			DMA1_CNDTR2 = No_Of_Transactions;
			break;
		case DMA_CH3:
			DMA1_CNDTR3 = No_Of_Transactions;
			break;
		case DMA_CH4:
			DMA1_CNDTR4 = No_Of_Transactions;
			break;
		case DMA_CH5:
			DMA1_CNDTR5 = No_Of_Transactions;
			break;
		case DMA_CH6:
			DMA1_CNDTR6 = No_Of_Transactions;
			break;
		case DMA_CH7:
			DMA1_CNDTR7 = No_Of_Transactions;
			break;
		default:break;
	}
}

void DMA_Channel_Priority(DMA_CHANNEL dma_channel,DMA_CHANNEL_PRIORITY dma_channel_priority)
{
	switch(dma_channel)
	{
		case DMA_CH1:
			switch(dma_channel_priority)
			{
				case Very_High:
					SetBit(DMA1_CCR1,12);
					SetBit(DMA1_CCR1,13);
					break;
				case High:
					ClrBit(DMA1_CCR1,12);
					SetBit(DMA1_CCR1,13);
					break;
				case Medium:
					SetBit(DMA1_CCR1,12);
					ClrBit(DMA1_CCR1,13);
					break;
				case Low:
					ClrBit(DMA1_CCR1,12);
					ClrBit(DMA1_CCR1,13);
					break;
				default:break;
			}
			break;
		case DMA_CH2:
			switch(dma_channel_priority)
			{
				case Very_High:
					SetBit(DMA1_CCR2,12);
					SetBit(DMA1_CCR2,13);
					break;
				case High:
					ClrBit(DMA1_CCR2,12);
					SetBit(DMA1_CCR2,13);
					break;
				case Medium:
					SetBit(DMA1_CCR2,12);
					ClrBit(DMA1_CCR2,13);
					break;
				case Low:
					ClrBit(DMA1_CCR2,12);
					ClrBit(DMA1_CCR2,13);
					break;
				default:break;
			}
			break;
		case DMA_CH3:
			switch(dma_channel_priority)
			{
				case Very_High:
					SetBit(DMA1_CCR3,12);
					SetBit(DMA1_CCR3,13);
					break;
				case High:
					ClrBit(DMA1_CCR3,12);
					SetBit(DMA1_CCR3,13);
					break;
				case Medium:
					SetBit(DMA1_CCR3,12);
					ClrBit(DMA1_CCR3,13);
					break;
				case Low:
					ClrBit(DMA1_CCR3,12);
					ClrBit(DMA1_CCR3,13);
					break;
				default:break;
			}
			break;
		case DMA_CH4:
			switch(dma_channel_priority)
			{
				case Very_High:
					SetBit(DMA1_CCR4,12);
					SetBit(DMA1_CCR4,13);
					break;
				case High:
					ClrBit(DMA1_CCR4,12);
					SetBit(DMA1_CCR4,13);
					break;
				case Medium:
					SetBit(DMA1_CCR4,12);
					ClrBit(DMA1_CCR4,13);
					break;
				case Low:
					ClrBit(DMA1_CCR4,12);
					ClrBit(DMA1_CCR4,13);
					break;
				default:break;
			}
			break;
		case DMA_CH5:
			switch(dma_channel_priority)
			{
				case Very_High:
					SetBit(DMA1_CCR5,12);
					SetBit(DMA1_CCR5,13);
					break;
				case High:
					ClrBit(DMA1_CCR5,12);
					SetBit(DMA1_CCR5,13);
					break;
				case Medium:
					SetBit(DMA1_CCR5,12);
					ClrBit(DMA1_CCR5,13);
					break;
				case Low:
					ClrBit(DMA1_CCR5,12);
					ClrBit(DMA1_CCR5,13);
					break;
				default:break;
			}
			break;
		case DMA_CH6:
			switch(dma_channel_priority)
			{
				case Very_High:
					SetBit(DMA1_CCR6,12);
					SetBit(DMA1_CCR6,13);
					break;
				case High:
					ClrBit(DMA1_CCR6,12);
					SetBit(DMA1_CCR6,13);
					break;
				case Medium:
					SetBit(DMA1_CCR6,12);
					ClrBit(DMA1_CCR6,13);
					break;
				case Low:
					ClrBit(DMA1_CCR6,12);
					ClrBit(DMA1_CCR6,13);
					break;
				default:break;
			}
			break;
		case DMA_CH7:
			switch(dma_channel_priority)
			{
				case Very_High:
					SetBit(DMA1_CCR7,12);
					SetBit(DMA1_CCR7,13);
					break;
				case High:
					ClrBit(DMA1_CCR7,12);
					SetBit(DMA1_CCR7,13);
					break;
				case Medium:
					SetBit(DMA1_CCR7,12);
					ClrBit(DMA1_CCR7,13);
					break;
				case Low:
					ClrBit(DMA1_CCR7,12);
					ClrBit(DMA1_CCR7,13);
					break;
				default:break;
			}
			break;
		default:break;
	}
}

void DMA_Source_Address(DMA_CHANNEL dma_channel ,DMA_SOURCE dma_source, unsigned long src)
{
	switch(dma_source)
	{
		case Peripheral:
			switch(dma_channel)
			{
				case DMA_CH1:
					DMA1_CPAR1 = src;
					break;
				case DMA_CH2:
					DMA1_CPAR2 = src;
					break;
				case DMA_CH3:
					DMA1_CPAR3 = src;
					break;
				case DMA_CH4:
					DMA1_CPAR4 = src;
					break;
				case DMA_CH5:
					DMA1_CPAR5 = src;
					break;
				case DMA_CH6:
					DMA1_CPAR6 = src;
					break;
				case DMA_CH7:
					DMA1_CPAR7 = src;
					break;
				default:break;
			}
			break;
		case Memory:
			switch(dma_channel)
			{
				case DMA_CH1:
					DMA1_CMAR1 = src;
					break;
				case DMA_CH2:
					DMA1_CMAR2 = src;
					break;
				case DMA_CH3:
					DMA1_CMAR3 = src;
					break;
				case DMA_CH4:
					DMA1_CMAR4 = src;
					break;
				case DMA_CH5:
					DMA1_CMAR5 = src;
					break;
				case DMA_CH6:
					DMA1_CMAR6 = src;
					break;
				case DMA_CH7:
					DMA1_CMAR7 = src;
					break;
				default:break;
			}
			break;
		default:break;
	}
}
void DMA_Destination_Address(DMA_CHANNEL dma_channel ,DMA_SOURCE dma_source,unsigned long dst)
{
	switch(dma_source)
	{
		case Peripheral:
			switch(dma_channel)
			{
				case DMA_CH1:
					DMA1_CMAR1 = dst;
					break;
				case DMA_CH2:
					DMA1_CMAR2 = dst;
					break;
				case DMA_CH3:
					DMA1_CMAR3 = dst;
					break;
				case DMA_CH4:
					DMA1_CMAR4 = dst;
					break;
				case DMA_CH5:
					DMA1_CMAR5 = dst;
					break;
				case DMA_CH6:
					DMA1_CMAR6 = dst;
					break;
				case DMA_CH7:
					DMA1_CMAR7 = dst;
					break;
				default:break;
			}
			break;
		case Memory:
			switch(dma_channel)
			{
				case DMA_CH1:
					DMA1_CPAR1 = dst;
					break;
				case DMA_CH2:
					DMA1_CPAR2 = dst;
					break;
				case DMA_CH3:
					DMA1_CPAR3 = dst;
					break;
				case DMA_CH4:
					DMA1_CPAR4 = dst;
					break;
				case DMA_CH5:
					DMA1_CPAR5 = dst;
					break;
				case DMA_CH6:
					DMA1_CPAR6 = dst;
					break;
				case DMA_CH7:
					DMA1_CPAR7 = dst;
					break;
				default:break;
			}
			break;
		default:break;
	}
}

void DMA_Destination_Size(DMA_CHANNEL dma_channel,DMA_SOURCE dma_source,DATA_SIZE data_size)
{
	switch(dma_channel)
	{
		case DMA_CH1:
			switch(data_size)
			{
				case Byte:
					switch(dma_source)
					{
						case Peripheral:
							// Memory
							ClrBit(DMA1_CCR1,10);
							ClrBit(DMA1_CCR1,11);
							break;
						case Memory:
							// Peripheral
							ClrBit(DMA1_CCR1,8);
							ClrBit(DMA1_CCR1,9);
							break;
						default:break;
					}
					break;
				case Word:
					switch(dma_source)
					{
						case Peripheral:
							// Memory
							SetBit(DMA1_CCR1,10);
							ClrBit(DMA1_CCR1,11);
							break;
						case Memory:
							// Peripheral
							SetBit(DMA1_CCR1,8);
							ClrBit(DMA1_CCR1,9);
							break;
						default:break;
					}
					break;
				case Dword:
					switch(dma_source)
					{
						case Peripheral:
							// Memory
							ClrBit(DMA1_CCR1,10);
							SetBit(DMA1_CCR1,11);
							break;
						case Memory:
							// Peripheral
							ClrBit(DMA1_CCR1,8);
							SetBit(DMA1_CCR1,9);
							break;
						default:break;
					}
					break;
				default:break;
			}
			break;
		case DMA_CH2:
			switch(data_size)
			{
				case Byte:
					switch(dma_source)
					{
						case Peripheral:
							// Memory
							ClrBit(DMA1_CCR2,10);
							ClrBit(DMA1_CCR2,11);
							break;
						case Memory:
							// Peripheral
							ClrBit(DMA1_CCR2,8);
							ClrBit(DMA1_CCR2,9);
							break;
						default:break;
					}
					break;
				case Word:
					switch(dma_source)
					{
						case Peripheral:
							// Memory
							SetBit(DMA1_CCR2,10);
							ClrBit(DMA1_CCR2,11);
							break;
						case Memory:
							// Peripheral
							SetBit(DMA1_CCR2,8);
							ClrBit(DMA1_CCR2,9);
							break;
						default:break;
					}
					break;
				case Dword:
					switch(dma_source)
					{
						case Peripheral:
							// Memory
							ClrBit(DMA1_CCR2,10);
							SetBit(DMA1_CCR2,11);
							break;
						case Memory:
							// Peripheral
							ClrBit(DMA1_CCR2,8);
							SetBit(DMA1_CCR2,9);
							break;
						default:break;
					}
					break;
				default:break;
			}
			break;
		case DMA_CH3:
			switch(data_size)
			{
				case Byte:
					switch(dma_source)
					{
						case Peripheral:
							// Memory
							ClrBit(DMA1_CCR3,10);
							ClrBit(DMA1_CCR3,11);
							break;
						case Memory:
							// Peripheral
							ClrBit(DMA1_CCR3,8);
							ClrBit(DMA1_CCR3,9);
							break;
						default:break;
					}
					break;
				case Word:
					switch(dma_source)
					{
						case Peripheral:
							// Memory
							SetBit(DMA1_CCR3,10);
							ClrBit(DMA1_CCR3,11);
							break;
						case Memory:
							// Peripheral
							SetBit(DMA1_CCR3,8);
							ClrBit(DMA1_CCR3,9);
							break;
						default:break;
					}
					break;
				case Dword:
					switch(dma_source)
					{
						case Peripheral:
							// Memory
							ClrBit(DMA1_CCR3,10);
							SetBit(DMA1_CCR3,11);
							break;
						case Memory:
							// Peripheral
							ClrBit(DMA1_CCR3,8);
							SetBit(DMA1_CCR3,9);
							break;
						default:break;
					}
					break;
				default:break;
			}
			break;
		case DMA_CH4:
			switch(data_size)
			{
				case Byte:
					switch(dma_source)
					{
						case Peripheral:
							// Memory
							ClrBit(DMA1_CCR4,10);
							ClrBit(DMA1_CCR4,11);
							break;
						case Memory:
							// Peripheral
							ClrBit(DMA1_CCR4,8);
							ClrBit(DMA1_CCR4,9);
							break;
						default:break;
					}
					break;
				case Word:
					switch(dma_source)
					{
						case Peripheral:
							// Memory
							SetBit(DMA1_CCR4,10);
							ClrBit(DMA1_CCR4,11);
							break;
						case Memory:
							// Peripheral
							SetBit(DMA1_CCR4,8);
							ClrBit(DMA1_CCR4,9);
							break;
						default:break;
					}
					break;
				case Dword:
					switch(dma_source)
					{
						case Peripheral:
							// Memory
							ClrBit(DMA1_CCR4,10);
							SetBit(DMA1_CCR4,11);
							break;
						case Memory:
							// Peripheral
							ClrBit(DMA1_CCR4,8);
							SetBit(DMA1_CCR4,9);
							break;
						default:break;
					}
					break;
				default:break;
			}
			break;
		case DMA_CH5:
			switch(data_size)
			{
				case Byte:
					switch(dma_source)
					{
						case Peripheral:
							// Memory
							ClrBit(DMA1_CCR5,10);
							ClrBit(DMA1_CCR5,11);
							break;
						case Memory:
							// Peripheral
							ClrBit(DMA1_CCR5,8);
							ClrBit(DMA1_CCR5,9);
							break;
						default:break;
					}
					break;
				case Word:
					switch(dma_source)
					{
						case Peripheral:
							// Memory
							SetBit(DMA1_CCR5,10);
							ClrBit(DMA1_CCR5,11);
							break;
						case Memory:
							// Peripheral
							SetBit(DMA1_CCR5,8);
							ClrBit(DMA1_CCR5,9);
							break;
						default:break;
					}
					break;
				case Dword:
					switch(dma_source)
					{
						case Peripheral:
							// Memory
							ClrBit(DMA1_CCR5,10);
							SetBit(DMA1_CCR5,11);
							break;
						case Memory:
							// Peripheral
							ClrBit(DMA1_CCR5,8);
							SetBit(DMA1_CCR5,9);
							break;
						default:break;
					}
					break;
				default:break;
			}
			break;
		case DMA_CH6:
			switch(data_size)
			{
				case Byte:
					switch(dma_source)
					{
						case Peripheral:
							// Memory
							ClrBit(DMA1_CCR6,10);
							ClrBit(DMA1_CCR6,11);
							break;
						case Memory:
							// Peripheral
							ClrBit(DMA1_CCR6,8);
							ClrBit(DMA1_CCR6,9);
							break;
						default:break;
					}
					break;
				case Word:
					switch(dma_source)
					{
						case Peripheral:
							// Memory
							SetBit(DMA1_CCR6,10);
							ClrBit(DMA1_CCR6,11);
							break;
						case Memory:
							// Peripheral
							SetBit(DMA1_CCR6,8);
							ClrBit(DMA1_CCR6,9);
							break;
						default:break;
					}
					break;
				case Dword:
					switch(dma_source)
					{
						case Peripheral:
							// Memory
							ClrBit(DMA1_CCR6,10);
							SetBit(DMA1_CCR6,11);
							break;
						case Memory:
							// Peripheral
							ClrBit(DMA1_CCR6,8);
							SetBit(DMA1_CCR6,9);
							break;
						default:break;
					}
					break;
				default:break;
			}
			break;
		case DMA_CH7:
			switch(data_size)
			{
				case Byte:
					switch(dma_source)
					{
						case Peripheral:
							// Memory
							ClrBit(DMA1_CCR7,10);
							ClrBit(DMA1_CCR7,11);
							break;
						case Memory:
							// Peripheral
							ClrBit(DMA1_CCR7,8);
							ClrBit(DMA1_CCR7,9);
							break;
						default:break;
					}
					break;
				case Word:
					switch(dma_source)
					{
						case Peripheral:
							// Memory
							SetBit(DMA1_CCR7,10);
							ClrBit(DMA1_CCR7,11);
							break;
						case Memory:
							// Peripheral
							SetBit(DMA1_CCR7,8);
							ClrBit(DMA1_CCR7,9);
							break;
						default:break;
					}
					break;
				case Dword:
					switch(dma_source)
					{
						case Peripheral:
							// Memory
							ClrBit(DMA1_CCR7,10);
							SetBit(DMA1_CCR7,11);
							break;
						case Memory:
							// Peripheral
							ClrBit(DMA1_CCR7,8);
							SetBit(DMA1_CCR7,9);
							break;
						default:break;
					}
					break;
				default:break;
			}
			break;
		default:break;
	}
}
void DMA_Source_Size(DMA_CHANNEL dma_channel,DMA_SOURCE dma_source,DATA_SIZE data_size)
{
	switch(dma_channel)
	{
		case DMA_CH1:
			switch(data_size)
			{
				case Byte:
					switch(dma_source)
					{
						case Peripheral:
							// Peripheral
							ClrBit(DMA1_CCR1,8);
							ClrBit(DMA1_CCR1,9);
							break;
						case Memory:
							// Memory
							ClrBit(DMA1_CCR1,10);
							ClrBit(DMA1_CCR1,11);
							break;
						default:break;
					}
					break;
				case Word:
					switch(dma_source)
					{
						case Peripheral:
							// Memory
							SetBit(DMA1_CCR1,8);
							ClrBit(DMA1_CCR1,9);
							break;
						case Memory:
							// Peripheral
							SetBit(DMA1_CCR1,10);
							ClrBit(DMA1_CCR1,11);
							break;
						default:break;
					}
					break;
				case Dword:
					switch(dma_source)
					{
						case Peripheral:
							// Memory
							ClrBit(DMA1_CCR1,8);
							SetBit(DMA1_CCR1,9);
							break;
						case Memory:
							// Peripheral
							ClrBit(DMA1_CCR1,10);
							SetBit(DMA1_CCR1,11);
							break;
						default:break;
					}
					break;
				default:break;
			}
			break;
		case DMA_CH2:
			switch(data_size)
			{
				case Byte:
					switch(dma_source)
					{
						case Peripheral:
							// Peripheral
							ClrBit(DMA1_CCR2,8);
							ClrBit(DMA1_CCR2,9);
							break;
						case Memory:
							// Memory
							ClrBit(DMA1_CCR2,10);
							ClrBit(DMA1_CCR2,11);
							break;
						default:break;
					}
					break;
				case Word:
					switch(dma_source)
					{
						case Peripheral:
							// Peripheral
							SetBit(DMA1_CCR2,8);
							ClrBit(DMA1_CCR2,9);
							break;
						case Memory:
							// Memory
							SetBit(DMA1_CCR2,10);
							ClrBit(DMA1_CCR2,11);
							break;
						default:break;
					}
					break;
				case Dword:
					switch(dma_source)
					{
						case Peripheral:
							// Peripheral
							ClrBit(DMA1_CCR2,8);
							SetBit(DMA1_CCR2,9);
							break;
						case Memory:
							// Memory
							ClrBit(DMA1_CCR2,10);
							SetBit(DMA1_CCR2,11);
							break;
						default:break;
					}
					break;
				default:break;
			}
			break;
		case DMA_CH3:
			switch(data_size)
			{
				case Byte:
					switch(dma_source)
					{
						case Peripheral:
							// Peripheral
							ClrBit(DMA1_CCR3,8);
							ClrBit(DMA1_CCR3,9);
							break;
						case Memory:
							// Memory
							ClrBit(DMA1_CCR3,10);
							ClrBit(DMA1_CCR3,11);
							break;
						default:break;
					}
					break;
				case Word:
					switch(dma_source)
					{
						case Peripheral:
							// Peripheral
							SetBit(DMA1_CCR3,8);
							ClrBit(DMA1_CCR3,9);
							break;
						case Memory:
							// Memory
							SetBit(DMA1_CCR3,10);
							ClrBit(DMA1_CCR3,11);
							break;
						default:break;
					}
					break;
				case Dword:
					switch(dma_source)
					{
						case Peripheral:
							// Peripheral
							ClrBit(DMA1_CCR3,8);
							SetBit(DMA1_CCR3,9);
							break;
						case Memory:
							// Memory
							ClrBit(DMA1_CCR3,10);
							SetBit(DMA1_CCR3,11);
							break;
						default:break;
					}
					break;
				default:break;
			}
			break;
		case DMA_CH4:
			switch(data_size)
			{
				case Byte:
					switch(dma_source)
					{
						case Peripheral:
							// Peripheral
							ClrBit(DMA1_CCR4,8);
							ClrBit(DMA1_CCR4,9);
							break;
						case Memory:
							// Memory
							ClrBit(DMA1_CCR4,10);
							ClrBit(DMA1_CCR4,11);
							break;
						default:break;
					}
					break;
				case Word:
					switch(dma_source)
					{
						case Peripheral:
							// Peripheral
							SetBit(DMA1_CCR4,8);
							ClrBit(DMA1_CCR4,9);
							break;
						case Memory:
							// Memory
							SetBit(DMA1_CCR4,10);
							ClrBit(DMA1_CCR4,11);
							break;
						default:break;
					}
					break;
				case Dword:
					switch(dma_source)
					{
						case Peripheral:
							// Peripheral
							ClrBit(DMA1_CCR4,8);
							SetBit(DMA1_CCR4,9);
							break;
						case Memory:
							// Memory
							ClrBit(DMA1_CCR4,10);
							SetBit(DMA1_CCR4,11);
							break;
						default:break;
					}
					break;
				default:break;
			}
			break;
		case DMA_CH5:
			switch(data_size)
			{
				case Byte:
					switch(dma_source)
					{
						case Peripheral:
							// Peripheral
							ClrBit(DMA1_CCR5,8);
							ClrBit(DMA1_CCR5,9);
							break;
						case Memory:
							// Memory
							ClrBit(DMA1_CCR5,10);
							ClrBit(DMA1_CCR5,11);
							break;
						default:break;
					}
					break;
				case Word:
					switch(dma_source)
					{
						case Peripheral:
							// Peripheral
							SetBit(DMA1_CCR5,8);
							ClrBit(DMA1_CCR5,9);
							break;
						case Memory:
							// Memory
							SetBit(DMA1_CCR5,10);
							ClrBit(DMA1_CCR5,11);
							break;
						default:break;
					}
					break;
				case Dword:
					switch(dma_source)
					{
						case Peripheral:
							// Peripheral
							ClrBit(DMA1_CCR5,8);
							SetBit(DMA1_CCR5,9);
							break;
						case Memory:
							// Memory
							ClrBit(DMA1_CCR5,10);
							SetBit(DMA1_CCR5,11);
							break;
						default:break;
					}
					break;
				default:break;
			}
			break;
		case DMA_CH6:
			switch(data_size)
			{
				case Byte:
					switch(dma_source)
					{
						case Peripheral:
							//Peripheral
							ClrBit(DMA1_CCR6,8);
							ClrBit(DMA1_CCR6,9);
							break;
						case Memory:
							// Memory
							ClrBit(DMA1_CCR6,10);
							ClrBit(DMA1_CCR6,11);
							break;
						default:break;
					}
					break;
				case Word:
					switch(dma_source)
					{
						case Peripheral:
							// Peripheral
							SetBit(DMA1_CCR6,8);
							ClrBit(DMA1_CCR6,9);
							break;
						case Memory:
							// Memory
							SetBit(DMA1_CCR6,10);
							ClrBit(DMA1_CCR6,11);
							break;
						default:break;
					}
					break;
				case Dword:
					switch(dma_source)
					{
						case Peripheral:
							// Peripheral
							ClrBit(DMA1_CCR6,8);
							SetBit(DMA1_CCR6,9);
							break;
						case Memory:
							// Memory
							ClrBit(DMA1_CCR6,10);
							SetBit(DMA1_CCR6,11);
							break;
						default:break;
					}
					break;
				default:break;
			}
			break;
		case DMA_CH7:
			switch(data_size)
			{
				case Byte:
					switch(dma_source)
					{
						case Peripheral:
							// Peripheral
							ClrBit(DMA1_CCR7,8);
							ClrBit(DMA1_CCR7,9);
							break;
						case Memory:
							// Memory
							ClrBit(DMA1_CCR7,10);
							ClrBit(DMA1_CCR7,11);
							break;
						default:break;
					}
					break;
				case Word:
					switch(dma_source)
					{
						case Peripheral:
							// Peripheral
							SetBit(DMA1_CCR7,8);
							ClrBit(DMA1_CCR7,9);
							break;
						case Memory:
							// Memory
							SetBit(DMA1_CCR7,10);
							ClrBit(DMA1_CCR7,11);
							break;
						default:break;
					}
					break;
				case Dword:
					switch(dma_source)
					{
						case Peripheral:
							// Peripheral
							ClrBit(DMA1_CCR7,8);
							SetBit(DMA1_CCR7,9);
							break;
						case Memory:
							// Memory
							ClrBit(DMA1_CCR7,10);
							SetBit(DMA1_CCR7,11);
							break;
						default:break;
					}
					break;
				default:break;
			}
			break;
		default:break;
	}
}
void DMA_Direction(DMA_CHANNEL dma_channel,DMA_SOURCE dma_source)
{
	switch(dma_channel)
	{
		case DMA_CH1:
			switch(dma_source)
			{
				case Peripheral:
					ClrBit(DMA1_CCR1,4);
					break;
				case Memory:
					SetBit(DMA1_CCR1,4);
					break;
				default:break;
			}
			break;
		case DMA_CH2:
			switch(dma_source)
			{
				case Peripheral:
					ClrBit(DMA1_CCR2,4);
					break;
				case Memory:
					SetBit(DMA1_CCR2,4);
					break;
				default:break;
			}
			break;
		case DMA_CH3:
			switch(dma_source)
			{
				case Peripheral:
					ClrBit(DMA1_CCR3,4);
					break;
				case Memory:
					SetBit(DMA1_CCR3,4);
					break;
				default:break;
			}
			break;
		case DMA_CH4:
			switch(dma_source)
			{
				case Peripheral:
					ClrBit(DMA1_CCR4,4);
					break;
				case Memory:
					SetBit(DMA1_CCR4,4);
					break;
				default:break;
			}
			break;
		case DMA_CH5:
			switch(dma_source)
			{
				case Peripheral:
					ClrBit(DMA1_CCR5,4);
					break;
				case Memory:
					SetBit(DMA1_CCR5,4);
					break;
				default:break;
			}
			break;
		case DMA_CH6:
			switch(dma_source)
			{
				case Peripheral:
					ClrBit(DMA1_CCR6,4);
					break;
				case Memory:
					SetBit(DMA1_CCR6,4);
					break;
				default:break;
			}
			break;
		case DMA_CH7:
			switch(dma_source)
			{
				case Peripheral:
					ClrBit(DMA1_CCR7,4);
					break;
				case Memory:
					SetBit(DMA1_CCR7,4);
					break;
				default:break;
			}
			break;
		default:break;
	}
}

void DMA_Mode(DMA_CHANNEL dma_channel)
{
	switch(dma_channel)
	{
		case DMA_CH1:
			// Increment Memory Address
			SetBit(DMA1_CCR1,7);
			// Enable Circular Mode
			SetBit(DMA1_CCR1,5);
			break;
		case DMA_CH2:
			// Increment Memory Address
			SetBit(DMA1_CCR2,7);
			// Enable Circular Mode
			SetBit(DMA1_CCR2,5);
			break;
		case DMA_CH3:
			// Increment Memory Address
			SetBit(DMA1_CCR3,7);
			// Enable Circular Mode
			SetBit(DMA1_CCR3,5);
			break;
		case DMA_CH4:
			// Increment Memory Address
			SetBit(DMA1_CCR4,7);
			// Enable Circular Mode
			SetBit(DMA1_CCR4,5);
			break;
		case DMA_CH5:
			// Increment Memory Address
			SetBit(DMA1_CCR5,7);
			// Enable Circular Mode
			SetBit(DMA1_CCR5,5);
			break;
		case DMA_CH6:
			// Increment Memory Address
			SetBit(DMA1_CCR6,7);
			// Enable Circular Mode
			SetBit(DMA1_CCR6,5);
			break;
		case DMA_CH7:
			// Increment Memory Address
			SetBit(DMA1_CCR7,7);
			// Enable Circular Mode
			SetBit(DMA1_CCR7,5);
			break;
		default:break;
	}
}

// ISR Section //

void DMA1_Channel1_IRQHandler (void)
{
	SetBit(DMA1_IFCR,0);
	DMA_CH1_ISR();
}
void DMA1_Channel2_IRQHandler (void)
{
	SetBit(DMA1_IFCR,4);
	DMA_CH2_ISR();
}
void DMA1_Channel3_IRQHandler (void)
{
	SetBit(DMA1_IFCR,8);
	DMA_CH3_ISR();
}
void DMA1_Channel4_IRQHandler (void)
{
	SetBit(DMA1_IFCR,12);
	DMA_CH4_ISR();
}
void DMA1_Channel5_IRQHandler (void)
{
	SetBit(DMA1_IFCR,16);
	DMA_CH5_ISR();
}
void DMA1_Channel6_IRQHandler (void)
{
	SetBit(DMA1_IFCR,20);
	DMA_CH6_ISR();
}
void DMA1_Channel7_IRQHandler (void)
{
	SetBit(DMA1_IFCR,24);
	DMA_CH7_ISR();
}
