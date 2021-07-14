/*******************************************************************************
* File Name: DSR.h  
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

#if !defined(CY_PINS_DSR_H) /* Pins DSR_H */
#define CY_PINS_DSR_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DSR_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 DSR__PORT == 15 && ((DSR__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    DSR_Write(uint8 value);
void    DSR_SetDriveMode(uint8 mode);
uint8   DSR_ReadDataReg(void);
uint8   DSR_Read(void);
void    DSR_SetInterruptMode(uint16 position, uint16 mode);
uint8   DSR_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the DSR_SetDriveMode() function.
     *  @{
     */
        #define DSR_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define DSR_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define DSR_DM_RES_UP          PIN_DM_RES_UP
        #define DSR_DM_RES_DWN         PIN_DM_RES_DWN
        #define DSR_DM_OD_LO           PIN_DM_OD_LO
        #define DSR_DM_OD_HI           PIN_DM_OD_HI
        #define DSR_DM_STRONG          PIN_DM_STRONG
        #define DSR_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define DSR_MASK               DSR__MASK
#define DSR_SHIFT              DSR__SHIFT
#define DSR_WIDTH              1u

/* Interrupt constants */
#if defined(DSR__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DSR_SetInterruptMode() function.
     *  @{
     */
        #define DSR_INTR_NONE      (uint16)(0x0000u)
        #define DSR_INTR_RISING    (uint16)(0x0001u)
        #define DSR_INTR_FALLING   (uint16)(0x0002u)
        #define DSR_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define DSR_INTR_MASK      (0x01u) 
#endif /* (DSR__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DSR_PS                     (* (reg8 *) DSR__PS)
/* Data Register */
#define DSR_DR                     (* (reg8 *) DSR__DR)
/* Port Number */
#define DSR_PRT_NUM                (* (reg8 *) DSR__PRT) 
/* Connect to Analog Globals */                                                  
#define DSR_AG                     (* (reg8 *) DSR__AG)                       
/* Analog MUX bux enable */
#define DSR_AMUX                   (* (reg8 *) DSR__AMUX) 
/* Bidirectional Enable */                                                        
#define DSR_BIE                    (* (reg8 *) DSR__BIE)
/* Bit-mask for Aliased Register Access */
#define DSR_BIT_MASK               (* (reg8 *) DSR__BIT_MASK)
/* Bypass Enable */
#define DSR_BYP                    (* (reg8 *) DSR__BYP)
/* Port wide control signals */                                                   
#define DSR_CTL                    (* (reg8 *) DSR__CTL)
/* Drive Modes */
#define DSR_DM0                    (* (reg8 *) DSR__DM0) 
#define DSR_DM1                    (* (reg8 *) DSR__DM1)
#define DSR_DM2                    (* (reg8 *) DSR__DM2) 
/* Input Buffer Disable Override */
#define DSR_INP_DIS                (* (reg8 *) DSR__INP_DIS)
/* LCD Common or Segment Drive */
#define DSR_LCD_COM_SEG            (* (reg8 *) DSR__LCD_COM_SEG)
/* Enable Segment LCD */
#define DSR_LCD_EN                 (* (reg8 *) DSR__LCD_EN)
/* Slew Rate Control */
#define DSR_SLW                    (* (reg8 *) DSR__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DSR_PRTDSI__CAPS_SEL       (* (reg8 *) DSR__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DSR_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DSR__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DSR_PRTDSI__OE_SEL0        (* (reg8 *) DSR__PRTDSI__OE_SEL0) 
#define DSR_PRTDSI__OE_SEL1        (* (reg8 *) DSR__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DSR_PRTDSI__OUT_SEL0       (* (reg8 *) DSR__PRTDSI__OUT_SEL0) 
#define DSR_PRTDSI__OUT_SEL1       (* (reg8 *) DSR__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DSR_PRTDSI__SYNC_OUT       (* (reg8 *) DSR__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(DSR__SIO_CFG)
    #define DSR_SIO_HYST_EN        (* (reg8 *) DSR__SIO_HYST_EN)
    #define DSR_SIO_REG_HIFREQ     (* (reg8 *) DSR__SIO_REG_HIFREQ)
    #define DSR_SIO_CFG            (* (reg8 *) DSR__SIO_CFG)
    #define DSR_SIO_DIFF           (* (reg8 *) DSR__SIO_DIFF)
#endif /* (DSR__SIO_CFG) */

/* Interrupt Registers */
#if defined(DSR__INTSTAT)
    #define DSR_INTSTAT            (* (reg8 *) DSR__INTSTAT)
    #define DSR_SNAP               (* (reg8 *) DSR__SNAP)
    
	#define DSR_0_INTTYPE_REG 		(* (reg8 *) DSR__0__INTTYPE)
#endif /* (DSR__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_DSR_H */


/* [] END OF FILE */
