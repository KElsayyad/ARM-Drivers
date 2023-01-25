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
#ifndef MSTK_INTERFACE_H
#define MSTK_INTERFACE_H


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
/*							    	                                                      */
/******************************************************************************************/


/******************************************************************************************/
/*-------------------------------- Function Prototypes -----------------------------------*/
/******************************************************************************************/

/******************************************************************************************/
/*							01- MSTK_voidInit                                             */
/*----------------------------------------------------------------------------------------*/
/* @function 		MRCC_void_InitSystemClock											  */
/* @brief 			This function is used to initialise the system clock				  */
/* @param			void																  */
/******************************************************************************************/
void MSTK_voidInit(void);


/******************************************************************************************/
/*							02- MSTK_voidStart                                            */
/*----------------------------------------------------------------------------------------*/
/* @function 	MRCC_voidDisablePeripheralClock  									  	  */
/* @brief 		This function is used to disable peripheral clock    				  	  */
/* @param[in]	Copy_uddtBusName : Bus which the peripheral is connected to      	  	  */
/*		[AHB1 - AHB2 - APB1 - APB2]											  			  */
/* @param[in]	Copy_u8Peripheral														  */
/******************************************************************************************/
void MSTK_voidStart(u32 Copy_u32PreloadValue);


/******************************************************************************************/
/*							03- MSTK_u8ReadCountFlag                                      */
/*----------------------------------------------------------------------------------------*/
/* @function 	MRCC_voidEnablePeripheralClock  									  	  */
/* @brief 		This function is used to enable peripheral clock    				  	  */
/* @param[in]	Copy_uddtBusName : Bus which the peripheral is connected to      	  	  */
/*		[AHB1 - AHB2 - APB1 - APB2]											  			  */
/* @param[in]	Copy_u8Peripheral														  */
/******************************************************************************************/
u8 MSTK_u8ReadCountFlag(void);


/******************************************************************************************/
/*							04- MSTK_voidSetIntStatus                                     */
/*----------------------------------------------------------------------------------------*/
/* @function 	MRCC_voidChangeSystemClock											  	  */
/* @brief 		This function is used to change the system clock    				  	  */
/* @param[in]	Copy_uddtSystemClock : The system clock that is needed	        	  	  */
/*		[HSE - HSI - PLL]	      											  			  */
/******************************************************************************************/
void MSTK_voidSetIntStatus(u8 Copy_u8IntStatus);


/******************************************************************************************/
/*							04- MSTK_voidDelayMs                                          */
/*----------------------------------------------------------------------------------------*/
/* @function 	MRCC_voidChangeSystemClock											  	  */
/* @brief 		This function is used to change the system clock    				  	  */
/* @param[in]	Copy_uddtSystemClock : The system clock that is needed	        	  	  */
/*		[HSE - HSI - PLL]	      											  			  */
/******************************************************************************************/
void MSTK_voidDelayMs(u32 Copy_u32Time);


/******************************************************************************************/
/*							04- MSTK_voidDelayUs                                          */
/*----------------------------------------------------------------------------------------*/
/* @function 	MRCC_voidChangeSystemClock											  	  */
/* @brief 		This function is used to change the system clock    				  	  */
/* @param[in]	Copy_uddtSystemClock : The system clock that is needed	        	  	  */
/*		[HSE - HSI - PLL]	      											  			  */
/******************************************************************************************/
void MSTK_voidDelayUs(u32 Copy_u32Time);


/******************************************************************************************/
/*							05- MSTK_voidSetCallBack                                     */
/*----------------------------------------------------------------------------------------*/
/* @function 	MRCC_voidChangeSystemClock											  	  */
/* @brief 		This function is used to change the system clock    				  	  */
/* @param[in]	Copy_uddtSystemClock : The system clock that is needed	        	  	  */
/*		[HSE - HSI - PLL]	      											  			  */
/******************************************************************************************/
void MSTK_voidSetCallBack(void (*PFun)(void));


/******************************************************************************************/
/*------------------------------------- Macros -------------------------------------------*/
/******************************************************************************************/

#define DISABLE					0u
#define ENABLE					1u

#define MSTK_AHB_PRE8_CLK		0u
#define MSTK_AHB_CLK			1u

#endif /* MSTK_INTERFACE_H */
