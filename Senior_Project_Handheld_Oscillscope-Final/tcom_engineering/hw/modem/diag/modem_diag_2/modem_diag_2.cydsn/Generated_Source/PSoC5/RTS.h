/*******************************************************************************
* File Name: RTS.h  
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

#if !defined(CY_PINS_RTS_H) /* Pins RTS_H */
#define CY_PINS_RTS_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "RTS_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 RTS__PORT == 15 && ((RTS__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    RTS_Write(uint8 value);
void    RTS_SetDriveMode(uint8 mode);
uint8   RTS_ReadDataReg(void);
uint8   RTS_Read(void);
void    RTS_SetInterruptMode(uint16 position, uint16 mode);
uint8   RTS_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the RTS_SetDriveMode() function.
     *  @{
     */
        #define RTS_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define RTS_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define RTS_DM_RES_UP          PIN_DM_RES_UP
        #define RTS_DM_RES_DWN         PIN_DM_RES_DWN
        #define RTS_DM_OD_LO           PIN_DM_OD_LO
        #define RTS_DM_OD_HI           PIN_DM_OD_HI
        #define RTS_DM_STRONG          PIN_DM_STRONG
        #define RTS_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define RTS_MASK               RTS__MASK
#define RTS_SHIFT              RTS__SHIFT
#define RTS_WIDTH              1u

/* Interrupt constants */
#if defined(RTS__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in RTS_SetInterruptMode() function.
     *  @{
     */
        #define RTS_INTR_NONE      (uint16)(0x0000u)
        #define RTS_INTR_RISING    (uint16)(0x0001u)
        #define RTS_INTR_FALLING   (uint16)(0x0002u)
        #define RTS_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define RTS_INTR_MASK      (0x01u) 
#endif /* (RTS__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define RTS_PS                     (* (reg8 *) RTS__PS)
/* Data Register */
#define RTS_DR                     (* (reg8 *) RTS__DR)
/* Port Number */
#define RTS_PRT_NUM                (* (reg8 *) RTS__PRT) 
/* Connect to Analog Globals */                                                  
#define RTS_AG                     (* (reg8 *) RTS__AG)                       
/* Analog MUX bux enable */
#define RTS_AMUX                   (* (reg8 *) RTS__AMUX) 
/* Bidirectional Enable */                                                        
#define RTS_BIE                    (* (reg8 *) RTS__BIE)
/* Bit-mask for Aliased Register Access */
#define RTS_BIT_MASK               (* (reg8 *) RTS__BIT_MASK)
/* Bypass Enable */
#define RTS_BYP                    (* (reg8 *) RTS__BYP)
/* Port wide control signals */                                                   
#define RTS_CTL                    (* (reg8 *) RTS__CTL)
/* Drive Modes */
#define RTS_DM0                    (* (reg8 *) RTS__DM0) 
#define RTS_DM1                    (* (reg8 *) RTS__DM1)
#define RTS_DM2                    (* (reg8 *) RTS__DM2) 
/* Input Buffer Disable Override */
#define RTS_INP_DIS                (* (reg8 *) RTS__INP_DIS)
/* LCD Common or Segment Drive */
#define RTS_LCD_COM_SEG            (* (reg8 *) RTS__LCD_COM_SEG)
/* Enable Segment LCD */
#define RTS_LCD_EN                 (* (reg8 *) RTS__LCD_EN)
/* Slew Rate Control */
#define RTS_SLW                    (* (reg8 *) RTS__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define RTS_PRTDSI__CAPS_SEL       (* (reg8 *) RTS__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define RTS_PRTDSI__DBL_SYNC_IN    (* (reg8 *) RTS__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define RTS_PRTDSI__OE_SEL0        (* (reg8 *) RTS__PRTDSI__OE_SEL0) 
#define RTS_PRTDSI__OE_SEL1        (* (reg8 *) RTS__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define RTS_PRTDSI__OUT_SEL0       (* (reg8 *) RTS__PRTDSI__OUT_SEL0) 
#define RTS_PRTDSI__OUT_SEL1       (* (reg8 *) RTS__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define RTS_PRTDSI__SYNC_OUT       (* (reg8 *) RTS__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(RTS__SIO_CFG)
    #define RTS_SIO_HYST_EN        (* (reg8 *) RTS__SIO_HYST_EN)
    #define RTS_SIO_REG_HIFREQ     (* (reg8 *) RTS__SIO_REG_HIFREQ)
    #define RTS_SIO_CFG            (* (reg8 *) RTS__SIO_CFG)
    #define RTS_SIO_DIFF           (* (reg8 *) RTS__SIO_DIFF)
#endif /* (RTS__SIO_CFG) */

/* Interrupt Registers */
#if defined(RTS__INTSTAT)
    #define RTS_INTSTAT            (* (reg8 *) RTS__INTSTAT)
    #define RTS_SNAP               (* (reg8 *) RTS__SNAP)
    
	#define RTS_0_INTTYPE_REG 		(* (reg8 *) RTS__0__INTTYPE)
#endif /* (RTS__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_RTS_H */


/* [] END OF FILE */
