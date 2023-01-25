/******************************************************************************************/
/* Author 	       :	Kareem Elsayyad                                                   */
/* Version         :	V0.0.0                                                            */
/* Date	           :	18 / 1 / 20232                                                    */
/* Description     :	MRCC_Config.h -> RCC User Configurations			              */
/******************************************************************************************/
#ifndef MRCC_CONFIG_H
#define MRCC_CONFIG_H

/******************************************************************************************/
/*-------------------------------- Includes ----------------------------------------------*/
/******************************************************************************************/

/* Select Initial Clock Source
 * 		1) HSI_CLK
 * 		2) HSE_CLK
 * 		3) PLL_CLK
 */
#define MRCC_CLK_SRC		HSI_CLK


/* Select High Speed Clock (HSE) Type
 * 		1) HSE_MECH
 * 		2) HSE_RC
 */
#define HSE_TYP				HSE_MECH


/* Select The PLL Input Clock Source
 * 		1) PLL_HSE
 * 		2) PLL_HSI
 */
#define PLL_CLK_SRC			PLL_HSE


/* Enable/Disable The Clock Security System During Clock Initialisation
 * 		1) ENABLE
 * 		2) DISABLE
 */
#define CLK_SECURITY		DISABLE


#endif /* MRCC_CONFIG_H */

