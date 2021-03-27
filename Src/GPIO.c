/*
 * GPIO.c
 *
 *  Created on: Dec 15, 2020
 *      Author: Karim Hussein
 */


#include "GPIO.h"
#include "util.h"
#include "Regmap.h"


void GPIO_Init(PORT port)
{
	switch(port)
	{
		case PORTA:
			if(!GetBit(RCC_APB2ENR,2))
				SetBit(RCC_APB2ENR,2);
			break;
		case PORTB:
			if(!GetBit(RCC_APB2ENR,3))
				SetBit(RCC_APB2ENR,3);
			break;
		case PORTC:
			if(!GetBit(RCC_APB2ENR,4))
				SetBit(RCC_APB2ENR,4);
			break;
		case PORTD:
			if(!GetBit(RCC_APB2ENR,5))
				SetBit(RCC_APB2ENR,5);
			break;
 		default:break;
	}
}
void GPIO_PinDirection(PORT port,PIN pin,PIN_DIR pin_dir,PIN_MODE pin_mode)
{
   switch(port)
   {
   	   case PORTA:
   		   if(pin_dir == INPUT_PIN)
   		   {
   			   if(pin <= 7)
   			   {
   				// Mode (Input Mode)
   				   ClrBit(GPIOA_CRL,4*pin);
   				   ClrBit(GPIOA_CRL,((4*pin)+1));

   				   switch(pin_mode)
   				   {
   				   case Floating:
   	   				   // Configuration (Floating Input)
   						SetBit(GPIOA_CRL,((4*pin)+2));
   						ClrBit(GPIOA_CRL,((4*pin)+3));
   					   break;
   				   case Pull_Up:
   	   				   // Configuration (Pull_Up)
   						ClrBit(GPIOA_CRL,((4*pin)+2));
   						SetBit(GPIOA_CRL,((4*pin)+3));
   						SetBit(GPIOA_ODR,pin);
   					   break;
   				   case Pull_Down:
   	   				   // Configuration (Pull_Down)
   						ClrBit(GPIOA_CRL,((4*pin)+2));
   						SetBit(GPIOA_CRL,((4*pin)+3));
   						ClrBit(GPIOA_ODR,pin);
   					   break;
   				   case Analog:
   	   				   // Configuration (Analog Input)
   						ClrBit(GPIOA_CRL,((4*pin)+2));
   						ClrBit(GPIOA_CRL,((4*pin)+3));
   					   break;
   				   default:
   	   				   // Configuration (Floating Input)
   						SetBit(GPIOA_CRL,((4*pin)+2));
   						ClrBit(GPIOA_CRL,((4*pin)+3));
   					   break;
   				   }
   			   }
   			   else
   			   {
   				   // Mode (Input Mode)
   				    ClrBit(GPIOA_CRH,(4*(pin-8)));
   				    ClrBit(GPIOA_CRH,((4*(pin-8))+1));

   				   switch(pin_mode)
   				   {
   				   case Floating:
   	   				   // Configuration (Floating Input)
   						SetBit(GPIOA_CRH,((4*(pin-8))+2));
   						ClrBit(GPIOA_CRH,((4*(pin-8))+3));
   					   break;
   				   case Pull_Up:
   	   				   // Configuration (Pull_Up)
   						ClrBit(GPIOA_CRH,((4*(pin-8))+2));
   						SetBit(GPIOA_CRH,((4*(pin-8))+3));
   						SetBit(GPIOA_ODR,pin);
   					   break;
   				   case Pull_Down:
   	   				   // Configuration (Pull_Down)
   						ClrBit(GPIOA_CRH,((4*(pin-8))+2));
   						SetBit(GPIOA_CRH,((4*(pin-8))+3));
   						ClrBit(GPIOA_ODR,pin);
   					   break;
   				   case Analog:
   	   				   // Configuration (Analog Input)
   						ClrBit(GPIOA_CRH,((4*(pin-8))+2));
   						ClrBit(GPIOA_CRH,((4*(pin-8))+3));
   					   break;
   				   default:
   	   				   // Configuration (Floating Input)
   						SetBit(GPIOA_CRH,((4*(pin-8))+2));
   						ClrBit(GPIOA_CRH,((4*(pin-8))+3));
   					   break;
   				   }
   			   }
   		   }
   		   else if (pin_dir == OUTPUT_PIN)
   		   {
   			   if(pin <= 7)
   			   	{
   				   switch(pin_mode)
   				   {
   				   case Open_Drain:
      				// Mode (Output Mode -- 2 MHz)
      				ClrBit(GPIOA_CRL,4*pin);
      				SetBit(GPIOA_CRL,((4*pin)+1));
       			    // Configuration (Push-Pull Output)
      				SetBit(GPIOA_CRL,((4*pin)+2));
      				ClrBit(GPIOA_CRL,((4*pin)+3));
   					   break;
   				   case Push_Pull:
   					// Mode (Output Mode -- 2 MHz)
   					SetBit(GPIOA_CRL,4*pin);
   					ClrBit(GPIOA_CRL,((4*pin)+1));
       			    // Configuration (Push-Pull Output)
      				ClrBit(GPIOA_CRL,((4*pin)+2));
      				ClrBit(GPIOA_CRL,((4*pin)+3));
   					   break;
   				   case AF_PP:
        				// Mode (Output Mode -- 2 MHz)
        				SetBit(GPIOA_CRL,4*pin);
        				SetBit(GPIOA_CRL,((4*pin)+1));
         			    // Configuration (Push-Pull Output)
        				ClrBit(GPIOA_CRL,((4*pin)+2));
        				SetBit(GPIOA_CRL,((4*pin)+3));
   					   break;
   				   case AF_OD:
       				// Mode (Output Mode -- 2 MHz)
       				SetBit(GPIOA_CRL,4*pin);
       				SetBit(GPIOA_CRL,((4*pin)+1));
        			// Configuration (Push-Pull Output)
       				SetBit(GPIOA_CRL,((4*pin)+2));
       				SetBit(GPIOA_CRL,((4*pin)+3));
   					   break;
   				   default:
         				// Mode (Output Mode -- 2 MHz)
         				ClrBit(GPIOA_CRL,4*pin);
         				SetBit(GPIOA_CRL,((4*pin)+1));
          			    // Configuration (Push-Pull Output)
         				SetBit(GPIOA_CRL,((4*pin)+2));
         				ClrBit(GPIOA_CRL,((4*pin)+3));
   					   break;
   				   }
   			    }
   			   else
   			   	{
   	   				   switch(pin_mode)
   	   				   {
   	   				   case Open_Drain:
   	      				// Mode (Output Mode -- 2 MHz)
   	      				ClrBit(GPIOA_CRH,4*(pin-8));
   	      				SetBit(GPIOA_CRH,((4*(pin-8))+1));
   	       			    // Configuration (Push-Pull Output)
   	      				SetBit(GPIOA_CRH,((4*(pin-8))+2));
   	      				ClrBit(GPIOA_CRH,((4*(pin-8))+3));
   	   					   break;
   	   				   case Push_Pull:
   	   					// Mode (Output Mode -- 2 MHz)
   	   					SetBit(GPIOA_CRH,(4*(pin-8)));
   	   					ClrBit(GPIOA_CRH,((4*(pin-8))+1));
   	       			    // Configuration (Push-Pull Output)
   	      				ClrBit(GPIOA_CRH,((4*(pin-8))+2));
   	      				ClrBit(GPIOA_CRH,((4*(pin-8))+3));
   	   					   break;
   	   				   case AF_PP:
   	        				// Mode (Output Mode -- 2 MHz)
   	        				SetBit(GPIOA_CRH,4*(pin-8));
   	        				SetBit(GPIOA_CRH,((4*(pin-8))+1));
   	         			    // Configuration (Push-Pull Output)
   	        				ClrBit(GPIOA_CRH,((4*(pin-8))+2));
   	        				SetBit(GPIOA_CRH,((4*(pin-8))+3));
   	   					   break;
   	   				   case AF_OD:
   	       				// Mode (Output Mode -- 2 MHz)
   	       				SetBit(GPIOA_CRH,4*(pin-8));
   	       				SetBit(GPIOA_CRH,((4*(pin-8))+1));
   	        			// Configuration (Push-Pull Output)
   	       				SetBit(GPIOA_CRH,((4*(pin-8))+2));
   	       				SetBit(GPIOA_CRH,((4*(pin-8))+3));
   	   					   break;
   	   				   default:
   	         				// Mode (Output Mode -- 2 MHz)
   	         				ClrBit(GPIOA_CRH,4*(pin-8));
   	         				SetBit(GPIOA_CRH,((4*(pin-8))+1));
   	          			    // Configuration (Push-Pull Output)
   	         				SetBit(GPIOA_CRH,((4*(pin-8))+2));
   	         				ClrBit(GPIOA_CRH,((4*(pin-8))+3));
   	   					   break;
   	   				   }
   		   }
   		   }
   		   break;
   	   case PORTB:
   		   if(pin_dir == INPUT_PIN)
   		   {
   			   if(pin <= 7)
   			   {
   				// Mode (Input Mode)
   				   ClrBit(GPIOB_CRL,4*pin);
   				   ClrBit(GPIOB_CRL,((4*pin)+1));

   				   switch(pin_mode)
   				   {
   				   case Floating:
   	   				   // Configuration (Floating Input)
   						SetBit(GPIOB_CRL,((4*pin)+2));
   						ClrBit(GPIOB_CRL,((4*pin)+3));
   					   break;
   				   case Pull_Up:
   	   				   // Configuration (Pull_Up)
   						ClrBit(GPIOB_CRL,((4*pin)+2));
   						SetBit(GPIOB_CRL,((4*pin)+3));
   						SetBit(GPIOB_ODR,pin);
   					   break;
   				   case Pull_Down:
   	   				   // Configuration (Pull_Down)
   						ClrBit(GPIOB_CRL,((4*pin)+2));
   						SetBit(GPIOB_CRL,((4*pin)+3));
   						ClrBit(GPIOB_ODR,pin);
   					   break;
   				   case Analog:
   	   				   // Configuration (Analog Input)
   						ClrBit(GPIOB_CRL,((4*pin)+2));
   						ClrBit(GPIOB_CRL,((4*pin)+3));
   					   break;
   				   default:
   	   				   // Configuration (Floating Input)
   						SetBit(GPIOB_CRL,((4*pin)+2));
   						ClrBit(GPIOB_CRL,((4*pin)+3));
   					   break;
   				   }
   			   }
   			   else
   			   {
   				   // Mode (Input Mode)
   				    ClrBit(GPIOB_CRH,4*(pin-8));
   				    ClrBit(GPIOB_CRH,((4*(pin-8))+1));

   				   switch(pin_mode)
   				   {
   				   case Floating:
   	   				   // Configuration (Floating Input)
   						SetBit(GPIOB_CRH,((4*(pin-8))+2));
   						ClrBit(GPIOB_CRH,((4*(pin-8))+3));
   					   break;
   				   case Pull_Up:
   	   				   // Configuration (Pull_Up)
   						ClrBit(GPIOB_CRH,((4*(pin-8))+2));
   						SetBit(GPIOB_CRH,((4*(pin-8))+3));
   						SetBit(GPIOB_ODR,pin);
   					   break;
   				   case Pull_Down:
   	   				   // Configuration (Pull_Down)
   						ClrBit(GPIOB_CRH,((4*(pin-8))+2));
   						SetBit(GPIOB_CRH,((4*(pin-8))+3));
   						ClrBit(GPIOB_ODR,pin);
   					   break;
   				   case Analog:
   	   				   // Configuration (Analog Input)
   						ClrBit(GPIOB_CRH,((4*(pin-8))+2));
   						ClrBit(GPIOB_CRH,((4*(pin-8))+3));
   					   break;
   				   default:
   	   				   // Configuration (Floating Input)
   						SetBit(GPIOB_CRH,((4*(pin-8))+2));
   						ClrBit(GPIOB_CRH,((4*(pin-8))+3));
   					   break;
   				   }
   			   }
   		   }
   		   else if (pin_dir == OUTPUT_PIN)
   		   {
   			   if(pin <= 7)
   			   	{
   				   switch(pin_mode)
   				   {
   				   case Open_Drain:
      				// Mode (Output Mode -- 2 MHz)
      				ClrBit(GPIOB_CRL,4*pin);
      				SetBit(GPIOB_CRL,((4*pin)+1));
       			    // Configuration (Push-Pull Output)
      				SetBit(GPIOB_CRL,((4*pin)+2));
      				ClrBit(GPIOB_CRL,((4*pin)+3));
   					   break;
   				   case Push_Pull:
   					// Mode (Output Mode -- 2 MHz)
   					SetBit(GPIOB_CRL,4*pin);
   					ClrBit(GPIOB_CRL,((4*pin)+1));
       			    // Configuration (Push-Pull Output)
      				ClrBit(GPIOB_CRL,((4*pin)+2));
      				ClrBit(GPIOB_CRL,((4*pin)+3));
   					   break;
   				   case AF_PP:
        				// Mode (Output Mode -- 2 MHz)
        				SetBit(GPIOB_CRL,4*pin);
        				SetBit(GPIOB_CRL,((4*pin)+1));
         			    // Configuration (Push-Pull Output)
        				ClrBit(GPIOB_CRL,((4*pin)+2));
        				SetBit(GPIOB_CRL,((4*pin)+3));
   					   break;
   				   case AF_OD:
       				// Mode (Output Mode -- 2 MHz)
       				SetBit(GPIOB_CRL,4*pin);
       				SetBit(GPIOB_CRL,((4*pin)+1));
        			// Configuration (Push-Pull Output)
       				SetBit(GPIOB_CRL,((4*pin)+2));
       				SetBit(GPIOB_CRL,((4*pin)+3));
   					   break;
   				   default:
         				// Mode (Output Mode -- 2 MHz)
         				ClrBit(GPIOB_CRL,4*pin);
         				SetBit(GPIOB_CRL,((4*pin)+1));
          			    // Configuration (Push-Pull Output)
         				SetBit(GPIOB_CRL,((4*pin)+2));
         				ClrBit(GPIOB_CRL,((4*pin)+3));
   					   break;
   				   }
   			    }
   			   else
   			   	{
   	   				   switch(pin_mode)
   	   				   {
   	   				   case Open_Drain:
   	      				// Mode (Output Mode -- 2 MHz)
   	      				ClrBit(GPIOB_CRH,4*(pin-8));
   	      				SetBit(GPIOB_CRH,((4*(pin-8))+1));
   	       			    // Configuration (Push-Pull Output)
   	      				SetBit(GPIOB_CRH,((4*(pin-8))+2));
   	      				ClrBit(GPIOB_CRH,((4*(pin-8))+3));
   	   					   break;
   	   				   case Push_Pull:
   	   					// Mode (Output Mode -- 2 MHz)
   	   					SetBit(GPIOB_CRH,4*(pin-8));
   	   					ClrBit(GPIOB_CRH,((4*(pin-8))+1));
   	       			    // Configuration (Push-Pull Output)
   	      				ClrBit(GPIOB_CRH,((4*(pin-8))+2));
   	      				ClrBit(GPIOB_CRH,((4*(pin-8))+3));
   	   					   break;
   	   				   case AF_PP:
   	        				// Mode (Output Mode -- 2 MHz)
   	        				SetBit(GPIOB_CRH,4*(pin-8));
   	        				SetBit(GPIOB_CRH,((4*(pin-8))+1));
   	         			    // Configuration (Push-Pull Output)
   	        				ClrBit(GPIOB_CRH,((4*(pin-8))+2));
   	        				SetBit(GPIOB_CRH,((4*(pin-8))+3));
   	   					   break;
   	   				   case AF_OD:
   	       				// Mode (Output Mode -- 2 MHz)
   	       				SetBit(GPIOB_CRH,4*(pin-8));
   	       				SetBit(GPIOB_CRH,((4*(pin-8))+1));
   	        			// Configuration (Push-Pull Output)
   	       				SetBit(GPIOB_CRH,((4*(pin-8))+2));
   	       				SetBit(GPIOB_CRH,((4*(pin-8))+3));
   	   					   break;
   	   				   default:
   	         				// Mode (Output Mode -- 2 MHz)
   	         				ClrBit(GPIOB_CRH,4*(pin-8));
   	         				SetBit(GPIOB_CRH,((4*(pin-8))+1));
   	          			    // Configuration (Push-Pull Output)
   	         				SetBit(GPIOB_CRH,((4*(pin-8))+2));
   	         				ClrBit(GPIOB_CRH,((4*(pin-8))+3));
   	   					   break;
   	   				   }
   		   }
   		   }
   		   break;
   	   case PORTC:
   		   if(pin_dir == INPUT_PIN)
   		   {
   			   if(pin <= 7)
   			   {
   				// Mode (Input Mode)
   				   ClrBit(GPIOC_CRL,4*pin);
   				   ClrBit(GPIOC_CRL,((4*pin)+1));

   				   switch(pin_mode)
   				   {
   				   case Floating:
   	   				   // Configuration (Floating Input)
   						SetBit(GPIOC_CRL,((4*pin)+2));
   						ClrBit(GPIOC_CRL,((4*pin)+3));
   					   break;
   				   case Pull_Up:
   	   				   // Configuration (Pull_Up)
   						ClrBit(GPIOC_CRL,((4*pin)+2));
   						SetBit(GPIOC_CRL,((4*pin)+3));
   						SetBit(GPIOC_ODR,pin);
   					   break;
   				   case Pull_Down:
   	   				   // Configuration (Pull_Down)
   						ClrBit(GPIOC_CRL,((4*pin)+2));
   						SetBit(GPIOC_CRL,((4*pin)+3));
   						ClrBit(GPIOC_ODR,pin);
   					   break;
   				   case Analog:
   	   				   // Configuration (Analog Input)
   						ClrBit(GPIOC_CRL,((4*pin)+2));
   						ClrBit(GPIOC_CRL,((4*pin)+3));
   					   break;
   				   default:
   	   				   // Configuration (Floating Input)
   						SetBit(GPIOC_CRL,((4*pin)+2));
   						ClrBit(GPIOC_CRL,((4*pin)+3));
   					   break;
   				   }
   			   }
   			   else
   			   {
   				   // Mode (Input Mode)
   				    ClrBit(GPIOC_CRH,4*(pin-8));
   				    ClrBit(GPIOC_CRH,((4*(pin-8))+1));

   				   switch(pin_mode)
   				   {
   				   case Floating:
   	   				   // Configuration (Floating Input)
   						SetBit(GPIOC_CRH,((4*(pin-8))+2));
   						ClrBit(GPIOC_CRH,((4*(pin-8))+3));
   					   break;
   				   case Pull_Up:
   	   				   // Configuration (Pull_Up)
   						ClrBit(GPIOC_CRH,((4*(pin-8))+2));
   						SetBit(GPIOC_CRH,((4*(pin-8))+3));
   						SetBit(GPIOC_ODR,pin);
   					   break;
   				   case Pull_Down:
   	   				   // Configuration (Pull_Down)
   						ClrBit(GPIOC_CRH,((4*(pin-8))+2));
   						SetBit(GPIOC_CRH,((4*(pin-8))+3));
   						ClrBit(GPIOC_ODR,pin);
   					   break;
   				   case Analog:
   	   				   // Configuration (Analog Input)
   						ClrBit(GPIOC_CRH,((4*(pin-8))+2));
   						ClrBit(GPIOC_CRH,((4*(pin-8))+3));
   					   break;
   				   default:
   	   				   // Configuration (Floating Input)
   						SetBit(GPIOC_CRH,((4*(pin-8))+2));
   						ClrBit(GPIOC_CRH,((4*(pin-8))+3));
   					   break;
   				   }
   			   }
   		   }
   		   else if (pin_dir == OUTPUT_PIN)
   		   {
   			   if(pin <= 7)
   			   	{
   				   switch(pin_mode)
   				   {
   				   case Open_Drain:
      				// Mode (Output Mode -- 2 MHz)
      				ClrBit(GPIOC_CRL,4*pin);
      				SetBit(GPIOC_CRL,((4*pin)+1));
       			    // Configuration (Push-Pull Output)
      				SetBit(GPIOC_CRL,((4*pin)+2));
      				ClrBit(GPIOC_CRL,((4*pin)+3));
   					   break;
   				   case Push_Pull:
   					// Mode (Output Mode -- 2 MHz)
   					SetBit(GPIOC_CRL,4*pin);
   					ClrBit(GPIOC_CRL,((4*pin)+1));
       			    // Configuration (Push-Pull Output)
      				ClrBit(GPIOC_CRL,((4*pin)+2));
      				ClrBit(GPIOC_CRL,((4*pin)+3));
   					   break;
   				   case AF_PP:
        				// Mode (Output Mode -- 2 MHz)
        				SetBit(GPIOC_CRL,4*pin);
        				SetBit(GPIOC_CRL,((4*pin)+1));
         			    // Configuration (Push-Pull Output)
        				ClrBit(GPIOC_CRL,((4*pin)+2));
        				SetBit(GPIOC_CRL,((4*pin)+3));
   					   break;
   				   case AF_OD:
       				// Mode (Output Mode -- 2 MHz)
       				SetBit(GPIOC_CRL,4*pin);
       				SetBit(GPIOC_CRL,((4*pin)+1));
        			// Configuration (Push-Pull Output)
       				SetBit(GPIOC_CRL,((4*pin)+2));
       				SetBit(GPIOC_CRL,((4*pin)+3));
   					   break;
   				   default:
         				// Mode (Output Mode -- 2 MHz)
         				ClrBit(GPIOC_CRL,4*pin);
         				SetBit(GPIOC_CRL,((4*pin)+1));
          			    // Configuration (Push-Pull Output)
         				SetBit(GPIOC_CRL,((4*pin)+2));
         				ClrBit(GPIOC_CRL,((4*pin)+3));
   					   break;
   				   }
   			    }
   			   else
   			   	{
   	   				   switch(pin_mode)
   	   				   {
   	   				   case Open_Drain:
   	      				// Mode (Output Mode -- 2 MHz)
   	      				ClrBit(GPIOC_CRH,4*(pin-8));
   	      				SetBit(GPIOC_CRH,((4*(pin-8))+1));
   	       			    // Configuration (Push-Pull Output)
   	      				SetBit(GPIOC_CRH,((4*(pin-8))+2));
   	      				ClrBit(GPIOC_CRH,((4*(pin-8))+3));
   	   					   break;
   	   				   case Push_Pull:
   	   					// Mode (Output Mode -- 2 MHz)
   	   					SetBit(GPIOC_CRH,4*(pin-8));
   	   					ClrBit(GPIOC_CRH,((4*(pin-8))+1));
   	       			    // Configuration (Push-Pull Output)
   	      				ClrBit(GPIOC_CRH,((4*(pin-8))+2));
   	      				ClrBit(GPIOC_CRH,((4*(pin-8))+3));
   	   					   break;
   	   				   case AF_PP:
   	        				// Mode (Output Mode -- 2 MHz)
   	        				SetBit(GPIOC_CRH,4*(pin-8));
   	        				SetBit(GPIOC_CRH,((4*(pin-8))+1));
   	         			    // Configuration (Push-Pull Output)
   	        				ClrBit(GPIOC_CRH,((4*(pin-8))+2));
   	        				SetBit(GPIOC_CRH,((4*(pin-8))+3));
   	   					   break;
   	   				   case AF_OD:
   	       				// Mode (Output Mode -- 2 MHz)
   	       				SetBit(GPIOC_CRH,4*(pin-8));
   	       				SetBit(GPIOC_CRH,((4*(pin-8))+1));
   	        			// Configuration (Push-Pull Output)
   	       				SetBit(GPIOC_CRH,((4*(pin-8))+2));
   	       				SetBit(GPIOC_CRH,((4*(pin-8))+3));
   	   					   break;
   	   				   default:
   	         				// Mode (Output Mode -- 2 MHz)
   	         				ClrBit(GPIOC_CRH,4*(pin-8));
   	         				SetBit(GPIOC_CRH,((4*(pin-8))+1));
   	          			    // Configuration (Push-Pull Output)
   	         				SetBit(GPIOC_CRH,((4*(pin-8))+2));
   	         				ClrBit(GPIOC_CRH,((4*(pin-8))+3));
   	   					   break;
   	   				   }
   		   }
   		   break;
   	   default:break;
   }
   }
}




void GPIO_PinWrite(PORT port,PIN pin,PIN_STATE pin_state)
{
	switch(port)
	{
		case PORTA:
            if (pin_state == PIN_HIGH)
            {
            	SetBit(GPIOA_BSRR,pin);
            }
            else if (pin_state == PIN_LOW)
            {
            	SetBit(GPIOA_BRR,pin);
            }
			break;
		case PORTB:
            if (pin_state == PIN_HIGH)
            {
            	SetBit(GPIOB_BSRR,pin);
            }
            else if (pin_state == PIN_LOW)
            {
            	SetBit(GPIOB_BRR,pin);
            }
			break;
		case PORTC:
            if (pin_state == PIN_HIGH)
            {
            	SetBit(GPIOC_BSRR,pin);
            }
            else if (pin_state == PIN_LOW)
            {
            	SetBit(GPIOC_BRR,pin);
            }
			break;
		case PORTD:
            if (pin_state == PIN_HIGH)
            {
            	SetBit(GPIOD_BSRR,pin);
            }
            else if (pin_state == PIN_LOW)
            {
            	SetBit(GPIOD_BRR,pin);
            }
			break;
		default:break;
	}
}

unsigned char GPIO_PinRead(PORT port , PIN pin)
{
	switch(port)
	{
	case PORTA:
		return (GetBit(GPIOA_IDR,pin));
		break;
	case PORTB:
		return (GetBit(GPIOB_IDR,pin));
		break;
	case PORTC:
		return (GetBit(GPIOC_IDR,pin));
		break;
	case PORTD:
		return (GetBit(GPIOD_IDR,pin));
		break;
	default:break;
	}
}

void GPIO_PortWrite(PORT port,unsigned short data)
{
	switch(port)
	{
	case PORTA:
		GPIOA_ODR &= 0xFFFF0000 ;
		GPIOA_ODR |= data;
		break;
	case PORTB:
		GPIOB_ODR &= 0xFFFF0000 ;
		GPIOB_ODR |= data;
		break;
	case PORTC:
		GPIOC_ODR &= 0xFFFF0000 ;
		GPIOC_ODR |= data;
		break;
	case PORTD:
		GPIOD_ODR &= 0xFFFF0000 ;
		GPIOD_ODR |= data;
		break;
	default:break;
	}
}

unsigned short GPIO_PortRead(PORT port)
{
	switch(port)
	{
	case PORTA:
		return(GPIOA_ODR & 0x0000FFFF);
		break;
	case PORTB:
		return(GPIOB_ODR & 0x0000FFFF);
		break;
	case PORTC:
		return(GPIOC_ODR & 0x0000FFFF);
		break;
	case PORTD:
		return(GPIOD_ODR & 0x0000FFFF);
	    break;
	default:break;
	}
}
