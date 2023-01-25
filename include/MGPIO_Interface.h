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
/*				07- MGPIO_voidSetPortValue												  */
/* TODO:																				  */
/* 				08-MGPIO_voidLockPin													  */
/* 				09-MGPIO_voidSetResetPin												  */
/* 				10-MGPIO_voidSetPinAlternativeFunction									  */
/******************************************************************************************/
#ifndef MGPIO_INTERFACE_H
#define MGPIO_INTERFACE_H

/******************************************************************************************/
/*-------------------------------- Includes ----------------------------------------------*/
/******************************************************************************************/

/******************************************************************************************/
/*                            Standard Types LIB                                          */
/******************************************************************************************/
#include "LSTD_TYPES.h"
#include "LERROR_STATES.h"
#include "LBIT_MATH.h"


/******************************************************************************************/
/*-------------------------------- Enumerators -------------------------------------------*/
/******************************************************************************************/

/******************************************************************************************/
/*							    	Port Name                                     		  */
/******************************************************************************************/
typedef enum
{
	MGPIO_PORTA			,
	MGPIO_PORTB			,
	MGPIO_PORTC
}PortName_t;

/******************************************************************************************/
/*							    	Pin Name                                     		  */
/******************************************************************************************/
typedef enum
{
	PIN0 		,
	PIN1 		,
	PIN2 		,
	PIN3 		,
	PIN4 		,
	PIN5 		,
	PIN6 		,
	PIN7 		,
	PIN8 		,
	PIN9 		,
	PIN10 		,
	PIN11 		,
	PIN12 		,
	PIN13 		,
	PIN14 		,
	PIN15 		,
}PinNum_t;

/******************************************************************************************/
/*							    	Speed Type                                     		  */
/******************************************************************************************/
typedef enum
{
	MGPIO_SPEED_LOW			,
	MGPIO_SPEED_MEDIUM		,
	MGPIO_SPEED_HIGH		,
	MGPIO_SPEED_VHIGH
}MGPIO_PinSpeed_t;

/******************************************************************************************/
/*							    	Output Mode                                    		  */
/******************************************************************************************/
typedef enum
{
	MGPIO_PUSH_PULL		,
	MGPIO_OPEN_DRAIN
}MGPIO_OutputType_t;

/******************************************************************************************/
/*							    	Pull Mode                                    		  */
/******************************************************************************************/
typedef enum
{
	MGPIO_PIN_FLOAT			,
	MGPIO_PIN_PULLUP		,
	MGPIO_PIN_PULLDOWN
}MGPIO_PullMode_t;

/******************************************************************************************/
/*							    	Pin Mode                                     		  */
/******************************************************************************************/
typedef enum
{
	MGPIO_PIN_INPUT		,
	MGPIO_PIN_OUTPUT	,
	MGPIO_PIN_ALTF		,
	MGPIO_PIN_ANALOG
}MGPIO_PinMode_t;


/******************************************************************************************/
/*-------------------------------- Function Prototypes -----------------------------------*/
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
void MGPIO_voidSetPinMode(PortName_t Copy_uddtPortName, PinNum_t Copy_uddtPinNum, MGPIO_PinMode_t Copy_u8PinMode);


/******************************************************************************************/
/*							02- MGPIO_voidSetOutputType	                                  */
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
void MGPIO_voidSetOutputPinType(PortName_t Copy_uddtPortName, PinNum_t Copy_uddtPinNum, MGPIO_OutputType_t Copy_uddtOutputType);


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
void MGPIO_voidSetOutputPinSpeed(PortName_t Copy_uddtPortName, PinNum_t Copy_uddtPinNum, MGPIO_PinSpeed_t Copy_uddtPinSpeed);


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
void MGPIO_voidSetInputPinPullType(PortName_t Copy_uddtPortName, PinNum_t Copy_uddtPinNum, MGPIO_PullMode_t Copy_uddtPullType);


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
void MGPIO_voidSetPinValue(PortName_t Copy_uddtPortName, PinNum_t Copy_uddtPinNum, u8 Copy_u8PinValue);


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
void MGPIO_voidGetPinValue(PortName_t Copy_uddtPortName, PinNum_t Copy_uddtPinNum, u8 *Copy_pu8PinValue);


/******************************************************************************************/
/*							07- MGPIO_voidSetPortValue	                                  */
/*----------------------------------------------------------------------------------------*/
/* @function 		MGPIO_voidSetInputPinPullType										  */
/* @brief 			This function is used to set output pin value						  */
/* 						-High															  */
/* 						-Low															  */
/* @param[in]	Copy_uddtPortName : GPIO Port which will be configured		      	  	  */
/*		[MGPIO_PORTA - MGPIO_PORTB - MGPIO_PORTC]							  			  */
/* @param[in]	Copy_uddtPinNum															  */
/*		MGPIO_PIN[0:15]														  			  */
/* @param[in]	Copy_u32PortValue -> Value to be written on port					      */
/******************************************************************************************/
void MGPIO_voidSetPortValue(PortName_t Copy_uddtPortName, u16 Copy_u32PortValue);


/******************************************************************************************/
/*------------------------------------- Macros -------------------------------------------*/
/******************************************************************************************/

/******************************************************************************************/
/*							    	Pin Value                                     		  */
/******************************************************************************************/
#define MGPIO_PIN_HIGH		1u
#define MGPIO_PIN_LOW		0u


#endif /* MGPIO_INTERFACE_H */
