/*******************************************************************************
* File Name: Seg_3.h  
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

#if !defined(CY_PINS_Seg_3_ALIASES_H) /* Pins Seg_3_ALIASES_H */
#define CY_PINS_Seg_3_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define Seg_3_0			(Seg_3__0__PC)
#define Seg_3_0_INTR	((uint16)((uint16)0x0001u << Seg_3__0__SHIFT))

#define Seg_3_1			(Seg_3__1__PC)
#define Seg_3_1_INTR	((uint16)((uint16)0x0001u << Seg_3__1__SHIFT))

#define Seg_3_2			(Seg_3__2__PC)
#define Seg_3_2_INTR	((uint16)((uint16)0x0001u << Seg_3__2__SHIFT))

#define Seg_3_3			(Seg_3__3__PC)
#define Seg_3_3_INTR	((uint16)((uint16)0x0001u << Seg_3__3__SHIFT))

#define Seg_3_4			(Seg_3__4__PC)
#define Seg_3_4_INTR	((uint16)((uint16)0x0001u << Seg_3__4__SHIFT))

#define Seg_3_5			(Seg_3__5__PC)
#define Seg_3_5_INTR	((uint16)((uint16)0x0001u << Seg_3__5__SHIFT))

#define Seg_3_6			(Seg_3__6__PC)
#define Seg_3_6_INTR	((uint16)((uint16)0x0001u << Seg_3__6__SHIFT))

#define Seg_3_7			(Seg_3__7__PC)
#define Seg_3_7_INTR	((uint16)((uint16)0x0001u << Seg_3__7__SHIFT))

#define Seg_3_INTR_ALL	 ((uint16)(Seg_3_0_INTR| Seg_3_1_INTR| Seg_3_2_INTR| Seg_3_3_INTR| Seg_3_4_INTR| Seg_3_5_INTR| Seg_3_6_INTR| Seg_3_7_INTR))

#endif /* End Pins Seg_3_ALIASES_H */


/* [] END OF FILE */
