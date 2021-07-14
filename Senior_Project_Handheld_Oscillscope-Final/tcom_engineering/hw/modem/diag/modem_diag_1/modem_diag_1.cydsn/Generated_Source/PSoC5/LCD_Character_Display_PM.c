/*******************************************************************************
* File Name: LCD_Character_Display_PM.c
* Version 2.20
*
* Description:
*  This file provides the API source code for the Static Segment LCD component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "LCD_Character_Display.h"


static LCD_Character_Display_BACKUP_STRUCT LCD_Character_Display_backup;


/*******************************************************************************
* Function Name: LCD_Character_Display_SaveConfig
********************************************************************************
*
* Summary:
*  Does nothing, provided for consistency.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void LCD_Character_Display_SaveConfig(void) 
{
}


/*******************************************************************************
* Function Name: LCD_Character_Display_RestoreConfig
********************************************************************************
*
* Summary:
*  Does nothing, provided for consistency.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void LCD_Character_Display_RestoreConfig(void) 
{
}


/*******************************************************************************
* Function Name: LCD_Character_Display_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the sleep mode.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void LCD_Character_Display_Sleep(void) 
{
    LCD_Character_Display_backup.enableState = LCD_Character_Display_enableState;
    LCD_Character_Display_SaveConfig();
    LCD_Character_Display_Stop();
}


/*******************************************************************************
* Function Name: LCD_Character_Display_Wakeup
********************************************************************************
*
* Summary:
*  Wakes the component from sleep mode. Configures DMA and enables the component
*  for normal operation.
*
* Parameters:
*  LCD_Character_Display_enableState - Global variable.
*
* Return:
*  Status one of standard status for PSoC3 Component
*       CYRET_SUCCESS - Function completed successfully.
*       CYRET_LOCKED - The object was locked, already in use. Some of TDs or
*                      a channel already in use.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void LCD_Character_Display_Wakeup(void) 
{
    LCD_Character_Display_RestoreConfig();

    if(LCD_Character_Display_backup.enableState == 1u)
    {
        LCD_Character_Display_Enable();
    }
}


/* [] END OF FILE */
