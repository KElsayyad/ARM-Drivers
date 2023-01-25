/******************************************************************************************/
/* Author 	       :	Kareem Elsayyad                                                   */
/* Version         :	V0.0.0                                                            */
/* Date	           :	18 / 1 / 20232                                                    */
/* Description     :	MRCC_Interface.h -> Prototypes, Enumerators & Macros              */
/* Module Features :																	  */
/*				01- MRCC_voidInitSystemClock											  */
/*				02- MRCC_voidDisablePeripheralSystemClock								  */
/*				03- MRCC_voidEnablePeripheralSystemClock								  */
/*				04- MRCC_voidChangeSystemClock   										  */
/******************************************************************************************/
#ifndef MRCC_INTERFACE_H
#define MRCC_INTERFACE_H


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
/*							    	Bus Name                                       */
/******************************************************************************************/
typedef enum
{
	AHB1 = 0	,
	AHB2		,
	APB1		,
	APB2
}BusName_t;


/******************************************************************************************/
/*							        Clock Name                                            */
/******************************************************************************************/
typedef enum
{
	HSE	= 0		,
	HSI			,
	PLL
}SystemClock_t;


/******************************************************************************************/
/*-------------------------------- Function Prototypes -----------------------------------*/
/******************************************************************************************/

/******************************************************************************************/
/*							01- MRCC_voidInitSystemClock                                  */
/*----------------------------------------------------------------------------------------*/
/* @function 		MRCC_void_InitSystemClock											  */
/* @brief 			This function is used to initialise the system clock				  */
/* @param			void																  */
/******************************************************************************************/
void MRCC_voidInitSystemClock(void);


/******************************************************************************************/
/*							02- MRCC_voidDisablePeripheralClock                           */
/*----------------------------------------------------------------------------------------*/
/* @function 	MRCC_voidDisablePeripheralClock  									  	  */
/* @brief 		This function is used to disable peripheral clock    				  	  */
/* @param[in]	Copy_uddtBusName : Bus which the peripheral is connected to      	  	  */
/*		[AHB1 - AHB2 - APB1 - APB2]											  			  */
/* @param[in]	Copy_u8Peripheral														  */
/******************************************************************************************/
void MRCC_voidDisablePeripheralClock(BusName_t Copy_uddtBusName, u8 Copy_u8Peripheral);


/******************************************************************************************/
/*							03- MRCC_voidDisablePeripheralClock                           */
/*----------------------------------------------------------------------------------------*/
/* @function 	MRCC_voidEnablePeripheralClock  									  	  */
/* @brief 		This function is used to enable peripheral clock    				  	  */
/* @param[in]	Copy_uddtBusName : Bus which the peripheral is connected to      	  	  */
/*		[AHB1 - AHB2 - APB1 - APB2]											  			  */
/* @param[in]	Copy_u8Peripheral														  */
/******************************************************************************************/
void MRCC_voidEnablePeripheralClock(BusName_t Copy_uddtBusName, u8 Copy_u8Peripheral);


/******************************************************************************************/
/*							04- MRCC_voidChangeSystemClock                                */
/*----------------------------------------------------------------------------------------*/
/* @function 	MRCC_voidChangeSystemClock											  	  */
/* @brief 		This function is used to change the system clock    				  	  */
/* @param[in]	Copy_uddtSystemClock : The system clock that is needed	        	  	  */
/*		[HSE - HSI - PLL]	      											  			  */
/******************************************************************************************/
void MRCC_voidChangeSystemClock(SystemClock_t Copy_uddtSystemClock);


/******************************************************************************************/
/*------------------------------------- Macros -------------------------------------------*/
/******************************************************************************************/

/******************************************************************************************/
/*                          RCC AHB1 Clock Enable (RCC_AHB1ENR)                           */
/******************************************************************************************/
#define MRCC_PERIPHERAL_EN_GPIOA       0U
#define MRCC_PERIPHERAL_EN_GPIOB       1U
#define MRCC_PERIPHERAL_EN_GPIOC       2U
#define MRCC_PERIPHERAL_EN_GPIOD       3U
#define MRCC_PERIPHERAL_EN_GPIOE       4U
#define MRCC_PERIPHERAL_EN_GPIOH       7U
#define MRCC_PERIPHERAL_EN_CRC         12U
#define MRCC_PERIPHERAL_EN_DMA1        21U
#define MRCC_PERIPHERAL_EN_DMA2        22U


/******************************************************************************************/
/*                          RCC AHB2 Clock Enable (RCC_AHB2ENR)                           */
/******************************************************************************************/
#define OTGFS_EN		7u


/******************************************************************************************/
/*                          RCC APB1 Clock Enable (RCC_APB1ENR)                           */
/******************************************************************************************/
#define MRCC_PERIPHERAL_TIM2_EN            0u
#define MRCC_PERIPHERAL_TIM3_EN            1u
#define MRCC_PERIPHERAL_TIM4_EN            2u
#define MRCC_PERIPHERAL_TIM5_EN            3u
#define MRCC_PERIPHERAL_WWDG_EN            11u
#define MRCC_PERIPHERAL_SPI2_EN            14u
#define MRCC_PERIPHERAL_SPI3_EN            15u
#define MRCC_PERIPHERAL_USART2_EN		   17u
#define MRCC_PERIPHERAL_I2C1_EN            21u
#define MRCC_PERIPHERAL_I2C2_EN            22u
#define MRCC_PERIPHERAL_I2C3_EN            23u
#define MRCC_PERIPHERAL_PWR_RST            28u


/******************************************************************************************/
/*                          RCC APB2 Clock Enable (RCC_APB2ENR)                           */
/******************************************************************************************/
#define MRCC_PERIPHERAL_TIM1_EN            0u
#define MRCC_PERIPHERAL_USART1_EN          4u
#define MRCC_PERIPHERAL_USART6_EN          5u
#define MRCC_PERIPHERAL_ADC1_EN            8u
#define MRCC_PERIPHERAL_SDIO_EN            11u
#define MRCC_PERIPHERAL_SPI1_EN            12u
#define MRCC_PERIPHERAL_SPI4_EN            13u
#define MRCC_PERIPHERAL_SYS_CFG_RST		   14u
#define MRCC_PERIPHERAL_TIM9_EN            16u
#define MRCC_PERIPHERAL_TIM10_EN           17u
#define MRCC_PERIPHERAL_TIM11_EN           18u


#endif /* MRCC_INTERFACE_H */
