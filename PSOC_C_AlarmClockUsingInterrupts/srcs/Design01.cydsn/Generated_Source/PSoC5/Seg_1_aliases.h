/*******************************************************************************
* File Name: Seg_1.h  
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

#if !defined(CY_PINS_Seg_1_ALIASES_H) /* Pins Seg_1_ALIASES_H */
#define CY_PINS_Seg_1_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define Seg_1_0			(Seg_1__0__PC)
#define Seg_1_0_INTR	((uint16)((uint16)0x0001u << Seg_1__0__SHIFT))

#define Seg_1_1			(Seg_1__1__PC)
#define Seg_1_1_INTR	((uint16)((uint16)0x0001u << Seg_1__1__SHIFT))

#define Seg_1_2			(Seg_1__2__PC)
#define Seg_1_2_INTR	((uint16)((uint16)0x0001u << Seg_1__2__SHIFT))

#define Seg_1_3			(Seg_1__3__PC)
#define Seg_1_3_INTR	((uint16)((uint16)0x0001u << Seg_1__3__SHIFT))

#define Seg_1_4			(Seg_1__4__PC)
#define Seg_1_4_INTR	((uint16)((uint16)0x0001u << Seg_1__4__SHIFT))

#define Seg_1_5			(Seg_1__5__PC)
#define Seg_1_5_INTR	((uint16)((uint16)0x0001u << Seg_1__5__SHIFT))

#define Seg_1_6			(Seg_1__6__PC)
#define Seg_1_6_INTR	((uint16)((uint16)0x0001u << Seg_1__6__SHIFT))

#define Seg_1_7			(Seg_1__7__PC)
#define Seg_1_7_INTR	((uint16)((uint16)0x0001u << Seg_1__7__SHIFT))

#define Seg_1_INTR_ALL	 ((uint16)(Seg_1_0_INTR| Seg_1_1_INTR| Seg_1_2_INTR| Seg_1_3_INTR| Seg_1_4_INTR| Seg_1_5_INTR| Seg_1_6_INTR| Seg_1_7_INTR))

#endif /* End Pins Seg_1_ALIASES_H */


/* [] END OF FILE */
