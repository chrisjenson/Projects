/*******************************************************************************
* File Name: Pin_10.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Pin_10_ALIASES_H) /* Pins Pin_10_ALIASES_H */
#define CY_PINS_Pin_10_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define Pin_10_0			(Pin_10__0__PC)
#define Pin_10_0_INTR	((uint16)((uint16)0x0001u << Pin_10__0__SHIFT))

#define Pin_10_1			(Pin_10__1__PC)
#define Pin_10_1_INTR	((uint16)((uint16)0x0001u << Pin_10__1__SHIFT))

#define Pin_10_2			(Pin_10__2__PC)
#define Pin_10_2_INTR	((uint16)((uint16)0x0001u << Pin_10__2__SHIFT))

#define Pin_10_3			(Pin_10__3__PC)
#define Pin_10_3_INTR	((uint16)((uint16)0x0001u << Pin_10__3__SHIFT))

#define Pin_10_4			(Pin_10__4__PC)
#define Pin_10_4_INTR	((uint16)((uint16)0x0001u << Pin_10__4__SHIFT))

#define Pin_10_5			(Pin_10__5__PC)
#define Pin_10_5_INTR	((uint16)((uint16)0x0001u << Pin_10__5__SHIFT))

#define Pin_10_6			(Pin_10__6__PC)
#define Pin_10_6_INTR	((uint16)((uint16)0x0001u << Pin_10__6__SHIFT))

#define Pin_10_7			(Pin_10__7__PC)
#define Pin_10_7_INTR	((uint16)((uint16)0x0001u << Pin_10__7__SHIFT))

#define Pin_10_INTR_ALL	 ((uint16)(Pin_10_0_INTR| Pin_10_1_INTR| Pin_10_2_INTR| Pin_10_3_INTR| Pin_10_4_INTR| Pin_10_5_INTR| Pin_10_6_INTR| Pin_10_7_INTR))

#endif /* End Pins Pin_10_ALIASES_H */


/* [] END OF FILE */
