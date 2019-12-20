/*******************************************************************************
* File Name: Driver1.h
* Version 1.10
*
* Description:
*  This file provides constants and parameter values and API definition for the
*  LED Driver Component
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_LED_Driver_Driver1_H)
#define CY_LED_Driver_Driver1_H


/***************************************
*   Conditional Compilation Parameters
***************************************/
#define Driver1_BRIGHTNESS_EN                (0u)
#define Driver1_COM_DRIVE                    (0u)
#define Driver1_SEG_DRIVE                    (0u)
#define Driver1_NUM_COM                      (4u)
#define Driver1_NUM_SEG                      (8u)
#define Driver1_TWO_NUM_COM                  ((uint8)((uint8)Driver1_NUM_COM << 1u))

/* Error message for removed commons control register through optimization */
#ifdef Driver1_Com_Driver_Sync_ctrl_reg__REMOVED
    #error LED_Driver_v1_10 requires all the signals from the commons terminal to be connected to pins.
#endif /* Driver1_Com_Driver_Sync_ctrl_reg__REMOVED */

/* Error message for removed segments control registers through optimization */
#if defined Driver1_Seg_Driver_L_Sync_ctrl_reg__REMOVED || \
defined Driver1_Seg_Driver_M_Sync_ctrl_reg__REMOVED || \
defined Driver1_Seg_Driver_H_Sync_ctrl_reg__REMOVED
    #error LED_Driver_v1_10 requires all the signals from the segments terminal to be connected to pins.
#endif /* Driver1_Seg_Driver_L_Sync_ctrl_reg__REMOVED */


/***************************************
*   Header files
***************************************/
#include <Driver1_Com_Driver.h>
#include <Driver1_Seg_Driver_L.h>
#if (Driver1_NUM_SEG > 8u)
    #include <Driver1_Seg_Driver_M.h>
#endif /* Segment_M control register */
#if (Driver1_NUM_SEG > 16u)
    #include <Driver1_Seg_Driver_H.h>
#endif /* Segment_H control register */

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#ifndef CY_PSOC5A
    #error Component LED_Driver_v1_10 requires cy_boot v3.0 or later
#endif /* CY_PSOC5A */


/***************************************
*        Structure Definitions
***************************************/
typedef struct
{
    uint8 ledEnableState;
    /* Backup the segment values when going to sleep. (Stop() clears the buffers) */
    uint8 segLBackup[Driver1_NUM_COM];
    #if (Driver1_NUM_SEG > 8u) 
        uint8 segMBackup[Driver1_NUM_COM];
    #endif /* (Driver1_NUM_SEG > 8u) */
    #if (Driver1_NUM_SEG > 16u) 
        uint8 segHBackup[Driver1_NUM_COM];
    #endif /* (Driver1_NUM_SEG > 16u) */
}Driver1_backupStruct;


/***************************************
*        Function Prototypes
***************************************/
void Driver1_Init(void)                       ;
void Driver1_Enable(void)                     ;
void Driver1_Start(void)                      ;
void Driver1_Stop(void)                       ;
void Driver1_SetDisplayRAM(uint8 value, uint8 position) 
                                                        ;
void Driver1_SetRC(uint8 row, uint8 column)    ;
void Driver1_ClearRC(uint8 row, uint8 column)  ;
void Driver1_ToggleRC(uint8 row, uint8 column) ;
uint8 Driver1_GetRC(uint8 row, uint8 column)   ;
void Driver1_ClearDisplay(uint8 position)      ;
void Driver1_ClearDisplayAll(void)             ;
void Driver1_Write7SegNumberDec(int32 number, uint8 position, uint8 digits, uint8 alignment)
                                                        ;
void Driver1_Write7SegNumberHex(uint32 number, uint8 position, uint8 digits, uint8 alignment)
                                                        ;
void Driver1_WriteString7Seg(char8 const character[], uint8 position)
                                                        ;
void Driver1_PutChar7Seg(char8 character , uint8 position)
                                                        ;
void Driver1_Write7SegDigitDec(uint8 digit, uint8 position)
                                                        ;
void Driver1_Write7SegDigitHex(uint8 digit, uint8 position)
                                                        ;
void Driver1_Write14SegNumberDec(int32 number, uint8 position, uint8 digits, uint8 alignment)
                                                        ;
void Driver1_Write14SegNumberHex(uint32 number, uint8 position, uint8 digits, uint8 alignment)
                                                        ;
void Driver1_WriteString14Seg(char8 const character[], uint8 position)
                                                        ;
void Driver1_PutChar14Seg(char8 character , uint8 position)
                                                        ;
void Driver1_Write14SegDigitDec(uint8 digit, uint8 position)
                                                        ;
void Driver1_Write14SegDigitHex(uint8 digit, uint8 position)
                                                        ;
void Driver1_Write16SegNumberDec(int32 number, uint8 position, uint8 digits, uint8 alignment)
                                                        ;
void Driver1_Write16SegNumberHex(uint32 number, uint8 position, uint8 digits, uint8 alignment)
                                                        ;
void Driver1_WriteString16Seg(char8 const character[], uint8 position)
                                                        ;
void Driver1_PutChar16Seg(char8 character , uint8 position)
                                                        ;
void Driver1_Write16SegDigitDec(uint8 digit, uint8 position)
                                                        ;
void Driver1_Write16SegDigitHex(uint8 digit, uint8 position)
                                                        ;
void Driver1_PutDecimalPoint(uint8 dp, uint8 position)
                                                        ;
uint8 Driver1_GetDecimalPoint(uint8 position)  ;
uint8 Driver1_EncodeNumber7Seg(uint8 number)   ;
uint8 Driver1_EncodeChar7Seg(char8 input)      ;
uint16 Driver1_EncodeNumber14Seg(uint8 number) ;
uint16 Driver1_EncodeChar14Seg(char8 input)    ;
uint16 Driver1_EncodeNumber16Seg(uint8 number) ;
uint16 Driver1_EncodeChar16Seg(char8 input)    ;
void Driver1_SetBrightness(uint8 bright, uint8 position)
                                                        ;
uint8 Driver1_GetBrightness(uint8 position)    ;
void Driver1_Sleep(void)                       ;
void Driver1_Wakeup(void)                      ;


/***************************************
*           Global Variables
***************************************/
extern uint8 Driver1_initVar;
extern uint8 Driver1_enableVar;

/* Buffers used to hold the display(segment) values to be transferred to the control registers */
extern uint8 Driver1_segLBuffer[Driver1_NUM_COM];
#if (Driver1_NUM_SEG > 8u) 
    extern uint8 Driver1_segMBuffer[Driver1_NUM_COM];
#endif /* (Driver1_NUM_SEG > 8u) */
#if (Driver1_NUM_SEG > 16u) 
    extern uint8 Driver1_segHBuffer[Driver1_NUM_COM];
#endif /* (Driver1_NUM_SEG > 16u) */


/***************************************
*           API Constants
***************************************/

/* Related to conditional compilation */
#define Driver1_HIGH                   (0x01u)
#define Driver1_ENABLED                (0x01u)

/* Number of DMA channels */
#if (Driver1_BRIGHTNESS_EN == Driver1_ENABLED)
    #define Driver1_CHANNEL_LIMIT      (0x03u)
#else
    #define Driver1_CHANNEL_LIMIT      (0x02u)
#endif /* (Driver1_BRIGHTNESS_EN == Driver1_ENABLED) */

/* Defines related to sign extraction for number displays */
#define Driver1_SIGNED                 (0x01u)
#define Driver1_UNSIGNED               (0x00u)
#define Driver1_ZERO_NEG               ((int32)0x00000000)

/* Brightness control defines */
#define Driver1_INIT_BRIGHT            (0xFFu)

/* Segment display defines */
#if(Driver1_SEG_DRIVE == Driver1_HIGH)
    #define Driver1_CLEAR              (0x00u)
    #define Driver1_CLEAR_16           ((uint16)0x0000u)
    #define Driver1_ZERO_7CHAR         (0x3Fu)
    #define Driver1_ZERO_14CHAR        ((uint16)0x243Fu)
    #define Driver1_ZERO_16CHAR        ((uint16)0x90FFu)
#else
    #define Driver1_CLEAR              (0xFFu)
    #define Driver1_CLEAR_16           ((uint16)0xFFFFu)
    #define Driver1_ZERO_7CHAR         (0xC0u)
    #define Driver1_ZERO_14CHAR        ((uint16)0xDBC0u)
    #define Driver1_ZERO_16CHAR        ((uint16)0x6F00u)
#endif /* (Driver1_SEG_DRIVE == Driver1_HIGH) */

/* Shifts and 4-bit operation mask */
#define Driver1_SHIFT_NIBBLE           (0x04u)
#define Driver1_NIBBLE_MASK            (0x0Fu)
#define Driver1_SHIFT_BYTE             (0x08u)

/* ASCII table access defines */
#define Driver1_SEG_ASCII_OFFSET       (0x02u)
#define Driver1_SEG_ASCII_LIM_HI       (0x08u)
#define Driver1_SEG_ASCII_LIM_LO       (0x01u)

/* Decimal point defines */
#define Driver1_DEC_POINT              (0x07u)
#define Driver1_DEC_POINT_MASK         (0x01u)
#if(Driver1_SEG_DRIVE == Driver1_HIGH)
    #define Driver1_DEC_POINT_VALUE    (0x80u)
#else
    #define Driver1_DEC_POINT_VALUE    (0x7Fu)
#endif /* (Driver1_SEG_DRIVE == Driver1_HIGH) */

/* 7-seg position to register mapping defines */
#define Driver1_SEG_REG_LOW            (0x00u)
#define Driver1_SEG_REG_MID            (0x01u)
#define Driver1_SEG_REG_HIGH           (0x02u)

/* Segment display alignment defines */
#define Driver1_RIGHT_ALIGN            (0x00u)
#define Driver1_LEFT_ALIGN             (0x01u)
#define Driver1_ZERO_PAD               (0x02u)


/***************************************
*           Registers
***************************************/
#define Driver1_CONTROL_REG_BASE       (CYDEV_PERIPH_BASE)
#define Driver1_SRAM_BASE              (CYDEV_SRAM_BASE)

#define Driver1_COM_CONTROL_PTR        (Driver1_Com_Driver_Control_PTR)
#define Driver1_SEG_L_CONTROL_PTR      (Driver1_Seg_Driver_L_Control_PTR)

#if (Driver1_NUM_SEG > 8u)
    #define Driver1_SEG_M_CONTROL_PTR  (Driver1_Seg_Driver_M_Control_PTR)
#endif /* (Driver1_NUM_SEG > 8u) */
#if (Driver1_NUM_SEG > 16u)
    #define Driver1_SEG_H_CONTROL_PTR  (Driver1_Seg_Driver_H_Control_PTR)
#endif /* (Driver1_NUM_SEG > 16u) */


/***************************************
*           UDB PWM Registers
***************************************/
/* Control register */
#define Driver1_CONTROL_REG            (*(reg8 *) Driver1_bLED_PWM_CtlReg__CONTROL_REG)
#define Driver1_CONTROL_PTR            ( (reg8 *) Driver1_bLED_PWM_CtlReg__CONTROL_REG)

/* Counter register */
#define Driver1_COUNTER_REG            (*(reg8 *) Driver1_bLED_PWM_PwmDP_u0__A1_REG)
#define Driver1_COUNTER_PTR            ((reg8 *) Driver1_bLED_PWM_PwmDP_u0__A1_REG)
/* Compare value buffer */
#define Driver1_COMPARE_REG            (*(reg8 *) Driver1_bLED_PWM_PwmDP_u0__D0_REG)
#define Driver1_COMPARE_PTR            ((reg8 *) Driver1_bLED_PWM_PwmDP_u0__D0_REG)


/***************************************
*          Register Constants
***************************************/
/* Control Register Enable/Disable. Also use for Driver1_enableVar */
#define Driver1_CTRL_ENABLE            (0x01u)
#define Driver1_CTRL_DISABLE           (0x00u)

#endif /* CY_LED_Driver_Driver1_H Header File */


/* [] END OF FILE */
