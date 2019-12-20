/*******************************************************************************
* File Name: Driver_PM.c
* Version 1.10
*
* Description:
*  This file provides the power management source code to API for the
*  LED_Driver component.
*
* Note:
*  None
*
*******************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "Driver.h"
static Driver_backupStruct Driver_backup;


/*******************************************************************************
* Function Name: Driver_Sleep
********************************************************************************
*
* Summary:
*  Stop and Save the user configuration
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Driver_Sleep(void) 
{
    uint8 i;
    
    /* Store the component enable state */
    Driver_backup.ledEnableState = Driver_enableVar;
    
    /* Save the segment buffers */
    for(i = 0u; i < Driver_NUM_COM; i++)
    {
        Driver_backup.segLBackup[i] = Driver_segLBuffer[i];
        #if (Driver_NUM_SEG > 8u) 
            Driver_backup.segMBackup[i] = Driver_segMBuffer[i];
        #endif /* (Driver_NUM_SEG > 8u) */
        #if (Driver_NUM_SEG > 16u) 
            Driver_backup.segHBackup[i] = Driver_segHBuffer[i];
        #endif /* (Driver_NUM_SEG > 16u) */
    }
    
    Driver_Stop();
}


/*******************************************************************************
* Function Name: Driver_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Driver_Wakeup(void) 
{
    uint8 i;
    
    /* Restore the segment buffers */
    for(i = 0u; i < Driver_NUM_COM; i++)
    {
        Driver_segLBuffer[i] = Driver_backup.segLBackup[i];
        #if (Driver_NUM_SEG > 8u) 
            Driver_segMBuffer[i] = Driver_backup.segMBackup[i];
        #endif /* (Driver_NUM_SEG > 8u) */
        #if (Driver_NUM_SEG > 16u) 
            Driver_segHBuffer[i] = Driver_backup.segHBackup[i];
        #endif /* (Driver_NUM_SEG > 16u) */
    }
    
    if(Driver_backup.ledEnableState == Driver_ENABLED)
    {
        /* Enable the component */
        Driver_Enable();
    }
}


/* [] END OF FILE */

