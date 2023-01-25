/******************************************************************************************/
/* Author 	       :	Kareem Elsayyad                                                   */
/* Version         :	V0.0.0                                                            */
/* Date	           :	18 / 1 / 20232                                                    */
/* Description     :	MRCC_Interface.h -> Functions Implementation                      */
/* Module Features :																	  */
/*				01- MRCC_voidInitSystemClock											  */
/*				02- MRCC_voidDisablePeripheralSystemClock								  */
/*				03- MRCC_voidEnablePeripheralSystemClock								  */
/*				04- MRCC_voidChangeSystemClock   										  */
/******************************************************************************************/


/******************************************************************************************/
/*-------------------------------- Includes ----------------------------------------------*/
/******************************************************************************************/

/******************************************************************************************/
/*                            Standard Types LIB                                          */
/******************************************************************************************/

#include "LBIT_MATH.h"
#include "LERROR_STATES.h"
#include "LSTD_TYPES.h"

/******************************************************************************************/
/*                                Own Headers                                             */
/******************************************************************************************/
#include "MRCC_Private.h"
#include "MRCC_Config.h"
#include "MRCC_Interface.h"

/******************************************************************************************/
/*-------------------------------- Function Implementation -------------------------------*/
/******************************************************************************************/

/******************************************************************************************/
/*							01- MRCC_voidInitSystemClock                                  */
/*----------------------------------------------------------------------------------------*/
/* @function 		MRCC_void_InitSystemClock											  */
/* @brief 			This function is used to initialise the system clock				  */
/* @param			void																  */
/******************************************************************************************/
void MRCC_voidInitSystemClock(void)
{
/* Check If Clock Security System Is Enabled Or Disabled */
#if CLK_SECURITY == ENABLE
	SET_BIT(MRCC_CR, MRCC_CR_EN_CSS);
#elif CLK_SECURITY == DISABLE
	CLR_BIT(MRCC_CR, MRCC_CR_EN_CSS);
#else
	/* ERROR */
#endif

/* Check Which Clock Source To Enable */
#if MRCC_CLK_SRC == HSI_CLK
	/* 1- Enable HSI */
	SET_BIT(MRCC_CR, MRCC_CR_HSI_EN);
	/* 2- Wait Till HSI Ready */
	while(GET_BIT(MRCC_CR, MRCC_CR_HSI_RDY) == 0);
	/* 3- Switch To HSI */
	CLR_BIT(MRCC_CFGR, MRCC_CFGR_SW_0);
	CLR_BIT(MRCC_CFGR, MRCC_CFGR_SW_1);
#elif MRCC_CLK_SRC == HSE_CLK
	/* 1- Enable HSE */
	SET_BIT(MRCC_CR, MRCC_CR_HSE_EN);
	/* 2- Wait Till HSE Ready */
	while(GET_BIT(MRCC_CR, MRCC_CR_HSE_RDY) == 0);
	/* 3- Enable or Disable Bypass */
	#if HSE_TYP == HSE_MECH
		/* Disable Bypass */
		CLR_BIT(MRCC_CR, MRCC_CR_HSE_BYPASS);
	#elif == HSE_RC
		/* Enable Bypass */
		SET_BIT(MRCC_CR, MRCC_HSE_BYPASS)
	#else
		/* ERROR */
	#endif
	/* 4- Switch To HSE */
	SET_BIT(MRCC_CFGR, MRCC_CFGR_SW_0);
	CLR_BIT(MRCC_CFGR, MRCC_CFGR_SW_1);
#elif MRCC_CLK_SRC == PLL_CLK
	/* 1- Disable PPL */
	CLR_BIT(MRCC_CR, MRCC_CR_PLL_EN);
	/* 2- Select PLL Clock Source And Configure Speed to Be 84 MHz */
	#if PLL_CLK_SRC == PLL_HSE
		SET_BIT(MRCC_PLLCFGR, MRCC_PLLCFGR_PLLSRC);
		/* 1) M -> Divide by 25 */
		SET_BIT(MRCC_PLLCFGR, MRCC_PLLCFGR_PLLM_0);
		CLR_BIT(MRCC_PLLCFGR, MRCC_PLLCFGR_PLLM_1);
		CLR_BIT(MRCC_PLLCFGR, MRCC_PLLCFGR_PLLM_2);
		SET_BIT(MRCC_PLLCFGR, MRCC_PLLCFGR_PLLM_3);
		SET_BIT(MRCC_PLLCFGR, MRCC_PLLCFGR_PLLM_4);
		CLR_BIT(MRCC_PLLCFGR, MRCC_PLLCFGR_PLLM_5);
		/* 2) N -> Multiply by 168 */
		CLR_BIT(MRCC_PLLCFGR, MRCC_PLLCFGR_PLLN_0);
		CLR_BIT(MRCC_PLLCFGR, MRCC_PLLCFGR_PLLN_1);
		CLR_BIT(MRCC_PLLCFGR, MRCC_PLLCFGR_PLLN_2);
		SET_BIT(MRCC_PLLCFGR, MRCC_PLLCFGR_PLLN_3);
		CLR_BIT(MRCC_PLLCFGR, MRCC_PLLCFGR_PLLN_4);
		SET_BIT(MRCC_PLLCFGR, MRCC_PLLCFGR_PLLN_5);
		CLR_BIT(MRCC_PLLCFGR, MRCC_PLLCFGR_PLLN_6);
		SET_BIT(MRCC_PLLCFGR, MRCC_PLLCFGR_PLLN_7);
		CLR_BIT(MRCC_PLLCFGR, MRCC_PLLCFGR_PLLN_8);
		/* 3) P -> Divide by 2 */
		CLR_BIT(MRCC_PLLCFGR, MRCC_PLLCFGR_PLLP_0);
		SET_BIT(MRCC_PLLCFGR, MRCC_PLLCFGR_PLLP_1);
		/* 4) Q -> Divide by 4 */
		CLR_BIT(MRCC_PLLCFGR, MRCC_PLLCFGR_PLLQ_0);
		CLR_BIT(MRCC_PLLCFGR, MRCC_PLLCFGR_PLLQ_1);
		SET_BIT(MRCC_PLLCFGR, MRCC_PLLCFGR_PLLQ_2);
		SET_BIT(MRCC_PLLCFGR, MRCC_PLLCFGR_PLLQ_3);
	#elif PLL_CLK_SRC == PLL_HSI
		CLR_BIT(MRCC_PLLCFGR, MRCC_PLLCFGR_PLLSRC);
		/* 1) M -> Divide by 8 */
		CLR_BIT(MRCC_PLLCFGR, MRCC_PLLCFGR_PLLM_0);
		CLR_BIT(MRCC_PLLCFGR, MRCC_PLLCFGR_PLLM_1);
		CLR_BIT(MRCC_PLLCFGR, MRCC_PLLCFGR_PLLM_2);
		SET_BIT(MRCC_PLLCFGR, MRCC_PLLCFGR_PLLM_3);
		CLR_BIT(MRCC_PLLCFGR, MRCC_PLLCFGR_PLLM_4);
		CLR_BIT(MRCC_PLLCFGR, MRCC_PLLCFGR_PLLM_5);
		/* 2) N -> Multiply by 84 */
		CLR_BIT(MRCC_PLLCFGR, MRCC_PLLCFGR_PLLN_0);
		CLR_BIT(MRCC_PLLCFGR, MRCC_PLLCFGR_PLLN_1);
		SET_BIT(MRCC_PLLCFGR, MRCC_PLLCFGR_PLLN_2);
		CLR_BIT(MRCC_PLLCFGR, MRCC_PLLCFGR_PLLN_3);
		SET_BIT(MRCC_PLLCFGR, MRCC_PLLCFGR_PLLN_4);
		CLR_BIT(MRCC_PLLCFGR, MRCC_PLLCFGR_PLLN_5);
		SET_BIT(MRCC_PLLCFGR, MRCC_PLLCFGR_PLLN_6);
		CLR_BIT(MRCC_PLLCFGR, MRCC_PLLCFGR_PLLN_7);
		CLR_BIT(MRCC_PLLCFGR, MRCC_PLLCFGR_PLLN_8);
		/* 3) P -> Divide by 2 */
		CLR_BIT(MRCC_PLLCFGR, MRCC_PLLCFGR_PLLP_0);
		SET_BIT(MRCC_PLLCFGR, MRCC_PLLCFGR_PLLP_1);
		/* 4) Q -> Divide by 4 */
		CLR_BIT(MRCC_PLLCFGR, MRCC_PLLCFGR_PLLQ_0);
		CLR_BIT(MRCC_PLLCFGR, MRCC_PLLCFGR_PLLQ_1);
		SET_BIT(MRCC_PLLCFGR, MRCC_PLLCFGR_PLLQ_2);
		CLR_BIT(MRCC_PLLCFGR, MRCC_PLLCFGR_PLLN_3);
	#else
		/* ERROR */
	#endif
	/* 3- Enable PLL */
	SET_BIT(MRCC_CR, MRCC_CR_PLL_EN);
	/* 4- Wait Till PLL is Ready */
	while(GET_BIT(MRCC_CR, MRCC_CR_PLL_RDY) == 0);
	/* 5- Switch To PLL */
	CLR_BIT(MRCC_CFGR,MRCC_CFGR_SW_0);
	SET_BIT(MRCC_CFGR,MRCC_CFGR_SW_1);
#else
	/* ERROR */
#endif
}


/******************************************************************************************/
/*							02- MRCC_voidDisablePeripheralClock                           */
/*----------------------------------------------------------------------------------------*/
/* @function 	MRCC_voidDisablePeripheralClock  									  	  */
/* @brief 		This function is used to disable peripheral clock    				  	  */
/* @param[in]	Copy_uddtBusName : Bus which the peripheral is connected to      	  	  */
/*		[AHB1 - AHB2 - APB1 - APB2]											  			  */
/* @param[in]	Copy_u8Peripheral														  */
/******************************************************************************************/
void MRCC_voidDisablePeripheralClock(BusName_t Copy_uddtBusName, u8 Copy_u8Peripheral)
{
	switch(Copy_uddtBusName)
	{
	case AHB1:	CLR_BIT(MRCC_AHB1ENR, Copy_u8Peripheral);	break;
	case AHB2:	CLR_BIT(MRCC_AHB2ENR, Copy_u8Peripheral);	break;
	case APB1:	CLR_BIT(MRCC_APB1ENR, Copy_u8Peripheral);	break;
	case APB2:	CLR_BIT(MRCC_APB2ENR, Copy_u8Peripheral);	break;
	default:	/* ERROR */								;	break;
	}
}


/******************************************************************************************/
/*							03- MRCC_voidDisablePeripheralClock                           */
/*----------------------------------------------------------------------------------------*/
/* @function 	MRCC_voidEnablePeripheralClock  									  	  */
/* @brief 		This function is used to enable peripheral clock    				  	  */
/* @param[in]	Copy_uddtBusName : Bus which the peripheral is connected to      	  	  */
/*		[AHB1 - AHB2 - APB1 - APB2]											  			  */
/* @param[in]	Copy_u8Peripheral														  */
/******************************************************************************************/
void MRCC_voidEnablePeripheralClock(BusName_t Copy_uddtBusName, u8 Copy_u8Peripheral)
{
	switch(Copy_uddtBusName)
	{
	case AHB1:	SET_BIT(MRCC_AHB1ENR, Copy_u8Peripheral);	break;
	case AHB2:	SET_BIT(MRCC_AHB2ENR, Copy_u8Peripheral);	break;
	case APB1:	SET_BIT(MRCC_APB1ENR, Copy_u8Peripheral);	break;
	case APB2:	SET_BIT(MRCC_APB2ENR, Copy_u8Peripheral);	break;
	default:	/* ERROR */								;	break;
	}
}


/******************************************************************************************/
/*							04- MRCC_voidChangeSystemClock                                */
/*----------------------------------------------------------------------------------------*/
/* @function 	MRCC_voidChangeSystemClock											  	  */
/* @brief 		This function is used to change the system clock    				  	  */
/* @param[in]	Copy_uddtSystemClock : The system clock that is needed	        	  	  */
/*		[HSE - HSI - PLL]	      											  			  */
/******************************************************************************************/
void MRCC_voidChangeSystemClock(SystemClock_t Copy_uddtSystemClock)
{
	//TODO
}
