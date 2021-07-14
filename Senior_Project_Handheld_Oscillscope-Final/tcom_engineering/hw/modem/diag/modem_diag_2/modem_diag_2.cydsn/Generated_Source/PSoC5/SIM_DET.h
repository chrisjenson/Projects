/*******************************************************************************
* File Name: SIM_DET.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_SIM_DET_H) /* Pins SIM_DET_H */
#define CY_PINS_SIM_DET_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SIM_DET_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SIM_DET__PORT == 15 && ((SIM_DET__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    SIM_DET_Write(uint8 value);
void    SIM_DET_SetDriveMode(uint8 mode);
uint8   SIM_DET_ReadDataReg(void);
uint8   SIM_DET_Read(void);
void    SIM_DET_SetInterruptMode(uint16 position, uint16 mode);
uint8   SIM_DET_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the SIM_DET_SetDriveMode() function.
     *  @{
     */
        #define SIM_DET_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define SIM_DET_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define SIM_DET_DM_RES_UP          PIN_DM_RES_UP
        #define SIM_DET_DM_RES_DWN         PIN_DM_RES_DWN
        #define SIM_DET_DM_OD_LO           PIN_DM_OD_LO
        #define SIM_DET_DM_OD_HI           PIN_DM_OD_HI
        #define SIM_DET_DM_STRONG          PIN_DM_STRONG
        #define SIM_DET_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define SIM_DET_MASK               SIM_DET__MASK
#define SIM_DET_SHIFT              SIM_DET__SHIFT
#define SIM_DET_WIDTH              1u

/* Interrupt constants */
#if defined(SIM_DET__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SIM_DET_SetInterruptMode() function.
     *  @{
     */
        #define SIM_DET_INTR_NONE      (uint16)(0x0000u)
        #define SIM_DET_INTR_RISING    (uint16)(0x0001u)
        #define SIM_DET_INTR_FALLING   (uint16)(0x0002u)
        #define SIM_DET_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define SIM_DET_INTR_MASK      (0x01u) 
#endif /* (SIM_DET__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SIM_DET_PS                     (* (reg8 *) SIM_DET__PS)
/* Data Register */
#define SIM_DET_DR                     (* (reg8 *) SIM_DET__DR)
/* Port Number */
#define SIM_DET_PRT_NUM                (* (reg8 *) SIM_DET__PRT) 
/* Connect to Analog Globals */                                                  
#define SIM_DET_AG                     (* (reg8 *) SIM_DET__AG)                       
/* Analog MUX bux enable */
#define SIM_DET_AMUX                   (* (reg8 *) SIM_DET__AMUX) 
/* Bidirectional Enable */                                                        
#define SIM_DET_BIE                    (* (reg8 *) SIM_DET__BIE)
/* Bit-mask for Aliased Register Access */
#define SIM_DET_BIT_MASK               (* (reg8 *) SIM_DET__BIT_MASK)
/* Bypass Enable */
#define SIM_DET_BYP                    (* (reg8 *) SIM_DET__BYP)
/* Port wide control signals */                                                   
#define SIM_DET_CTL                    (* (reg8 *) SIM_DET__CTL)
/* Drive Modes */
#define SIM_DET_DM0                    (* (reg8 *) SIM_DET__DM0) 
#define SIM_DET_DM1                    (* (reg8 *) SIM_DET__DM1)
#define SIM_DET_DM2                    (* (reg8 *) SIM_DET__DM2) 
/* Input Buffer Disable Override */
#define SIM_DET_INP_DIS                (* (reg8 *) SIM_DET__INP_DIS)
/* LCD Common or Segment Drive */
#define SIM_DET_LCD_COM_SEG            (* (reg8 *) SIM_DET__LCD_COM_SEG)
/* Enable Segment LCD */
#define SIM_DET_LCD_EN                 (* (reg8 *) SIM_DET__LCD_EN)
/* Slew Rate Control */
#define SIM_DET_SLW                    (* (reg8 *) SIM_DET__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SIM_DET_PRTDSI__CAPS_SEL       (* (reg8 *) SIM_DET__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SIM_DET_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SIM_DET__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SIM_DET_PRTDSI__OE_SEL0        (* (reg8 *) SIM_DET__PRTDSI__OE_SEL0) 
#define SIM_DET_PRTDSI__OE_SEL1        (* (reg8 *) SIM_DET__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SIM_DET_PRTDSI__OUT_SEL0       (* (reg8 *) SIM_DET__PRTDSI__OUT_SEL0) 
#define SIM_DET_PRTDSI__OUT_SEL1       (* (reg8 *) SIM_DET__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SIM_DET_PRTDSI__SYNC_OUT       (* (reg8 *) SIM_DET__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(SIM_DET__SIO_CFG)
    #define SIM_DET_SIO_HYST_EN        (* (reg8 *) SIM_DET__SIO_HYST_EN)
    #define SIM_DET_SIO_REG_HIFREQ     (* (reg8 *) SIM_DET__SIO_REG_HIFREQ)
    #define SIM_DET_SIO_CFG            (* (reg8 *) SIM_DET__SIO_CFG)
    #define SIM_DET_SIO_DIFF           (* (reg8 *) SIM_DET__SIO_DIFF)
#endif /* (SIM_DET__SIO_CFG) */

/* Interrupt Registers */
#if defined(SIM_DET__INTSTAT)
    #define SIM_DET_INTSTAT            (* (reg8 *) SIM_DET__INTSTAT)
    #define SIM_DET_SNAP               (* (reg8 *) SIM_DET__SNAP)
    
	#define SIM_DET_0_INTTYPE_REG 		(* (reg8 *) SIM_DET__0__INTTYPE)
#endif /* (SIM_DET__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SIM_DET_H */


/* [] END OF FILE */
