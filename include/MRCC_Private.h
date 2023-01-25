/******************************************************************************************/
/* Author 	       :	Kareem Elsayyad                                                   */
/* Version         :	V0.0.0                                                            */
/* Date	           :	18 / 1 / 20232                                                    */
/* Description     :	MRCC_Private.h -> Register Definition Macros                      */
/******************************************************************************************/
#ifndef MRCC_PRIVATE_H
#define MRCC_PRIVATE_H

/******************************************************************************************/
/*------------------------------------- Macros -------------------------------------------*/
/******************************************************************************************/

#define MRCC_BASE_ADDRESS		0x40023800
/******************************************************************************************/
/*							    RCC Register Addresses                                    */
/******************************************************************************************/
#define MRCC_CR                 (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x00)))
#define MRCC_PLLCFGR            (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x04)))
#define MRCC_CFGR               (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x08)))
#define MRCC_CIR                (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x0C)))
#define MRCC_AHB1RSTR           (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x10)))
#define MRCC_AHB2RSTR           (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x14)))
#define MRCC_APB1RSTR           (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x20)))
#define MRCC_APB2RSTR           (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x24)))
#define MRCC_AHB1ENR            (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x30)))
#define MRCC_AHB2ENR            (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x34)))
#define MRCC_APB1ENR            (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x40)))
#define MRCC_APB2ENR            (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x44)))
#define MRCC_AHB1LPENR          (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x50)))
#define MRCC_AHB2LPENR          (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x54)))
#define MRCC_APB1LPENR          (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x60)))
#define MRCC_APB2LPENR          (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x64)))
#define MRCC_BDCR               (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x70)))
#define MRCC_CSR                (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x74)))
#define MRCC_SSCGR              (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x80)))
#define MRCC_PLLI2SCFGR			(*((volatile u32*)(MRCC_BASE_ADDRESS + 0x84)))
#define MRCC_DCKCFGR            (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x8C)))


/******************************************************************************************/
/*							RCC Control Register (RCC_CR)                                 */
/******************************************************************************************/
#define MRCC_CR_HSI_EN				   0u
#define MRCC_CR_HSI_RDY				   1u
#define MRCC_CR_HSI_TRIM_0			   3u
#define MRCC_CR_HSI_TRIM_1             4u
#define MRCC_CR_HSI_TRIM_2             5u
#define MRCC_CR_HSI_TRIM_3             6u
#define MRCC_CR_HSI_TRIM_4             7u
#define MRCC_CR_HSI_CAL_0              8u
#define MRCC_CR_HSI_CAL_1              9u
#define MRCC_CR_HSI_CAL_2              10u
#define MRCC_CR_HSI_CAL_3              11u
#define MRCC_CR_HSI_CAL_4              12u
#define MRCC_CR_HSI_CAL_5              13u
#define MRCC_CR_HSI_CAL_6              14u
#define MRCC_CR_HSI_CAL_7              15u
#define MRCC_CR_HSE_EN	               16u
#define MRCC_CR_HSE_RDY                17u
#define MRCC_CR_HSE_BYPASS             18u
#define MRCC_CR_EN_CSS                 19u
#define MRCC_CR_PLL_EN	               24u
#define MRCC_CR_PLL_RDY                25u
#define MRCC_CR_PLL_I2S_EN             26u
#define MRCC_CR_PLL_I2S_RDY            27u


/******************************************************************************************/
/*						   RCC Clock Configure Register (RCC_CFGR)                        */
/******************************************************************************************/
#define MRCC_CFGR_SW_0               0u
#define MRCC_CFGR_SW_1               1u
#define MRCC_CFGR_SWS_0              2u
#define MRCC_CFGR_SWS_1              3u
#define MRCC_CFGR_HPRE_0             4u
#define MRCC_CFGR_HPRE_1             5u
#define MRCC_CFGR_HPRE_2             6u
#define MRCC_CFGR_HPRE_3             7u
#define MRCC_CFGR_PPRE1_0            10u
#define MRCC_CFGR_PPRE1_1            11u
#define MRCC_CFGR_PPRE1_2            12u
#define MRCC_CFGR_PPRE2_0            13u
#define MRCC_CFGR_PPRE2_1            14u
#define MRCC_CFGR_PPRE2_2            15u
#define MRCC_CFGR_RTCPRE_0           16u
#define MRCC_CFGR_RTCPRE_1           17u
#define MRCC_CFGR_RTCPRE_2           18u
#define MRCC_CFGR_RTCPRE_3           19u
#define MRCC_CFGR_RTCPRE_4           20u
#define MRCC_CFGR_MCO1_0             21u
#define MRCC_CFGR_MCO1_1             22u
#define MRCC_CFGR_I2SSCR             23u
#define MRCC_CFGR_MCO1PRE_0			 24u
#define MRCC_CFGR_MCO1PRE_1          25u
#define MRCC_CFGR_MCO1PRE_2          26u
#define MRCC_CFGR_MCO2PRE_0          27u
#define MRCC_CFGR_MCO2PRE_1          28u
#define MRCC_CFGR_MCO2PRE_2          29u
#define MRCC_CFGR_MCO2_0             30u
#define MRCC_CFGR_MCO2_1             31u


/******************************************************************************************/
/*				   RCC  PLL Clock Configure Register (RCC_PLLCFGR)                        */
/******************************************************************************************/
#define MRCC_PLLCFGR_PLLM_0			0u
#define MRCC_PLLCFGR_PLLM_1         1u
#define MRCC_PLLCFGR_PLLM_2         2u
#define MRCC_PLLCFGR_PLLM_3         3u
#define MRCC_PLLCFGR_PLLM_4         4u
#define MRCC_PLLCFGR_PLLM_5         5u
#define MRCC_PLLCFGR_PLLN_0         6u
#define MRCC_PLLCFGR_PLLN_1         7u
#define MRCC_PLLCFGR_PLLN_2         8u
#define MRCC_PLLCFGR_PLLN_3         9u
#define MRCC_PLLCFGR_PLLN_4         10u
#define MRCC_PLLCFGR_PLLN_5         11u
#define MRCC_PLLCFGR_PLLN_6         12u
#define MRCC_PLLCFGR_PLLN_7         13u
#define MRCC_PLLCFGR_PLLN_8         14u
#define MRCC_PLLCFGR_PLLP_0         16u
#define MRCC_PLLCFGR_PLLP_1         17u
#define MRCC_PLLCFGR_PLLSRC         22u
#define MRCC_PLLCFGR_PLLQ_0         24u
#define MRCC_PLLCFGR_PLLQ_1         25u
#define MRCC_PLLCFGR_PLLQ_2         26u
#define MRCC_PLLCFGR_PLLQ_3         27u


/******************************************************************************************/
/*						                User Configuration                                */
/******************************************************************************************/
#define HSE_CLK		0u
#define HSI_CLK		1u
#define PLL_CLK		2u

#define HSE_MECH	0u
#define HSE_RC		1u

#define PLL_HSE		0u
#define PLL_HSI		1u

#define DISABLE		0u
#define ENABLE		1u

//TODO
//#define HSI_84MHZ	0x12421508
//#define HSI_42MHZ
#endif /* MRCC_PRIVATE_H */
