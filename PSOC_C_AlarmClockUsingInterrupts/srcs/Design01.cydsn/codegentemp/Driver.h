/*******************************************************************************
* File Name: Driver.h
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

#if !defined(CY_LED_Driver_Driver_H)
#define CY_LED_Driver_Driver_H


/***************************************
*   Conditional Compilation Parameters
***************************************/
#define Driver_BRIGHTNESS_EN                (0u)
#define Driver_COM_DRIVE                    (0u)
#define Driver_SEG_DRIVE                    (0u)
#define Driver_NUM_COM                      (4u)
#define Driver_NUM_SEG                      (8u)
#define Driver_TWO_NUM_COM                  ((uint8)((uint8)Driver_NUM_COM << 1u))

/* Error message for removed commons control register through optimization */
#ifdef Driver_Com_Driver_Sync_ctrl_reg__REMOVED
    #error LED_Driver_v1_10 requires all the signals from the commons terminal to be connected to pins.
#endif /* Driver_Com_Driver_Sync_ctrl_reg__REMOVED */

/* Error message for removed segments control registers through optimization */
#if defined Driver_Seg_Driver_L_Sync_ctrl_reg__REMOVED || \
defined Driver_Seg_Driver_M_Sync_ctrl_reg__REMOVED || \
defined Driver_Seg_Driver_H_Sync_ctrl_reg__REMOVED
    #error LED_Driver_v1_10 requires all the signals from the segments terminal to be connected to pins.
#endif /* Driver_Seg_Driver_L_Sync_ctrl_reg__REMOVED */


/***************************************
*   Header files
***************************************/
#include <Driver_Com_Driver.h>
#include <Driver_Seg_Driver_L.h>
#if (Driver_NUM_SEG > 8u)
    #include <Driver_Seg_Driver_M.h>
#endif /* Segment_M control register */
#if (Driver_NUM_SEG > 16u)
    #include <Driver_Seg_Driver_H.h>
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
    uint8 segLBackup[Driver_NUM_COM];
    #if (Driver_NUM_SEG > 8u) 
        uint8 segMBackup[Driver_NUM_COM];
    #endif /* (Driver_NUM_SEG > 8u) */
    #if (Driver_NUM_SEG > 16u) 
        uint8 segHBackup[Driver_NUM_COM];
    #endif /* (Driver_NUM_SEG > 16u) */
}Driver_backupStruct;


/***************************************
*        Function Prototypes
***************************************/
void Driver_Init(void)                       ;
void Driver_Enable(void)                     ;
void Driver_Start(void)                      ;
void Driver_Stop(void)                       ;
void Driver_SetDisplayRAM(uint8 value, uint8 position) 
                                                        ;
void Driver_SetRC(uint8 row, uint8 column)    ;
void Driver_ClearRC(uint8 row, uint8 column)  ;
void Driver_ToggleRC(uint8 row, uint8 column) ;
uint8 Driver_GetRC(uint8 row, uint8 column)   ;
void Driver_ClearDisplay(uint8 position)      ;
void Driver_ClearDisplayAll(void)             ;
void Driver_Write7SegNumberDec(int32 number, uint8 position, uint8 digits, uint8 alignment)
                                                        ;
void Driver_Write7SegNumberHex(uint32 number, uint8 position, uint8 digits, uint8 alignment)
                                                        ;
void Driver_WriteString7Seg(char8 const character[], uint8 position)
                                                        ;
void Driver_PutChar7Seg(char8 character , uint8 position)
                                                        ;
void Driver_Write7SegDigitDec(uint8 digit, uint8 position)
                                                        ;
void Driver_Write7SegDigitHex(uint8 digit, uint8 position)
                                                        ;
void Driver_Write14SegNumberDec(int32 number, uint8 position, uint8 digits, uint8 alignment)
                                                        ;
void Driver_Write14SegNumberHex(uint32 number, uint8 position, uint8 digits, uint8 alignment)
                                                        ;
void Driver_WriteString14Seg(char8 const character[], uint8 position)
                                                        ;
void Driver_PutChar14Seg(char8 character , uint8 position)
                                                        ;
void Driver_Write14SegDigitDec(uint8 digit, uint8 position)
                                                        ;
void Driver_Write14SegDigitHex(uint8 digit, uint8 position)
                                                        ;
void Driver_Write16SegNumberDec(int32 number, uint8 position, uint8 digits, uint8 alignment)
                                                        ;
void Driver_Write16SegNumberHex(uint32 number, uint8 position, uint8 digits, uint8 alignment)
                                                        ;
void Driver_WriteString16Seg(char8 const character[], uint8 position)
                                                        ;
void Driver_PutChar16Seg(char8 character , uint8 position)
                                                        ;
void Driver_Write16SegDigitDec(uint8 digit, uint8 position)
                                                        ;
void Driver_Write16SegDigitHex(uint8 digit, uint8 position)
                                                        ;
void Driver_PutDecimalPoint(uint8 dp, uint8 position)
                                                        ;
uint8 Driver_GetDecimalPoint(uint8 position)  ;
uint8 Driver_EncodeNumber7Seg(uint8 number)   ;
uint8 Driver_EncodeChar7Seg(char8 input)      ;
uint16 Driver_EncodeNumber14Seg(uint8 number) ;
uint16 Driver_EncodeChar14Seg(char8 input)    ;
uint16 Driver_EncodeNumber16Seg(uint8 number) ;
uint16 Driver_EncodeChar16Seg(char8 input)    ;
void Driver_SetBrightness(uint8 bright, uint8 position)
                                                        ;
uint8 Driver_GetBrightness(uint8 position)    ;
void Driver_Sleep(void)                       ;
void Driver_Wakeup(void)                      ;


/***************************************
*           Global Variables
***************************************/
extern uint8 Driver_initVar;
extern uint8 Driver_enableVar;

/* Buffers used to hold the display(segment) values to be transferred to the control registers */
extern uint8 Driver_segLBuffer[Driver_NUM_COM];
#if (Driver_NUM_SEG > 8u) 
    extern uint8 Driver_segMBuffer[Driver_NUM_COM];
#endif /* (Driver_NUM_SEG > 8u) */
#if (Driver_NUM_SEG > 16u) 
    extern uint8 Driver_segHBuffer[Driver_NUM_COM];
#endif /* (Driver_NUM_SEG > 16u) */


/***************************************
*           API Constants
***************************************/

/* Related to conditional compilation */
#define Driver_HIGH                   (0x01u)
#define Driver_ENABLED                (0x01u)

/* Number of DMA channels */
#if (Driver_BRIGHTNESS_EN == Driver_ENABLED)
    #define Driver_CHANNEL_LIMIT      (0x03u)
#else
    #define Driver_CHANNEL_LIMIT      (0x02u)
#endif /* (Driver_BRIGHTNESS_EN == Driver_ENABLED) */

/* Defines related to sign extraction for number displays */
#define Driver_SIGNED                 (0x01u)
#define Driver_UNSIGNED               (0x00u)
#define Driver_ZERO_NEG               ((int32)0x00000000)

/* Brightness control defines */
#define Driver_INIT_BRIGHT            (0xFFu)

/* Segment display defines */
#if(Driver_SEG_DRIVE == Driver_HIGH)
    #define Driver_CLEAR              (0x00u)
    #define Driver_CLEAR_16           ((uint16)0x0000u)
    #define Driver_ZERO_7CHAR         (0x3Fu)
    #define Driver_ZERO_14CHAR        ((uint16)0x243Fu)
    #define Driver_ZERO_16CHAR        ((uint16)0x90FFu)
#else
    #define Driver_CLEAR              (0xFFu)
    #define Driver_CLEAR_16           ((uint16)0xFFFFu)
    #define Driver_ZERO_7CHAR         (0xC0u)
    #define Driver_ZERO_14CHAR        ((uint16)0xDBC0u)
    #define Driver_ZERO_16CHAR        ((uint16)0x6F00u)
#endif /* (Driver_SEG_DRIVE == Driver_HIGH) */

/* Shifts and 4-bit operation mask */
#define Driver_SHIFT_NIBBLE           (0x04u)
#define Driver_NIBBLE_MASK            (0x0Fu)
#define Driver_SHIFT_BYTE             (0x08u)

/* ASCII table access defines */
#define Driver_SEG_ASCII_OFFSET       (0x02u)
#define Driver_SEG_ASCII_LIM_HI       (0x08u)
#define Driver_SEG_ASCII_LIM_LO       (0x01u)

/* Decimal point defines */
#define Driver_DEC_POINT              (0x07u)
#define Driver_DEC_POINT_MASK         (0x01u)
#if(Driver_SEG_DRIVE == Driver_HIGH)
    #define Driver_DEC_POINT_VALUE    (0x80u)
#else
    #define Driver_DEC_POINT_VALUE    (0x7Fu)
#endif /* (Driver_SEG_DRIVE == Driver_HIGH) */

/* 7-seg position to register mapping defines */
#define Driver_SEG_REG_LOW            (0x00u)
#define Driver_SEG_REG_MID            (0x01u)
#define Driver_SEG_REG_HIGH           (0x02u)

/* Segment display alignment defines */
#define Driver_RIGHT_ALIGN            (0x00u)
#define Driver_LEFT_ALIGN             (0x01u)
#define Driver_ZERO_PAD               (0x02u)


/***************************************
*           Registers
***************************************/
#define Driver_CONTROL_REG_BASE       (CYDEV_PERIPH_BASE)
#define Driver_SRAM_BASE              (CYDEV_SRAM_BASE)

#define Driver_COM_CONTROL_PTR        (Driver_Com_Driver_Control_PTR)
#define Driver_SEG_L_CONTROL_PTR      (Driver_Seg_Driver_L_Control_PTR)

#if (Driver_NUM_SEG > 8u)
    #define Driver_SEG_M_CONTROL_PTR  (Driver_Seg_Driver_M_Control_PTR)
#endif /* (Driver_NUM_SEG > 8u) */
#if (Driver_NUM_SEG > 16u)
    #define Driver_SEG_H_CONTROL_PTR  (Driver_Seg_Driver_H_Control_PTR)
#endif /* (Driver_NUM_SEG > 16u) */


/***************************************
*           UDB PWM Registers
***************************************/
/* Control register */
#define Driver_CONTROL_REG            (*(reg8 *) Driver_bLED_PWM_CtlReg__CONTROL_REG)
#define Driver_CONTROL_PTR            ( (reg8 *) Driver_bLED_PWM_CtlReg__CONTROL_REG)

/* Counter register */
#define Driver_COUNTER_REG            (*(reg8 *) Driver_bLED_PWM_PwmDP_u0__A1_REG)
#define Driver_COUNTER_PTR            ((reg8 *) Driver_bLED_PWM_PwmDP_u0__A1_REG)
/* Compare value buffer */
#define Driver_COMPARE_REG            (*(reg8 *) Driver_bLED_PWM_PwmDP_u0__D0_REG)
#define Driver_COMPARE_PTR            ((reg8 *) Driver_bLED_PWM_PwmDP_u0__D0_REG)


/***************************************
*          Register Constants
***************************************/
/* Control Register Enable/Disable. Also use for Driver_enableVar */
#define Driver_CTRL_ENABLE            (0x01u)
#define Driver_CTRL_DISABLE           (0x00u)

#endif /* CY_LED_Driver_Driver_H Header File */


/* [] END OF FILE */
