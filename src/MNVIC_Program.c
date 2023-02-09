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
#include "MNVIC_Private.h"
#include "MNVIC_Config.h"
#include "MNVIC_Interface.h"


/******************************************************************************************/
/*-------------------------------- Function Implementation -------------------------------*/
/******************************************************************************************/

/******************************************************************************************/
/*							01- MNVIC_voidEnableInterrupt                                 */
/*----------------------------------------------------------------------------------------*/
/* @function 		MNVIC_voidEnableInterrupt											  */
/* @brief 			This function is used to enable interrupt							  */
/* @param[in]		Copy_u8IntNum : Interrupt number						      	  	  */
/******************************************************************************************/
void MNVIC_voidEnableInterrupt(u8 Copy_u8IntNum)
{
	MNVIC->ISER[Copy_u8IntNum / 32] = (1 << (Copy_u8IntNum % 32));
}


/******************************************************************************************/
/*							02- MNVIC_voidDisableInterrupt                                */
/*----------------------------------------------------------------------------------------*/
/* @function 		MNVIC_voidDisableInterrupt											  */
/* @brief 			This function is used to disable interrupt							  */
/* @param[in]		Copy_u8IntNum : Interrupt number						      	  	  */
/******************************************************************************************/
void MNVIC_voidDisableInterrupt(u8 Copy_u8IntNum)
{
	MNVIC->ICER[Copy_u8IntNum / 32] = (1 << (Copy_u8IntNum % 32));
}


/******************************************************************************************/
/*							03- MNVIC_voidEnableInterruptPending                          */
/*----------------------------------------------------------------------------------------*/
/* @function 		MNVIC_voidEnableInterruptPending								  	  */
/* @brief 			This function is used to enable interrupt pending  				  	  */
/* @param[in]		Copy_u8IntNum : Interrupt number						      	  	  */
/******************************************************************************************/
void MNVIC_voidEnableInterruptPending(u8 Copy_u8IntNum)
{
		MNVIC->ISPR[Copy_u8IntNum / 32] = (1 << (Copy_u8IntNum % 32));
}


/******************************************************************************************/
/*							04- MNVIC_voidDisableInterruptPending                         */
/*----------------------------------------------------------------------------------------*/
/* @function 		MNVIC_voidDisableInterruptPending								  	  */
/* @brief 			This function is used to disable interrupt pending 				  	  */
/* @param[in]		Copy_u8IntNum : Interrupt number						      	  	  */
/******************************************************************************************/
void MNVIC_voidDisableInterruptPending(u8 Copy_u8IntNum)
{
	MNVIC->ICPR[Copy_u8IntNum / 32] = (1 << (Copy_u8IntNum % 32));
}


/******************************************************************************************/
/*							05- MNVIC_u8InterruptActive                                   */
/*----------------------------------------------------------------------------------------*/
/* @function 	MNVIC_u8InterruptActive												  	  */
/* @brief 		This function is used to do hardware delay		    				  	  */
/* @param[in]	Copy_u8IntNum : Interrupt number						        	  	  */
/* @param[out]	u8 : Return interrupt flag								        	  	  */
/******************************************************************************************/
u8 MNVIC_u8InterruptActive(u8 Copy_u8IntNum)
{
	u8 Local_u8IntStatus;
	Local_u8IntStatus = GET_BIT(MNVIC->ISPR[Copy_u8IntNum/32], Copy_u8IntNum);
	return Local_u8IntStatus;
}


/******************************************************************************************/
/*							06- MNVIC_voidInitInterruptGroup                              */
/*----------------------------------------------------------------------------------------*/
/* @function 	MNVIC_voidInitInterruptGroup										  	  */
/* @brief 		This function is used to do hardware delay		    				  	  */
/* @param[in]	Copy_uddtGroupMode : Interrupt grouping configuration					  */
/* 			[ NVIC_GROUP_MODE_G16S0, NVIC_GROUP_MODE_G8S2, NVIC_GROUP_MODE_G4S4			  */
/* 			  NVIC_GROUP_MODE_G4S4 , NVIC_GROUP_MODE_G2S8, NVIC_GROUP_MODE_G0S16 ]		  */
/******************************************************************************************/
void MNVIC_voidInitInterruptGroup(NVIC_GroupMode_t Copy_uddtGroupMode)
{
	SCB_AIRCR = (VECTKEY | (Copy_uddtGroupMode << 8));
}


/******************************************************************************************/
/*							07- MNVIC_voidSetInterruptPriority                            */
/*----------------------------------------------------------------------------------------*/
/* @function 	MNVIC_voidSetInterruptPriority										  	  */
/* @brief 		This function is used to set the callback function for ISR			  	  */
/* @param[in]	Copy_PuddtPriorityConfig : Structure contain the interrupt configuration  */
/******************************************************************************************/
void MNVIC_voidSetInterruptPriority(NVIC_PriorityConfig_t* Copy_PuddtPriorityConfig)
{
	u8 Local_u8PrioValue = 0;
	switch(Copy_PuddtPriorityConfig->Copy_uddtGroupMode)
	{
	case NVIC_GROUP_MODE_G16S0 : Local_u8PrioValue =  Copy_PuddtPriorityConfig->Copy_GroupPriority; break;
	case NVIC_GROUP_MODE_G8S2  : Local_u8PrioValue = (Copy_PuddtPriorityConfig->Copy_GroupPriority << 1) | Copy_PuddtPriorityConfig->Copy_SubPriority; break;
	case NVIC_GROUP_MODE_G4S4  : Local_u8PrioValue = (Copy_PuddtPriorityConfig->Copy_GroupPriority << 2) | Copy_PuddtPriorityConfig->Copy_SubPriority; break;
	case NVIC_GROUP_MODE_G2S8  : Local_u8PrioValue = (Copy_PuddtPriorityConfig->Copy_GroupPriority << 3) | Copy_PuddtPriorityConfig->Copy_SubPriority; break;
	case NVIC_GROUP_MODE_G0S16 : Local_u8PrioValue =  Copy_PuddtPriorityConfig->Copy_SubPriority; break;
	}
	MNVIC->IPR[Copy_PuddtPriorityConfig->Copy_u8IntNum] = Local_u8PrioValue << 4;
}

