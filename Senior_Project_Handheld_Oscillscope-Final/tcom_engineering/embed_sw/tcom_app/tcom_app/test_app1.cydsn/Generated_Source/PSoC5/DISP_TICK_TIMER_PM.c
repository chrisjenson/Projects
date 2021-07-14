/*******************************************************************************
* File Name: DISP_TICK_TIMER_PM.c
* Version 2.80
*
*  Description:
*     This file provides the power management source code to API for the
*     Timer.
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "DISP_TICK_TIMER.h"

static DISP_TICK_TIMER_backupStruct DISP_TICK_TIMER_backup;


/*******************************************************************************
* Function Name: DISP_TICK_TIMER_SaveConfig
********************************************************************************
*
* Summary:
*     Save the current user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  DISP_TICK_TIMER_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void DISP_TICK_TIMER_SaveConfig(void) 
{
    #if (!DISP_TICK_TIMER_UsingFixedFunction)
        DISP_TICK_TIMER_backup.TimerUdb = DISP_TICK_TIMER_ReadCounter();
        DISP_TICK_TIMER_backup.InterruptMaskValue = DISP_TICK_TIMER_STATUS_MASK;
        #if (DISP_TICK_TIMER_UsingHWCaptureCounter)
            DISP_TICK_TIMER_backup.TimerCaptureCounter = DISP_TICK_TIMER_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!DISP_TICK_TIMER_UDB_CONTROL_REG_REMOVED)
            DISP_TICK_TIMER_backup.TimerControlRegister = DISP_TICK_TIMER_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: DISP_TICK_TIMER_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  DISP_TICK_TIMER_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void DISP_TICK_TIMER_RestoreConfig(void) 
{   
    #if (!DISP_TICK_TIMER_UsingFixedFunction)

        DISP_TICK_TIMER_WriteCounter(DISP_TICK_TIMER_backup.TimerUdb);
        DISP_TICK_TIMER_STATUS_MASK =DISP_TICK_TIMER_backup.InterruptMaskValue;
        #if (DISP_TICK_TIMER_UsingHWCaptureCounter)
            DISP_TICK_TIMER_SetCaptureCount(DISP_TICK_TIMER_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!DISP_TICK_TIMER_UDB_CONTROL_REG_REMOVED)
            DISP_TICK_TIMER_WriteControlRegister(DISP_TICK_TIMER_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: DISP_TICK_TIMER_Sleep
********************************************************************************
*
* Summary:
*     Stop and Save the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  DISP_TICK_TIMER_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void DISP_TICK_TIMER_Sleep(void) 
{
    #if(!DISP_TICK_TIMER_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(DISP_TICK_TIMER_CTRL_ENABLE == (DISP_TICK_TIMER_CONTROL & DISP_TICK_TIMER_CTRL_ENABLE))
        {
            /* Timer is enabled */
            DISP_TICK_TIMER_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            DISP_TICK_TIMER_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    DISP_TICK_TIMER_Stop();
    DISP_TICK_TIMER_SaveConfig();
}


/*******************************************************************************
* Function Name: DISP_TICK_TIMER_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  DISP_TICK_TIMER_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void DISP_TICK_TIMER_Wakeup(void) 
{
    DISP_TICK_TIMER_RestoreConfig();
    #if(!DISP_TICK_TIMER_UDB_CONTROL_REG_REMOVED)
        if(DISP_TICK_TIMER_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                DISP_TICK_TIMER_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
