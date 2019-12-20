/*******************************************************************************
* File Name: Com_3.h  
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

#if !defined(CY_PINS_Com_3_ALIASES_H) /* Pins Com_3_ALIASES_H */
#define CY_PINS_Com_3_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define Com_3_0			(Com_3__0__PC)
#define Com_3_0_INTR	((uint16)((uint16)0x0001u << Com_3__0__SHIFT))

#define Com_3_1			(Com_3__1__PC)
#define Com_3_1_INTR	((uint16)((uint16)0x0001u << Com_3__1__SHIFT))

#define Com_3_2			(Com_3__2__PC)
#define Com_3_2_INTR	((uint16)((uint16)0x0001u << Com_3__2__SHIFT))

#define Com_3_3			(Com_3__3__PC)
#define Com_3_3_INTR	((uint16)((uint16)0x0001u << Com_3__3__SHIFT))

#define Com_3_INTR_ALL	 ((uint16)(Com_3_0_INTR| Com_3_1_INTR| Com_3_2_INTR| Com_3_3_INTR))

#endif /* End Pins Com_3_ALIASES_H */


/* [] END OF FILE */
