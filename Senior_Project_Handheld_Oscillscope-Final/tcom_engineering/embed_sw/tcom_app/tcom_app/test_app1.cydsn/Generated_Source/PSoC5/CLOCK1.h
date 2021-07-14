/*******************************************************************************
* File Name: CLOCK1.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_CLOCK1_H)
#define CY_CLOCK_CLOCK1_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void CLOCK1_Start(void) ;
void CLOCK1_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void CLOCK1_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void CLOCK1_StandbyPower(uint8 state) ;
void CLOCK1_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 CLOCK1_GetDividerRegister(void) ;
void CLOCK1_SetModeRegister(uint8 modeBitMask) ;
void CLOCK1_ClearModeRegister(uint8 modeBitMask) ;
uint8 CLOCK1_GetModeRegister(void) ;
void CLOCK1_SetSourceRegister(uint8 clkSource) ;
uint8 CLOCK1_GetSourceRegister(void) ;
#if defined(CLOCK1__CFG3)
void CLOCK1_SetPhaseRegister(uint8 clkPhase) ;
uint8 CLOCK1_GetPhaseRegister(void) ;
#endif /* defined(CLOCK1__CFG3) */

#define CLOCK1_Enable()                       CLOCK1_Start()
#define CLOCK1_Disable()                      CLOCK1_Stop()
#define CLOCK1_SetDivider(clkDivider)         CLOCK1_SetDividerRegister(clkDivider, 1u)
#define CLOCK1_SetDividerValue(clkDivider)    CLOCK1_SetDividerRegister((clkDivider) - 1u, 1u)
#define CLOCK1_SetMode(clkMode)               CLOCK1_SetModeRegister(clkMode)
#define CLOCK1_SetSource(clkSource)           CLOCK1_SetSourceRegister(clkSource)
#if defined(CLOCK1__CFG3)
#define CLOCK1_SetPhase(clkPhase)             CLOCK1_SetPhaseRegister(clkPhase)
#define CLOCK1_SetPhaseValue(clkPhase)        CLOCK1_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(CLOCK1__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define CLOCK1_CLKEN              (* (reg8 *) CLOCK1__PM_ACT_CFG)
#define CLOCK1_CLKEN_PTR          ((reg8 *) CLOCK1__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define CLOCK1_CLKSTBY            (* (reg8 *) CLOCK1__PM_STBY_CFG)
#define CLOCK1_CLKSTBY_PTR        ((reg8 *) CLOCK1__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define CLOCK1_DIV_LSB            (* (reg8 *) CLOCK1__CFG0)
#define CLOCK1_DIV_LSB_PTR        ((reg8 *) CLOCK1__CFG0)
#define CLOCK1_DIV_PTR            ((reg16 *) CLOCK1__CFG0)

/* Clock MSB divider configuration register. */
#define CLOCK1_DIV_MSB            (* (reg8 *) CLOCK1__CFG1)
#define CLOCK1_DIV_MSB_PTR        ((reg8 *) CLOCK1__CFG1)

/* Mode and source configuration register */
#define CLOCK1_MOD_SRC            (* (reg8 *) CLOCK1__CFG2)
#define CLOCK1_MOD_SRC_PTR        ((reg8 *) CLOCK1__CFG2)

#if defined(CLOCK1__CFG3)
/* Analog clock phase configuration register */
#define CLOCK1_PHASE              (* (reg8 *) CLOCK1__CFG3)
#define CLOCK1_PHASE_PTR          ((reg8 *) CLOCK1__CFG3)
#endif /* defined(CLOCK1__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define CLOCK1_CLKEN_MASK         CLOCK1__PM_ACT_MSK
#define CLOCK1_CLKSTBY_MASK       CLOCK1__PM_STBY_MSK

/* CFG2 field masks */
#define CLOCK1_SRC_SEL_MSK        CLOCK1__CFG2_SRC_SEL_MASK
#define CLOCK1_MODE_MASK          (~(CLOCK1_SRC_SEL_MSK))

#if defined(CLOCK1__CFG3)
/* CFG3 phase mask */
#define CLOCK1_PHASE_MASK         CLOCK1__CFG3_PHASE_DLY_MASK
#endif /* defined(CLOCK1__CFG3) */

#endif /* CY_CLOCK_CLOCK1_H */


/* [] END OF FILE */
