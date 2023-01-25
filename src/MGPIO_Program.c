/******************************************************************************************/
/* Author 	       :	Kareem Elsayyad                                                   */
/* Version         :	V0.0.0                                                            */
/* Date	           :	22 / 1 / 20232                                                    */
/* Description     :	MGPIO_Interface.h -> Prototypes, Enumerators & Macros             */
/* Module Features :																	  */
/*				01- MGPIO_voidSetPinMode												  */
/*				02- MGPIO_voidSetOutputType												  */
/*				03- MGPIO_voidSetOutputPinSpeed											  */
/*				04- MGPIO_voidSetInputPinPullType										  */
/*				05- MGPIO_voidSetPinValue												  */
/*				06- MGPIO_voidGetPinValue												  */
/* TODO:																				  */
/* 				07-MGPIO_voidLockPin													  */
/* 				08-MGPIO_voidSetResetPin												  */
/* 				09-MGPIO_voidSetPinAlternativeFunction									  */
/******************************************************************************************/

/******************************************************************************************/
/*-------------------------------- Includes ----------------------------------------------*/
/******************************************************************************************/

/******************************************************************************************/
/*                            Standard Types LIB                                          */
/******************************************************************************************/
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "LERROR_STATES.h"

/******************************************************************************************/
/*                              Module Headers                                            */
/******************************************************************************************/
#include "MGPIO_Private.h"
#include "MGPIO_Config.h"
#include "MGPIO_Interface.h"


/******************************************************************************************/
/*-------------------------------- Function Implementation -------------------------------*/
/******************************************************************************************/

/******************************************************************************************/
/*							01- MGPIO_voidSetPinMode	                                  */
/*----------------------------------------------------------------------------------------*/
/* @function 		MGPIO_voidSetPinMode     											  */
/* @brief 			This function is used to set pin mode								  */
/* 						-Input															  */
/* 						-Output															  */
/* 						-Analog															  */
/* 						-Alternative Function											  */
/* @param[in]	Copy_uddtPortName : GPIO Port which will be configured		      	  	  */
/*		[MGPIO_PORTA - MGPIO_PORTB - MGPIO_PORTC]							  			  */
/* @param[in]	Copy_uddtPinNum															  */
/*		MGPIO_PIN[0:15]														  			  */
/* @param[in]	Copy_u8PinMode															  */
/*		[MGPIO_PIN_INPUT - MGPIO_PIN_OUTPUT - MGPIO_PIN_ALTF - MGPIO_PIN_ANALOG]		  */
/******************************************************************************************/
void MGPIO_voidSetPinMode(PortName_t Copy_uddtPortName, PinNum_t Copy_uddtPinNum, MGPIO_PinMode_t Copy_u8PinMode)
{
	switch (Copy_uddtPortName)
	{
	case MGPIO_PORTA:
		CLR_BITS(MGPIOA->MODER, (3U << Copy_uddtPinNum * 2U));
		MGPIOA->MODER |= (u32)(Copy_u8PinMode << (Copy_uddtPinNum * 2U));	break;
	case MGPIO_PORTB:
		CLR_BITS(MGPIOB->MODER, (3U << Copy_uddtPinNum * 2U));
		MGPIOB->MODER |= (u32)(Copy_u8PinMode << (Copy_uddtPinNum * 2U));	break;
	case MGPIO_PORTC:
		CLR_BITS(MGPIOC->MODER, (3U << Copy_uddtPinNum * 2U));
		MGPIOC->MODER |= (u32)(Copy_u8PinMode << (Copy_uddtPinNum * 2U));	break;
	default: /* ERROR */	;	break;
	}
}


/******************************************************************************************/
/*							02- MGPIO_voidSetOutputPinType                                */
/*----------------------------------------------------------------------------------------*/
/* @function 		MGPIO_voidSetOutputType    											  */
/* @brief 			This function is used to set output pin type						  */
/* 						-Push-Pull														  */
/* 						-Open Drain														  */
/* @param[in]	Copy_uddtPortName : GPIO Port which will be configured		      	  	  */
/*		[MGPIO_PORTA - MGPIO_PORTB - MGPIO_PORTC]							  			  */
/* @param[in]	Copy_uddtPinNum															  */
/*		MGPIO_PIN[0:15]														  			  */
/* @param[in]	Copy_uddtOutputType														  */
/*		[MGPIO_PUSH_PULL - MGPIO_OPEN_DRAIN]											  */
/******************************************************************************************/
void MGPIO_voidSetOutputPinType(PortName_t Copy_uddtPortName, PinNum_t Copy_uddtPinNum, MGPIO_OutputType_t Copy_uddtOutputType)
{
	switch (Copy_uddtPortName)
	{
	case MGPIO_PORTA:
		CLR_BITS(MGPIOA->OTYPER, (3U << Copy_uddtPinNum * 2U));
		MGPIOA->OTYPER |= (u32)(Copy_uddtOutputType << Copy_uddtPinNum);	break;
	case MGPIO_PORTB:
		CLR_BITS(MGPIOB->MODER, (3U << Copy_uddtPinNum * 2U));
		MGPIOB->OTYPER |= (u32)(Copy_uddtOutputType << Copy_uddtPinNum);	break;
	case MGPIO_PORTC:
		CLR_BITS(MGPIOC->MODER, (3U << Copy_uddtPinNum * 2U));
		MGPIOC->OTYPER |= (u32)(Copy_uddtOutputType << Copy_uddtPinNum);	break;
	default: /* ERROR */	;	break;
	}
}


/******************************************************************************************/
/*							03- MGPIO_voidSetOutputPinSpeed                               */
/*----------------------------------------------------------------------------------------*/
/* @function 		MGPIO_voidSetOutputType    											  */
/* @brief 			This function is used to set output pin speed						  */
/* 						-Low Speed														  */
/* 						-Medium	Speed													  */
/* 						-High Speed														  */
/* 						-Very High Speed												  */
/* @param[in]	Copy_uddtPortName : GPIO Port which will be configured		      	  	  */
/*		[MGPIO_PORTA - MGPIO_PORTB - MGPIO_PORTC]							  			  */
/* @param[in]	Copy_uddtPinNum															  */
/*		MGPIO_PIN[0:15]														  			  */
/* @param[in]	Copy_uddtPinSpeed														  */
/*		[MGPIO_SPEED_LOW - MGPIO_SPEED_MEDIUM - MGPIO_SPEED_HIGH - MGPIO_SPEED_VHIGH]	  */
/******************************************************************************************/
void MGPIO_voidSetOutputPinSpeed(PortName_t Copy_uddtPortName, PinNum_t Copy_uddtPinNum, MGPIO_PinSpeed_t Copy_uddtPinSpeed)
{
	switch (Copy_uddtPortName)
	{
	case MGPIO_PORTA:
		CLR_BITS(MGPIOA->OSPEEDR, 3U << (Copy_uddtPinNum * 2U));
		MGPIOA->OSPEEDR |= (u32)(Copy_uddtPinSpeed << (Copy_uddtPinNum * 2U));	break;
	case MGPIO_PORTB:
		CLR_BITS(MGPIOB->OSPEEDR, 3U << (Copy_uddtPinNum * 2U));
		MGPIOB->OSPEEDR |= (u32)(Copy_uddtPinSpeed << (Copy_uddtPinNum * 2U));	break;
	case MGPIO_PORTC:
		CLR_BITS(MGPIOC->OSPEEDR, 3U << (Copy_uddtPinNum * 2U));
		MGPIOC->OSPEEDR |= (u32)(Copy_uddtPinSpeed << (Copy_uddtPinNum * 2U));	break;
	default: /* ERROR */	;	break;
	}
}


/******************************************************************************************/
/*							04- MGPIO_voidSetInputPinPullType                             */
/*----------------------------------------------------------------------------------------*/
/* @function 		MGPIO_voidSetInputPinPullType										  */
/* @brief 			This function is used to set input pin pull type					  */
/* 						-Pull-Up														  */
/* 						-Pull-Down														  */
/* 						-Floating														  */
/* @param[in]	Copy_uddtPortName : GPIO Port which will be configured		      	  	  */
/*		[MGPIO_PORTA - MGPIO_PORTB - MGPIO_PORTC]							  			  */
/* @param[in]	Copy_uddtPinNum															  */
/*		MGPIO_PIN[0:15]														  			  */
/* @param[in]	Copy_uddtPinSpeed														  */
/*		[MGPIO_PIN_FLOAT - MGPIO_PIN_PULLUP - MGPIO_PIN_PULLDOWN]						  */
/******************************************************************************************/
void MGPIO_voidSetInputPinPullType(PortName_t Copy_uddtPortName, PinNum_t Copy_uddtPinNum, MGPIO_PullMode_t Copy_uddtPullType)
{
	switch(Copy_uddtPortName)
	{
	case MGPIO_PORTA:
		CLR_BITS(MGPIOA->PUPDR, 3U << (Copy_uddtPinNum * 2U));
		MGPIOA->PUPDR |= (u32)(Copy_uddtPullType << (Copy_uddtPinNum * 2U));	break;
	case MGPIO_PORTB:
		CLR_BITS(MGPIOB->PUPDR, 3U << (Copy_uddtPinNum * 2U));
		MGPIOB->PUPDR |= (u32)(Copy_uddtPullType << (Copy_uddtPinNum * 2U));	break;
	case MGPIO_PORTC:
		CLR_BITS(MGPIOC->PUPDR, 3U << (Copy_uddtPinNum * 2U));
		MGPIOC->PUPDR |= (u32)(Copy_uddtPullType << (Copy_uddtPinNum * 2U));	break;
	default: /* ERROR */	;	break;
	}
}


/******************************************************************************************/
/*							05- MGPIO_voidSetPinValue	                                  */
/*----------------------------------------------------------------------------------------*/
/* @function 		MGPIO_voidSetInputPinPullType										  */
/* @brief 			This function is used to set output pin value						  */
/* 						-High															  */
/* 						-Low															  */
/* @param[in]	Copy_uddtPortName : GPIO Port which will be configured		      	  	  */
/*		[MGPIO_PORTA - MGPIO_PORTB - MGPIO_PORTC]							  			  */
/* @param[in]	Copy_uddtPinNum															  */
/*		MGPIO_PIN[0:15]														  			  */
/* @param[in]	Copy_u8PinValue															  */
/*		[MGPIO_PIN_HIGH - MGPIO_PIN_LOW]												  */
/******************************************************************************************/
void MGPIO_voidSetPinValue(PortName_t Copy_uddtPortName, PinNum_t Copy_uddtPinNum, u8 Copy_u8PinValue)
{
	if (Copy_u8PinValue == MGPIO_PIN_HIGH)
	{
		switch(Copy_uddtPortName)
		{
		case MGPIO_PORTA:	MGPIOA->ODR |= (1U << Copy_uddtPinNum);	break;
		case MGPIO_PORTB:	MGPIOB->ODR |= (1U << Copy_uddtPinNum);	break;
		case MGPIO_PORTC:	MGPIOC->ODR |= (1U << Copy_uddtPinNum);	break;
		default: /* ERROR */	;	break;
		}
	}
	else if(Copy_u8PinValue == MGPIO_PIN_LOW)
	{
		switch(Copy_uddtPortName)
		{
		case MGPIO_PORTA:	MGPIOA->ODR &= ~(1U << Copy_uddtPinNum);	break;
		case MGPIO_PORTB:	MGPIOB->ODR &= ~(1U << Copy_uddtPinNum);	break;
		case MGPIO_PORTC:	MGPIOC->ODR &= ~(1U << Copy_uddtPinNum);	break;
		default: /* ERROR */	;	break;
		}
	}
	else
	{
		/* ERROR */
	}
}


/******************************************************************************************/
/*							06- MGPIO_voidSetPinValue	                                  */
/*----------------------------------------------------------------------------------------*/
/* @function 		MGPIO_voidSetInputPinPullType										  */
/* @brief 			This function is used to set output pin type						  */
/* 						-Push-Pull														  */
/* 						-Open Drain														  */
/* @param[in]	Copy_uddtPortName : GPIO Port which will be configured		      	  	  */
/*		[MGPIO_PORTA - MGPIO_PORTB - MGPIO_PORTC]							  			  */
/* @param[in]	Copy_uddtPinNum															  */
/*		MGPIO_PIN[0:15]														  			  */
/* @param[in]	Copy_pu8PinValue -> Address of variable to be updated					  */
/******************************************************************************************/
void MGPIO_voidGetPinValue(PortName_t Copy_uddtPortName, PinNum_t Copy_uddtPinNum, u8 *Copy_pu8PinValue)
{
	switch(Copy_uddtPortName)
	{
	case MGPIO_PORTA:	*Copy_pu8PinValue = MGPIOA->IDR >> (Copy_uddtPinNum & 1U);	break;
	case MGPIO_PORTB:	*Copy_pu8PinValue = MGPIOB->IDR >> (Copy_uddtPinNum & 1U);	break;
	case MGPIO_PORTC:	*Copy_pu8PinValue = MGPIOC->IDR >> (Copy_uddtPinNum & 1U);	break;
	default: /* ERROR */	;	break;
	}
}


/******************************************************************************************/
/*							07- MGPIO_voidSetPortValue	                                  */
/*----------------------------------------------------------------------------------------*/
/* @function 		MGPIO_voidSetInputPinPullType										  */
/* @brief 			This function is used to set output pin value						  */
/* 						-High															  */
/* 						-Low															  */
/* @param[in]	Copy_uddtPortName : GPIO Port which will be configured		      	  	  */
/*		[MGPIO_PORTA - MGPIO_PORTB - MGPIO_PORTC]							  			  */
/* @param[in]	Copy_u8PortValue -> Value to be written on port							  */
/******************************************************************************************/
void MGPIO_voidSetPortValue(PortName_t Copy_uddtPortName, u16 Copy_u32PortValue)
{
	switch(Copy_uddtPortName)
	{
	case MGPIO_PORTA:
		if(Copy_u32PortValue < 256)
		{
			MGPIOA->ODR = (MGPIOA->ODR & 0xFF00) | Copy_u32PortValue;
		}
		else
		{
			MGPIOA->ODR = Copy_u32PortValue;
		}
		break;
	case MGPIO_PORTB:
		if(Copy_u32PortValue < 256)
		{
			MGPIOB->ODR = (MGPIOB->ODR & 0xFF00) | Copy_u32PortValue;
		}
		else
		{
			MGPIOB->ODR = Copy_u32PortValue;
		}
		break;
	case MGPIO_PORTC:
		if(Copy_u32PortValue < 256)
		{
			MGPIOC->ODR = (MGPIOC->ODR & 0xFF00) | Copy_u32PortValue;
		}
		else
		{

			MGPIOC->ODR = Copy_u32PortValue;
		}
		break;
	default: /* ERROR */	;	break;
	}
}
