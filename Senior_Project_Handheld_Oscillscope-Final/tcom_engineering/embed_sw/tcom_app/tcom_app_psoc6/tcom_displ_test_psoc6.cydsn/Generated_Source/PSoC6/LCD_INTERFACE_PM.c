/*******************************************************************************
* File Name: LCD_INTERFACE_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control and status commands to support 
*  the component operations in Low-power mode.  
*
********************************************************************************
* Copyright 2008-2018, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "LCD_INTERFACE.h" 


/*******************************************************************************
* Function Name: LCD_INTERFACE_SaveConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to save here.
*
*******************************************************************************/
void LCD_INTERFACE_SaveConfig(void) 
{   
    
}


/*******************************************************************************
* Function Name: LCD_INTERFACE_RestoreConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to restore here.
*
*******************************************************************************/
void LCD_INTERFACE_RestoreConfig(void) 
{    
    
}


/*******************************************************************************
* Function Name: LCD_INTERFACE_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves its configuration. Should be called 
*  prior to entering Sleep.
*
*******************************************************************************/
void LCD_INTERFACE_Sleep(void) 
{
    LCD_INTERFACE_Stop();
}


/*******************************************************************************
* Function Name: LCD_INTERFACE_Wakeup
********************************************************************************
*
* Summary:
*  Enables block's operation and restores its configuration. Should be called
*  after awaking from Sleep.
*
*******************************************************************************/
void LCD_INTERFACE_Wakeup(void) 
{
    LCD_INTERFACE_Enable();
}


/* [] END OF FILE */

