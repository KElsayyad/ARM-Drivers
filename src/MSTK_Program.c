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
#include "MSTK_Private.h"
#include "MSTK_Config.h"
#include "MSTK_Interface.h"


/******************************************************************************************/
/*-------------------------------- Function Implementation -------------------------------*/
/******************************************************************************************/
static void (*MSTK_CallBack)(void);

//called by hardware if interrupt happen
void SysTick_Handler(void)
{
	MSTK_CallBack();
}


/******************************************************************************************/
/*							01- MSTK_voidInit                                             */
/*----------------------------------------------------------------------------------------*/
/* @function 		MRCC_void_InitSystemClock											  */
/* @brief 			This function is used to initialise the system clock				  */
/* @param			void																  */
/******************************************************************************************/
void MSTK_voidInit(void)
{
	/* Enable Systick Int - Clock = AHB/8 - Disable Systick */
	SET_BIT(MSTK->CTRL, MSTK_CTRL_TICK_INT);
	CLR_BIT(MSTK->CTRL, MSTK_CTRL_CLK_SOURCE);
	CLR_BIT(MSTK->CTRL, MSTK_CTRL_ENABLE);
}


/******************************************************************************************/
/*							02- MSTK_voidStart                                            */
/*----------------------------------------------------------------------------------------*/
/* @function 	MRCC_voidDisablePeripheralClock  									  	  */
/* @brief 		This function is used to disable peripheral clock    				  	  */
/* @param[in]	Copy_uddtBusName : Bus which the peripheral is connected to      	  	  */
/*		[AHB1 - AHB2 - APB1 - APB2]											  			  */
/* @param[in]	Copy_u8Peripheral														  */
/******************************************************************************************/
void MSTK_voidStart(u32 Copy_u32PreloadValue)
{
	/* Load Value - Write on Val Reg - Enable Systick */
	// FCPU = 16MHz HSI = AHB
	// F_Timer = 16/8 = 2MHz -> Tick Time = 0.5 Us
	MSTK->LOAD = Copy_u32PreloadValue;
	MSTK->VAL = 0;
	SET_BIT(MSTK->CTRL, MSTK_CTRL_ENABLE);
}


/******************************************************************************************/
/*							03- MSTK_u8ReadCountFlag                                      */
/*----------------------------------------------------------------------------------------*/
/* @function 	MRCC_voidEnablePeripheralClock  									  	  */
/* @brief 		This function is used to enable peripheral clock    				  	  */
/* @param[in]	Copy_uddtBusName : Bus which the peripheral is connected to      	  	  */
/*		[AHB1 - AHB2 - APB1 - APB2]											  			  */
/* @param[in]	Copy_u8Peripheral														  */
/******************************************************************************************/
u8 MSTK_u8ReadCountFlag(void)
{
	/* Return Count Flag */
	return (GET_BIT(MSTK->CTRL, MSTK_CTRL_COUNT_FLAG));
}


/******************************************************************************************/
/*							04- MSTK_voidSetIntStatus                                     */
/*----------------------------------------------------------------------------------------*/
/* @function 	MRCC_voidChangeSystemClock											  	  */
/* @brief 		This function is used to change the system clock    				  	  */
/* @param[in]	Copy_uddtSystemClock : The system clock that is needed	        	  	  */
/*		[HSE - HSI - PLL]	      											  			  */
/******************************************************************************************/
void MSTK_voidSetIntStatus(u8 Copy_u8IntStatus)
{
	/* Clear Bit of Int - Set Bit with The IntStatus*/
	if (Copy_u8IntStatus == DISABLE)
	{
		CLR_BIT(MSTK->CTRL, MSTK_CTRL_TICK_INT);
	}
	else if (Copy_u8IntStatus == ENABLE)
	{
		SET_BIT(MSTK->CTRL, MSTK_CTRL_TICK_INT);
	}
}


/******************************************************************************************/
/*							04- MSTK_voidDelayMs                                          */
/*----------------------------------------------------------------------------------------*/
/* @function 	MRCC_voidChangeSystemClock											  	  */
/* @brief 		This function is used to change the system clock    				  	  */
/* @param[in]	Copy_uddtSystemClock : The system clock that is needed	        	  	  */
/*		[HSE - HSI - PLL]	      											  			  */
/******************************************************************************************/
void MSTK_voidDelayMs(u32 Copy_u32Time)
{
	//1- Init systick
	//2- disable int
	MSTK_voidSetIntStatus(DISABLE);
	//3- start systick(time) * 2000 to change from us to ms and each tick is 0.5 us
	MSTK_voidStart(Copy_u32Time * 2000);
	//4- wait flag polling
	while(MSTK_u8ReadCountFlag() == 0);
}


/******************************************************************************************/
/*							04- MSTK_voidDelayUs                                          */
/*----------------------------------------------------------------------------------------*/
/* @function 	MRCC_voidChangeSystemClock											  	  */
/* @brief 		This function is used to change the system clock    				  	  */
/* @param[in]	Copy_uddtSystemClock : The system clock that is needed	        	  	  */
/*		[HSE - HSI - PLL]	      											  			  */
/******************************************************************************************/
void MSTK_voidDelayUs(u32 Copy_u32Time)
{
	//1- Init systick
	//2- disable int
	MSTK_voidSetIntStatus(DISABLE);
	//3- start systick(time) * 2000 to change from us to ms and each tick is 0.5 us
	MSTK_voidStart(Copy_u32Time * 2);
	//4- wait flag polling
	while(MSTK_u8ReadCountFlag() == 0);
}


/******************************************************************************************/
/*							05- MSTK_voidSetCallBack                                     */
/*----------------------------------------------------------------------------------------*/
/* @function 	MRCC_voidChangeSystemClock											  	  */
/* @brief 		This function is used to change the system clock    				  	  */
/* @param[in]	Copy_uddtSystemClock : The system clock that is needed	        	  	  */
/*		[HSE - HSI - PLL]	      											  			  */
/******************************************************************************************/
void MSTK_voidSetCallBack(void (*PFun) (void))
{
	//assign the function that is passed to the MSTK_Callback global pointer
	MSTK_CallBack = PFun;
}

