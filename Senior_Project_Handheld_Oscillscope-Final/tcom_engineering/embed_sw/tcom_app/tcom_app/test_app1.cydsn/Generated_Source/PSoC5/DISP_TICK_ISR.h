/*******************************************************************************
* File Name: DISP_TICK_ISR.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_DISP_TICK_ISR_H)
#define CY_ISR_DISP_TICK_ISR_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void DISP_TICK_ISR_Start(void);
void DISP_TICK_ISR_StartEx(cyisraddress address);
void DISP_TICK_ISR_Stop(void);

CY_ISR_PROTO(DISP_TICK_ISR_Interrupt);

void DISP_TICK_ISR_SetVector(cyisraddress address);
cyisraddress DISP_TICK_ISR_GetVector(void);

void DISP_TICK_ISR_SetPriority(uint8 priority);
uint8 DISP_TICK_ISR_GetPriority(void);

void DISP_TICK_ISR_Enable(void);
uint8 DISP_TICK_ISR_GetState(void);
void DISP_TICK_ISR_Disable(void);

void DISP_TICK_ISR_SetPending(void);
void DISP_TICK_ISR_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the DISP_TICK_ISR ISR. */
#define DISP_TICK_ISR_INTC_VECTOR            ((reg32 *) DISP_TICK_ISR__INTC_VECT)

/* Address of the DISP_TICK_ISR ISR priority. */
#define DISP_TICK_ISR_INTC_PRIOR             ((reg8 *) DISP_TICK_ISR__INTC_PRIOR_REG)

/* Priority of the DISP_TICK_ISR interrupt. */
#define DISP_TICK_ISR_INTC_PRIOR_NUMBER      DISP_TICK_ISR__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable DISP_TICK_ISR interrupt. */
#define DISP_TICK_ISR_INTC_SET_EN            ((reg32 *) DISP_TICK_ISR__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the DISP_TICK_ISR interrupt. */
#define DISP_TICK_ISR_INTC_CLR_EN            ((reg32 *) DISP_TICK_ISR__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the DISP_TICK_ISR interrupt state to pending. */
#define DISP_TICK_ISR_INTC_SET_PD            ((reg32 *) DISP_TICK_ISR__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the DISP_TICK_ISR interrupt. */
#define DISP_TICK_ISR_INTC_CLR_PD            ((reg32 *) DISP_TICK_ISR__INTC_CLR_PD_REG)


#endif /* CY_ISR_DISP_TICK_ISR_H */


/* [] END OF FILE */
