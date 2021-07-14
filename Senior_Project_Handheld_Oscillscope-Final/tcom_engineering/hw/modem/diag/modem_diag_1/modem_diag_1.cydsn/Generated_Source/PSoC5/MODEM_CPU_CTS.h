/*******************************************************************************
* File Name: MODEM_CPU_CTS.h  
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

#if !defined(CY_PINS_MODEM_CPU_CTS_H) /* Pins MODEM_CPU_CTS_H */
#define CY_PINS_MODEM_CPU_CTS_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MODEM_CPU_CTS_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 MODEM_CPU_CTS__PORT == 15 && ((MODEM_CPU_CTS__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    MODEM_CPU_CTS_Write(uint8 value);
void    MODEM_CPU_CTS_SetDriveMode(uint8 mode);
uint8   MODEM_CPU_CTS_ReadDataReg(void);
uint8   MODEM_CPU_CTS_Read(void);
void    MODEM_CPU_CTS_SetInterruptMode(uint16 position, uint16 mode);
uint8   MODEM_CPU_CTS_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the MODEM_CPU_CTS_SetDriveMode() function.
     *  @{
     */
        #define MODEM_CPU_CTS_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define MODEM_CPU_CTS_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define MODEM_CPU_CTS_DM_RES_UP          PIN_DM_RES_UP
        #define MODEM_CPU_CTS_DM_RES_DWN         PIN_DM_RES_DWN
        #define MODEM_CPU_CTS_DM_OD_LO           PIN_DM_OD_LO
        #define MODEM_CPU_CTS_DM_OD_HI           PIN_DM_OD_HI
        #define MODEM_CPU_CTS_DM_STRONG          PIN_DM_STRONG
        #define MODEM_CPU_CTS_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define MODEM_CPU_CTS_MASK               MODEM_CPU_CTS__MASK
#define MODEM_CPU_CTS_SHIFT              MODEM_CPU_CTS__SHIFT
#define MODEM_CPU_CTS_WIDTH              1u

/* Interrupt constants */
#if defined(MODEM_CPU_CTS__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in MODEM_CPU_CTS_SetInterruptMode() function.
     *  @{
     */
        #define MODEM_CPU_CTS_INTR_NONE      (uint16)(0x0000u)
        #define MODEM_CPU_CTS_INTR_RISING    (uint16)(0x0001u)
        #define MODEM_CPU_CTS_INTR_FALLING   (uint16)(0x0002u)
        #define MODEM_CPU_CTS_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define MODEM_CPU_CTS_INTR_MASK      (0x01u) 
#endif /* (MODEM_CPU_CTS__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MODEM_CPU_CTS_PS                     (* (reg8 *) MODEM_CPU_CTS__PS)
/* Data Register */
#define MODEM_CPU_CTS_DR                     (* (reg8 *) MODEM_CPU_CTS__DR)
/* Port Number */
#define MODEM_CPU_CTS_PRT_NUM                (* (reg8 *) MODEM_CPU_CTS__PRT) 
/* Connect to Analog Globals */                                                  
#define MODEM_CPU_CTS_AG                     (* (reg8 *) MODEM_CPU_CTS__AG)                       
/* Analog MUX bux enable */
#define MODEM_CPU_CTS_AMUX                   (* (reg8 *) MODEM_CPU_CTS__AMUX) 
/* Bidirectional Enable */                                                        
#define MODEM_CPU_CTS_BIE                    (* (reg8 *) MODEM_CPU_CTS__BIE)
/* Bit-mask for Aliased Register Access */
#define MODEM_CPU_CTS_BIT_MASK               (* (reg8 *) MODEM_CPU_CTS__BIT_MASK)
/* Bypass Enable */
#define MODEM_CPU_CTS_BYP                    (* (reg8 *) MODEM_CPU_CTS__BYP)
/* Port wide control signals */                                                   
#define MODEM_CPU_CTS_CTL                    (* (reg8 *) MODEM_CPU_CTS__CTL)
/* Drive Modes */
#define MODEM_CPU_CTS_DM0                    (* (reg8 *) MODEM_CPU_CTS__DM0) 
#define MODEM_CPU_CTS_DM1                    (* (reg8 *) MODEM_CPU_CTS__DM1)
#define MODEM_CPU_CTS_DM2                    (* (reg8 *) MODEM_CPU_CTS__DM2) 
/* Input Buffer Disable Override */
#define MODEM_CPU_CTS_INP_DIS                (* (reg8 *) MODEM_CPU_CTS__INP_DIS)
/* LCD Common or Segment Drive */
#define MODEM_CPU_CTS_LCD_COM_SEG            (* (reg8 *) MODEM_CPU_CTS__LCD_COM_SEG)
/* Enable Segment LCD */
#define MODEM_CPU_CTS_LCD_EN                 (* (reg8 *) MODEM_CPU_CTS__LCD_EN)
/* Slew Rate Control */
#define MODEM_CPU_CTS_SLW                    (* (reg8 *) MODEM_CPU_CTS__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MODEM_CPU_CTS_PRTDSI__CAPS_SEL       (* (reg8 *) MODEM_CPU_CTS__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MODEM_CPU_CTS_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MODEM_CPU_CTS__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MODEM_CPU_CTS_PRTDSI__OE_SEL0        (* (reg8 *) MODEM_CPU_CTS__PRTDSI__OE_SEL0) 
#define MODEM_CPU_CTS_PRTDSI__OE_SEL1        (* (reg8 *) MODEM_CPU_CTS__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MODEM_CPU_CTS_PRTDSI__OUT_SEL0       (* (reg8 *) MODEM_CPU_CTS__PRTDSI__OUT_SEL0) 
#define MODEM_CPU_CTS_PRTDSI__OUT_SEL1       (* (reg8 *) MODEM_CPU_CTS__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MODEM_CPU_CTS_PRTDSI__SYNC_OUT       (* (reg8 *) MODEM_CPU_CTS__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(MODEM_CPU_CTS__SIO_CFG)
    #define MODEM_CPU_CTS_SIO_HYST_EN        (* (reg8 *) MODEM_CPU_CTS__SIO_HYST_EN)
    #define MODEM_CPU_CTS_SIO_REG_HIFREQ     (* (reg8 *) MODEM_CPU_CTS__SIO_REG_HIFREQ)
    #define MODEM_CPU_CTS_SIO_CFG            (* (reg8 *) MODEM_CPU_CTS__SIO_CFG)
    #define MODEM_CPU_CTS_SIO_DIFF           (* (reg8 *) MODEM_CPU_CTS__SIO_DIFF)
#endif /* (MODEM_CPU_CTS__SIO_CFG) */

/* Interrupt Registers */
#if defined(MODEM_CPU_CTS__INTSTAT)
    #define MODEM_CPU_CTS_INTSTAT            (* (reg8 *) MODEM_CPU_CTS__INTSTAT)
    #define MODEM_CPU_CTS_SNAP               (* (reg8 *) MODEM_CPU_CTS__SNAP)
    
	#define MODEM_CPU_CTS_0_INTTYPE_REG 		(* (reg8 *) MODEM_CPU_CTS__0__INTTYPE)
#endif /* (MODEM_CPU_CTS__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_MODEM_CPU_CTS_H */


/* [] END OF FILE */
