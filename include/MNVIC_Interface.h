/******************************************************************************************/
/* Author 	       :	Kareem Elsayyad                                                   */
/* Version         :	V0.0.0                                                            */
/* Date	           :	29 / 1 / 20232                                                    */
/* Description     :	MNVIC_Interface.h -> Prototypes, Enumerators & Macros             */
/* Module Features :																	  */
/*				01- MNVIC_voidEnableInterrupt											  */
/*				02- MNVIC_voidDisableInterrupt           								  */
/*				03- MNVIC_voidEnableInterruptPending    								  */
/*				04- MNVIC_voidDisableInterruptPending									  */
/*				05- MNVIC_u8InterruptActive												  */
/*				06- MNVIC_voidInitInterruptGroup										  */
/*				07- MNVIC_voidSetInterruptPriority										  */
/******************************************************************************************/
#ifndef MNVIC_INTERFACE_H
#define MNVIC_INTERFACE_H


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
typedef enum
{
 NVIC_GROUP_MODE_G16S0 = 3 ,
 NVIC_GROUP_MODE_G8S2      ,
 NVIC_GROUP_MODE_G4S4      ,
 NVIC_GROUP_MODE_G2S8      ,
 NVIC_GROUP_MODE_G0S16
}NVIC_GroupMode_t ;


/******************************************************************************************/
/*-------------------------------- Structures --------------------------------------------*/
/******************************************************************************************/
typedef struct
{
	u8 Copy_u8IntNum ;
	NVIC_GroupMode_t Copy_uddtGroupMode ;
	u8 Copy_GroupPriority  ;
	u8 Copy_SubPriority  ;

}NVIC_PriorityConfig_t ;


/******************************************************************************************/
/*-------------------------------- Function Prototypes -----------------------------------*/
/******************************************************************************************/

/******************************************************************************************/
/*							01- MNVIC_voidEnableInterrupt                                 */
/*----------------------------------------------------------------------------------------*/
/* @function 		MNVIC_voidEnableInterrupt											  */
/* @brief 			This function is used to enable interrupt							  */
/* @param[in]		Copy_u8IntNum : Interrupt number						      	  	  */
/******************************************************************************************/
void MNVIC_voidEnableInterrupt(u8 Copy_u8IntNum);


/******************************************************************************************/
/*							02- MNVIC_voidDisableInterrupt                                */
/*----------------------------------------------------------------------------------------*/
/* @function 		MNVIC_voidDisableInterrupt											  */
/* @brief 			This function is used to disable interrupt							  */
/* @param[in]		Copy_u8IntNum : Interrupt number						      	  	  */
/******************************************************************************************/
void MNVIC_voidDisableInterrupt(u8 Copy_u8IntNum);


/******************************************************************************************/
/*							03- MNVIC_voidEnableInterruptPending                          */
/*----------------------------------------------------------------------------------------*/
/* @function 		MNVIC_voidEnableInterruptPending								  	  */
/* @brief 			This function is used to enable interrupt pending  				  	  */
/* @param[in]		Copy_u8IntNum : Interrupt number						      	  	  */
/******************************************************************************************/
void MNVIC_voidEnableInterruptPending(u8 Copy_u8IntNum);


/******************************************************************************************/
/*							04- MNVIC_voidDisableInterruptPending                         */
/*----------------------------------------------------------------------------------------*/
/* @function 		MNVIC_voidDisableInterruptPending								  	  */
/* @brief 			This function is used to disable interrupt pending 				  	  */
/* @param[in]		Copy_u8IntNum : Interrupt number						      	  	  */
/******************************************************************************************/
void MNVIC_voidDisableInterruptPending(u8 Copy_u8IntNum);


/******************************************************************************************/
/*							05- MNVIC_u8InterruptActive                                   */
/*----------------------------------------------------------------------------------------*/
/* @function 	MNVIC_u8InterruptActive												  	  */
/* @brief 		This function is used to do hardware delay		    				  	  */
/* @param[in]	Copy_u8IntNum : Interrupt number						        	  	  */
/* @param[out]	u8 : Return interrupt flag								        	  	  */
/******************************************************************************************/
u8 MNVIC_u8InterruptActive(u8 Copy_u8IntNum);


/******************************************************************************************/
/*							06- MNVIC_voidInitInterruptGroup                              */
/*----------------------------------------------------------------------------------------*/
/* @function 	MNVIC_voidInitInterruptGroup										  	  */
/* @brief 		This function is used to do hardware delay		    				  	  */
/* @param[in]	Copy_uddtGroupMode : Interrupt grouping configuration					  */
/* 			[ NVIC_GROUP_MODE_G16S0, NVIC_GROUP_MODE_G8S2, NVIC_GROUP_MODE_G4S4			  */
/* 			  NVIC_GROUP_MODE_G4S4 , NVIC_GROUP_MODE_G2S8, NVIC_GROUP_MODE_G0S16 ]		  */
/******************************************************************************************/
void MNVIC_voidInitInterruptGroup(NVIC_GroupMode_t Copy_uddtGroupMode);


/******************************************************************************************/
/*							07- MNVIC_voidSetInterruptPriority                            */
/*----------------------------------------------------------------------------------------*/
/* @function 	MNVIC_voidSetInterruptPriority										  	  */
/* @brief 		This function is used to set the callback function for ISR			  	  */
/* @param[in]	Copy_PuddtPriorityConfig : Structure contain the interrupt configuration  */
/******************************************************************************************/
void MNVIC_voidSetInterruptPriority(NVIC_PriorityConfig_t* Copy_PuddtPriorityConfig);


/******************************************************************************************/
/*------------------------------------- Macros -------------------------------------------*/
/******************************************************************************************/

#define DISABLE					0u
#define ENABLE					1u


#endif /* MNVIC_INTERFACE_H */
