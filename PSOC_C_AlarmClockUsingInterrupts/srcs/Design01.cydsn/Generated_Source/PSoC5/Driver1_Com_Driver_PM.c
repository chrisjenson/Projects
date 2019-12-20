/*******************************************************************************
* File Name: Driver1_Com_Driver_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Driver1_Com_Driver.h"

/* Check for removal by optimization */
#if !defined(Driver1_Com_Driver_Sync_ctrl_reg__REMOVED)

static Driver1_Com_Driver_BACKUP_STRUCT  Driver1_Com_Driver_backup = {0u};

    
/*******************************************************************************
* Function Name: Driver1_Com_Driver_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Driver1_Com_Driver_SaveConfig(void) 
{
    Driver1_Com_Driver_backup.controlState = Driver1_Com_Driver_Control;
}


/*******************************************************************************
* Function Name: Driver1_Com_Driver_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void Driver1_Com_Driver_RestoreConfig(void) 
{
     Driver1_Com_Driver_Control = Driver1_Com_Driver_backup.controlState;
}


/*******************************************************************************
* Function Name: Driver1_Com_Driver_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Driver1_Com_Driver_Sleep(void) 
{
    Driver1_Com_Driver_SaveConfig();
}


/*******************************************************************************
* Function Name: Driver1_Com_Driver_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Driver1_Com_Driver_Wakeup(void)  
{
    Driver1_Com_Driver_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
