/*******************************************************************************
* File Name: CTS.h  
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

#if !defined(CY_PINS_CTS_H) /* Pins CTS_H */
#define CY_PINS_CTS_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "CTS_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 CTS__PORT == 15 && ((CTS__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    CTS_Write(uint8 value);
void    CTS_SetDriveMode(uint8 mode);
uint8   CTS_ReadDataReg(void);
uint8   CTS_Read(void);
void    CTS_SetInterruptMode(uint16 position, uint16 mode);
uint8   CTS_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the CTS_SetDriveMode() function.
     *  @{
     */
        #define CTS_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define CTS_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define CTS_DM_RES_UP          PIN_DM_RES_UP
        #define CTS_DM_RES_DWN         PIN_DM_RES_DWN
        #define CTS_DM_OD_LO           PIN_DM_OD_LO
        #define CTS_DM_OD_HI           PIN_DM_OD_HI
        #define CTS_DM_STRONG          PIN_DM_STRONG
        #define CTS_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define CTS_MASK               CTS__MASK
#define CTS_SHIFT              CTS__SHIFT
#define CTS_WIDTH              1u

/* Interrupt constants */
#if defined(CTS__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in CTS_SetInterruptMode() function.
     *  @{
     */
        #define CTS_INTR_NONE      (uint16)(0x0000u)
        #define CTS_INTR_RISING    (uint16)(0x0001u)
        #define CTS_INTR_FALLING   (uint16)(0x0002u)
        #define CTS_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define CTS_INTR_MASK      (0x01u) 
#endif /* (CTS__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define CTS_PS                     (* (reg8 *) CTS__PS)
/* Data Register */
#define CTS_DR                     (* (reg8 *) CTS__DR)
/* Port Number */
#define CTS_PRT_NUM                (* (reg8 *) CTS__PRT) 
/* Connect to Analog Globals */                                                  
#define CTS_AG                     (* (reg8 *) CTS__AG)                       
/* Analog MUX bux enable */
#define CTS_AMUX                   (* (reg8 *) CTS__AMUX) 
/* Bidirectional Enable */                                                        
#define CTS_BIE                    (* (reg8 *) CTS__BIE)
/* Bit-mask for Aliased Register Access */
#define CTS_BIT_MASK               (* (reg8 *) CTS__BIT_MASK)
/* Bypass Enable */
#define CTS_BYP                    (* (reg8 *) CTS__BYP)
/* Port wide control signals */                                                   
#define CTS_CTL                    (* (reg8 *) CTS__CTL)
/* Drive Modes */
#define CTS_DM0                    (* (reg8 *) CTS__DM0) 
#define CTS_DM1                    (* (reg8 *) CTS__DM1)
#define CTS_DM2                    (* (reg8 *) CTS__DM2) 
/* Input Buffer Disable Override */
#define CTS_INP_DIS                (* (reg8 *) CTS__INP_DIS)
/* LCD Common or Segment Drive */
#define CTS_LCD_COM_SEG            (* (reg8 *) CTS__LCD_COM_SEG)
/* Enable Segment LCD */
#define CTS_LCD_EN                 (* (reg8 *) CTS__LCD_EN)
/* Slew Rate Control */
#define CTS_SLW                    (* (reg8 *) CTS__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define CTS_PRTDSI__CAPS_SEL       (* (reg8 *) CTS__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define CTS_PRTDSI__DBL_SYNC_IN    (* (reg8 *) CTS__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define CTS_PRTDSI__OE_SEL0        (* (reg8 *) CTS__PRTDSI__OE_SEL0) 
#define CTS_PRTDSI__OE_SEL1        (* (reg8 *) CTS__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define CTS_PRTDSI__OUT_SEL0       (* (reg8 *) CTS__PRTDSI__OUT_SEL0) 
#define CTS_PRTDSI__OUT_SEL1       (* (reg8 *) CTS__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define CTS_PRTDSI__SYNC_OUT       (* (reg8 *) CTS__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(CTS__SIO_CFG)
    #define CTS_SIO_HYST_EN        (* (reg8 *) CTS__SIO_HYST_EN)
    #define CTS_SIO_REG_HIFREQ     (* (reg8 *) CTS__SIO_REG_HIFREQ)
    #define CTS_SIO_CFG            (* (reg8 *) CTS__SIO_CFG)
    #define CTS_SIO_DIFF           (* (reg8 *) CTS__SIO_DIFF)
#endif /* (CTS__SIO_CFG) */

/* Interrupt Registers */
#if defined(CTS__INTSTAT)
    #define CTS_INTSTAT            (* (reg8 *) CTS__INTSTAT)
    #define CTS_SNAP               (* (reg8 *) CTS__SNAP)
    
	#define CTS_0_INTTYPE_REG 		(* (reg8 *) CTS__0__INTTYPE)
#endif /* (CTS__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_CTS_H */


/* [] END OF FILE */
