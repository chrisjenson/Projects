/*******************************************************************************
* File Name: Driver1_PM.c
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

#include "Driver1.h"
static Driver1_backupStruct Driver1_backup;


/*******************************************************************************
* Function Name: Driver1_Sleep
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
void Driver1_Sleep(void) 
{
    uint8 i;
    
    /* Store the component enable state */
    Driver1_backup.ledEnableState = Driver1_enableVar;
    
    /* Save the segment buffers */
    for(i = 0u; i < Driver1_NUM_COM; i++)
    {
        Driver1_backup.segLBackup[i] = Driver1_segLBuffer[i];
        #if (Driver1_NUM_SEG > 8u) 
            Driver1_backup.segMBackup[i] = Driver1_segMBuffer[i];
        #endif /* (Driver1_NUM_SEG > 8u) */
        #if (Driver1_NUM_SEG > 16u) 
            Driver1_backup.segHBackup[i] = Driver1_segHBuffer[i];
        #endif /* (Driver1_NUM_SEG > 16u) */
    }
    
    Driver1_Stop();
}


/*******************************************************************************
* Function Name: Driver1_Wakeup
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
void Driver1_Wakeup(void) 
{
    uint8 i;
    
    /* Restore the segment buffers */
    for(i = 0u; i < Driver1_NUM_COM; i++)
    {
        Driver1_segLBuffer[i] = Driver1_backup.segLBackup[i];
        #if (Driver1_NUM_SEG > 8u) 
            Driver1_segMBuffer[i] = Driver1_backup.segMBackup[i];
        #endif /* (Driver1_NUM_SEG > 8u) */
        #if (Driver1_NUM_SEG > 16u) 
            Driver1_segHBuffer[i] = Driver1_backup.segHBackup[i];
        #endif /* (Driver1_NUM_SEG > 16u) */
    }
    
    if(Driver1_backup.ledEnableState == Driver1_ENABLED)
    {
        /* Enable the component */
        Driver1_Enable();
    }
}


/* [] END OF FILE */

