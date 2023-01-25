/*
 * main.c
 *
 *  Created on: 23 Jan 2023
 *      Author: Kareem
 */

#include "MRCC_Interface.h"
#include "MGPIO_Interface.h"
#include "MSTK_Interface.h"

const u8 arrSSD[10] = {0b1111110, 0b0110000, 0b1101101,
					   0b1111001, 0b0110011, 0b1011011,
					   0b1011111, 0b1110000, 0b1111111,
					   0b1110011};

void APP_voidDelayMS(u32 Copy_u32Delay);
void APP_voidSsdCount();

void main (void)
{
	//use 16 MHz from HSI
	MRCC_voidInitSystemClock();
	MSTK_voidInit();
	MRCC_voidEnablePeripheralClock(AHB1, MRCC_PERIPHERAL_EN_GPIOA);
	MRCC_voidEnablePeripheralClock(AHB1, MRCC_PERIPHERAL_EN_GPIOB);

	MGPIO_voidSetPinMode(MGPIO_PORTA, PIN0, MGPIO_PIN_OUTPUT);
	MGPIO_voidSetPinMode(MGPIO_PORTA, PIN1, MGPIO_PIN_OUTPUT);
	MGPIO_voidSetPinMode(MGPIO_PORTA, PIN2, MGPIO_PIN_OUTPUT);
	MGPIO_voidSetPinMode(MGPIO_PORTA, PIN3, MGPIO_PIN_OUTPUT);
	MGPIO_voidSetPinMode(MGPIO_PORTA, PIN4, MGPIO_PIN_OUTPUT);
	MGPIO_voidSetPinMode(MGPIO_PORTA, PIN5, MGPIO_PIN_OUTPUT);
	MGPIO_voidSetPinMode(MGPIO_PORTA, PIN6, MGPIO_PIN_OUTPUT);

	MGPIO_voidSetPinMode(MGPIO_PORTB, PIN0, MGPIO_PIN_OUTPUT);
	MGPIO_voidSetPinMode(MGPIO_PORTB, PIN1, MGPIO_PIN_OUTPUT);
	MGPIO_voidSetPinMode(MGPIO_PORTB, PIN2, MGPIO_PIN_OUTPUT);
	MGPIO_voidSetPinMode(MGPIO_PORTB, PIN3, MGPIO_PIN_OUTPUT);
	MGPIO_voidSetPinMode(MGPIO_PORTB, PIN4, MGPIO_PIN_OUTPUT);
	MGPIO_voidSetPinMode(MGPIO_PORTB, PIN5, MGPIO_PIN_OUTPUT);
	MGPIO_voidSetPinMode(MGPIO_PORTB, PIN6, MGPIO_PIN_OUTPUT);

	while (1)
	{
		APP_voidSsdCount();
	}
}


void APP_voidDelayMS(u32 Copy_u32Delay)
{
	for(u32 i = 0 ; i < Copy_u32Delay * 300 ; i++)
	{
		asm("NOP") ;  //asembly instruction
	}
}

void APP_voidSsdCount()
{
	for (u8 i=0; i<10; i++)
	{
		MGPIO_voidSetPortValue(MGPIO_PORTA, arrSSD[i]);
		for (u8 y=0; y<10; y++)
		{
			MGPIO_voidSetPortValue(MGPIO_PORTB, arrSSD[y]);
			MSTK_voidDelayMs(1000);
		}

	}
}
