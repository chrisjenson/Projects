/*******************************************************************************
* File Name: DTR.h  
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

#if !defined(CY_PINS_DTR_H) /* Pins DTR_H */
#define CY_PINS_DTR_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DTR_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 DTR__PORT == 15 && ((DTR__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    DTR_Write(uint8 value);
void    DTR_SetDriveMode(uint8 mode);
uint8   DTR_ReadDataReg(void);
uint8   DTR_Read(void);
void    DTR_SetInterruptMode(uint16 position, uint16 mode);
uint8   DTR_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the DTR_SetDriveMode() function.
     *  @{
     */
        #define DTR_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define DTR_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define DTR_DM_RES_UP          PIN_DM_RES_UP
        #define DTR_DM_RES_DWN         PIN_DM_RES_DWN
        #define DTR_DM_OD_LO           PIN_DM_OD_LO
        #define DTR_DM_OD_HI           PIN_DM_OD_HI
        #define DTR_DM_STRONG          PIN_DM_STRONG
        #define DTR_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define DTR_MASK               DTR__MASK
#define DTR_SHIFT              DTR__SHIFT
#define DTR_WIDTH              1u

/* Interrupt constants */
#if defined(DTR__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DTR_SetInterruptMode() function.
     *  @{
     */
        #define DTR_INTR_NONE      (uint16)(0x0000u)
        #define DTR_INTR_RISING    (uint16)(0x0001u)
        #define DTR_INTR_FALLING   (uint16)(0x0002u)
        #define DTR_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define DTR_INTR_MASK      (0x01u) 
#endif /* (DTR__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DTR_PS                     (* (reg8 *) DTR__PS)
/* Data Register */
#define DTR_DR                     (* (reg8 *) DTR__DR)
/* Port Number */
#define DTR_PRT_NUM                (* (reg8 *) DTR__PRT) 
/* Connect to Analog Globals */                                                  
#define DTR_AG                     (* (reg8 *) DTR__AG)                       
/* Analog MUX bux enable */
#define DTR_AMUX                   (* (reg8 *) DTR__AMUX) 
/* Bidirectional Enable */                                                        
#define DTR_BIE                    (* (reg8 *) DTR__BIE)
/* Bit-mask for Aliased Register Access */
#define DTR_BIT_MASK               (* (reg8 *) DTR__BIT_MASK)
/* Bypass Enable */
#define DTR_BYP                    (* (reg8 *) DTR__BYP)
/* Port wide control signals */                                                   
#define DTR_CTL                    (* (reg8 *) DTR__CTL)
/* Drive Modes */
#define DTR_DM0                    (* (reg8 *) DTR__DM0) 
#define DTR_DM1                    (* (reg8 *) DTR__DM1)
#define DTR_DM2                    (* (reg8 *) DTR__DM2) 
/* Input Buffer Disable Override */
#define DTR_INP_DIS                (* (reg8 *) DTR__INP_DIS)
/* LCD Common or Segment Drive */
#define DTR_LCD_COM_SEG            (* (reg8 *) DTR__LCD_COM_SEG)
/* Enable Segment LCD */
#define DTR_LCD_EN                 (* (reg8 *) DTR__LCD_EN)
/* Slew Rate Control */
#define DTR_SLW                    (* (reg8 *) DTR__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DTR_PRTDSI__CAPS_SEL       (* (reg8 *) DTR__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DTR_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DTR__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DTR_PRTDSI__OE_SEL0        (* (reg8 *) DTR__PRTDSI__OE_SEL0) 
#define DTR_PRTDSI__OE_SEL1        (* (reg8 *) DTR__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DTR_PRTDSI__OUT_SEL0       (* (reg8 *) DTR__PRTDSI__OUT_SEL0) 
#define DTR_PRTDSI__OUT_SEL1       (* (reg8 *) DTR__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DTR_PRTDSI__SYNC_OUT       (* (reg8 *) DTR__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(DTR__SIO_CFG)
    #define DTR_SIO_HYST_EN        (* (reg8 *) DTR__SIO_HYST_EN)
    #define DTR_SIO_REG_HIFREQ     (* (reg8 *) DTR__SIO_REG_HIFREQ)
    #define DTR_SIO_CFG            (* (reg8 *) DTR__SIO_CFG)
    #define DTR_SIO_DIFF           (* (reg8 *) DTR__SIO_DIFF)
#endif /* (DTR__SIO_CFG) */

/* Interrupt Registers */
#if defined(DTR__INTSTAT)
    #define DTR_INTSTAT            (* (reg8 *) DTR__INTSTAT)
    #define DTR_SNAP               (* (reg8 *) DTR__SNAP)
    
	#define DTR_0_INTTYPE_REG 		(* (reg8 *) DTR__0__INTTYPE)
#endif /* (DTR__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_DTR_H */


/* [] END OF FILE */
