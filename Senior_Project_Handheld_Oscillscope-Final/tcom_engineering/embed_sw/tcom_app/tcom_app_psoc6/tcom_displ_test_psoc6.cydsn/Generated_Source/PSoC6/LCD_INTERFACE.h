/*******************************************************************************
* File Name: LCD_INTERFACE.h
* Version 1.80
*
* Description:
*  This file provides the constants and parameter values and API definition for the 
*  GraphicLCDIntf Component
*
********************************************************************************
* Copyright 2008-2018, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_GraphicLCDIntf_LCD_INTERFACE_H)
#define CY_GraphicLCDIntf_LCD_INTERFACE_H

#include "cyfitter.h"

#if (CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC6)
    #include "syslib/cy_syslib.h"
#elif (CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3 || \
       CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC4 || \
       CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC5)
    #include "cytypes.h"
#endif

/*************************************** 
*   Conditional Compilation Parameters
***************************************/

#define LCD_INTERFACE_BUS_WIDTH (8u)

/***************************************
*        Function Prototypes            
***************************************/

void LCD_INTERFACE_Start(void) ;
void LCD_INTERFACE_Stop(void) ;
void LCD_INTERFACE_Write8(uint8 d_c, uint8 wrData) ;
void LCD_INTERFACE_WriteM8(uint8 d_c, uint8 wrData[], uint16 num) ;
uint8 LCD_INTERFACE_Read8(uint8 d_c) ;
void LCD_INTERFACE_ReadM8(uint8 d_c, uint8 rdData[], uint16 num) ;  
                                                
void LCD_INTERFACE_Write8_A0(uint8 wrData) ;
void LCD_INTERFACE_Write8_A1(uint8 wrData) ;
void LCD_INTERFACE_WriteM8_A0(uint8 wrData[], int num) ;
void LCD_INTERFACE_WriteM8_A1(uint8 wrData[], int num) ;
uint8 LCD_INTERFACE_Read8_A1(void) ;
void LCD_INTERFACE_ReadM8_A1(uint8 rdData[], int num) ;

void LCD_INTERFACE_Sleep(void) ;
void LCD_INTERFACE_Wakeup(void) ;
void LCD_INTERFACE_SaveConfig(void) ;   
void LCD_INTERFACE_RestoreConfig(void) ;
void LCD_INTERFACE_Init(void) ;
void LCD_INTERFACE_Enable(void) ;

#define CYGRAPHICS_START()                  LCD_INTERFACE_Start()
#define CYGRAPHICS_STOP()                   LCD_INTERFACE_Stop()
#define CYGRAPHICS_WRITE(addr, data)        LCD_INTERFACE_Write8(addr, data)
#define CYGRAPHICS_READ(addr)               LCD_INTERFACE_Read8(addr)
#define CYGRAPHICS_WRITEM(addr, data, num)  LCD_INTERFACE_WriteM8(addr, data, num)
#define CYGRAPHICS_READM(addr, data, num)   LCD_INTERFACE_ReadM8(addr, data, num)


/***************************************
*    Variables with External Linkage
***************************************/

extern uint8 LCD_INTERFACE_initVar;


/***************************************
*           API Constants               
***************************************/

#define LCD_INTERFACE_CMD_QUEUE_FULL           (0x01u)
#define LCD_INTERFACE_DATA_VALID               (0x02u)

#define LCD_INTERFACE_READ_COMMAND             (0x02u)

#define LCD_INTERFACE_DATA_ADDRESS             (0x01u)
#define LCD_INTERFACE_COMMAND_ADDRESS          (0x00u)


/***************************************
*    Enumerated Types and Parameters    
***************************************/


/***************************************
*    Initial Parameter Constants        
***************************************/

/* Set 2 smaller than a period because di must be sampled one cycle before
*  the end of the read Low intervals.
*/ 
#define LCD_INTERFACE_READ_LOW_PULSE           (18u - 2u)   

/* Set 1 smaller than a period */ 
#define LCD_INTERFACE_READ_HIGH_PULSE          (5u - 1u)


/***************************************
*             Registers                 
***************************************/

#define LCD_INTERFACE_STATUS_REG                     (* (reg8 *)  LCD_INTERFACE_StsReg__STATUS_REG)
#define LCD_INTERFACE_STATUS_PTR                     (  (reg8 *)  LCD_INTERFACE_StsReg__STATUS_REG)

#define LCD_INTERFACE_DIN_LSB_DATA_REG               (* (reg8 *)  LCD_INTERFACE_LsbReg__STATUS_REG)
#define LCD_INTERFACE_DIN_LSB_DATA_PTR               (  (reg8 *)  LCD_INTERFACE_LsbReg__STATUS_REG)

#if (LCD_INTERFACE_BUS_WIDTH == 8u)   /* 8-bit interface */
    #define LCD_INTERFACE_CMD_FIFO_REG               (* (reg8 *)  LCD_INTERFACE_GraphLcd8_Lsb__F0_REG)
    #define LCD_INTERFACE_CMD_FIFO_PTR               (  (reg8 *)  LCD_INTERFACE_GraphLcd8_Lsb__F0_REG)
    #define LCD_INTERFACE_DATA_FIFO_REG              (* (reg8 *)  LCD_INTERFACE_GraphLcd8_Lsb__F1_REG)
    #define LCD_INTERFACE_DATA_FIFO_PTR              (  (reg8 *)  LCD_INTERFACE_GraphLcd8_Lsb__F1_REG)    
    #define LCD_INTERFACE_READ_LO_PULSE_REG          (* (reg8 *)  LCD_INTERFACE_GraphLcd8_Lsb__D0_REG)
    #define LCD_INTERFACE_READ_LO_PULSE_PTR          (  (reg8 *)  LCD_INTERFACE_GraphLcd8_Lsb__D0_REG)
    #define LCD_INTERFACE_READ_HI_PULSE_REG          (* (reg8 *)  LCD_INTERFACE_GraphLcd8_Lsb__D1_REG)
    #define LCD_INTERFACE_READ_HI_PULSE_PTR          (  (reg8 *)  LCD_INTERFACE_GraphLcd8_Lsb__D1_REG)
#else   /* 16-bit interface */   
    #define LCD_INTERFACE_CMD_FIFO_REG               (* (reg8 *)  LCD_INTERFACE_GraphLcd16_Lsb__F0_REG)
    #define LCD_INTERFACE_CMD_FIFO_PTR               (  (reg8 *)  LCD_INTERFACE_GraphLcd16_Lsb__F0_REG)
	
    #if (CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC4)
        #define LCD_INTERFACE_DATA_FIFO_PTR              (  (reg16 *) LCD_INTERFACE_GraphLcd16_Lsb__16BIT_F1_REG)
    #else
        #define LCD_INTERFACE_DATA_FIFO_PTR              (  (reg16 *) LCD_INTERFACE_GraphLcd16_Lsb__F1_REG)
    #endif
    #define LCD_INTERFACE_DIN_MSB_DATA_REG           (* (reg8 *)  LCD_INTERFACE_GraphLcd16_MsbReg__STATUS_REG)
    #define LCD_INTERFACE_DIN_MSB_DATA_PTR           (  (reg8 *)  LCD_INTERFACE_GraphLcd16_MsbReg__STATUS_REG)
    #define LCD_INTERFACE_READ_LO_PULSE_REG          (* (reg8 *)  LCD_INTERFACE_GraphLcd16_Lsb__D0_REG)
    #define LCD_INTERFACE_READ_LO_PULSE_PTR          (  (reg8 *)  LCD_INTERFACE_GraphLcd16_Lsb__D0_REG)
    #define LCD_INTERFACE_READ_HI_PULSE_REG          (* (reg8 *)  LCD_INTERFACE_GraphLcd16_Lsb__D1_REG)
    #define LCD_INTERFACE_READ_HI_PULSE_PTR          (  (reg8 *)  LCD_INTERFACE_GraphLcd16_Lsb__D1_REG)        
#endif /* LCD_INTERFACE_BUS_WIDTH == 8u */

#endif /* CY_GraphicLCDIntf_LCD_INTERFACE_H */


/* [] END OF FILE */
