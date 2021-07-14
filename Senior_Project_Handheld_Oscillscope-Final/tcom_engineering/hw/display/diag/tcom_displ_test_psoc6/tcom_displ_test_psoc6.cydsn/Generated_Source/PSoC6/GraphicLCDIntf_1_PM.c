/*******************************************************************************
* File Name: GraphicLCDIntf_1_PM.c
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

#include "GraphicLCDIntf_1.h" 


/*******************************************************************************
* Function Name: GraphicLCDIntf_1_SaveConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to save here.
*
*******************************************************************************/
void GraphicLCDIntf_1_SaveConfig(void) 
{   
    
}


/*******************************************************************************
* Function Name: GraphicLCDIntf_1_RestoreConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to restore here.
*
*******************************************************************************/
void GraphicLCDIntf_1_RestoreConfig(void) 
{    
    
}


/*******************************************************************************
* Function Name: GraphicLCDIntf_1_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves its configuration. Should be called 
*  prior to entering Sleep.
*
*******************************************************************************/
void GraphicLCDIntf_1_Sleep(void) 
{
    GraphicLCDIntf_1_Stop();
}


/*******************************************************************************
* Function Name: GraphicLCDIntf_1_Wakeup
********************************************************************************
*
* Summary:
*  Enables block's operation and restores its configuration. Should be called
*  after awaking from Sleep.
*
*******************************************************************************/
void GraphicLCDIntf_1_Wakeup(void) 
{
    GraphicLCDIntf_1_Enable();
}


/* [] END OF FILE */

