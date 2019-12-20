/*******************************************************************************
* File Name: Driver3_PM.c
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

#include "Driver3.h"
static Driver3_backupStruct Driver3_backup;


/*******************************************************************************
* Function Name: Driver3_Sleep
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
void Driver3_Sleep(void) 
{
    uint8 i;
    
    /* Store the component enable state */
    Driver3_backup.ledEnableState = Driver3_enableVar;
    
    /* Save the segment buffers */
    for(i = 0u; i < Driver3_NUM_COM; i++)
    {
        Driver3_backup.segLBackup[i] = Driver3_segLBuffer[i];
        #if (Driver3_NUM_SEG > 8u) 
            Driver3_backup.segMBackup[i] = Driver3_segMBuffer[i];
        #endif /* (Driver3_NUM_SEG > 8u) */
        #if (Driver3_NUM_SEG > 16u) 
            Driver3_backup.segHBackup[i] = Driver3_segHBuffer[i];
        #endif /* (Driver3_NUM_SEG > 16u) */
    }
    
    Driver3_Stop();
}


/*******************************************************************************
* Function Name: Driver3_Wakeup
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
void Driver3_Wakeup(void) 
{
    uint8 i;
    
    /* Restore the segment buffers */
    for(i = 0u; i < Driver3_NUM_COM; i++)
    {
        Driver3_segLBuffer[i] = Driver3_backup.segLBackup[i];
        #if (Driver3_NUM_SEG > 8u) 
            Driver3_segMBuffer[i] = Driver3_backup.segMBackup[i];
        #endif /* (Driver3_NUM_SEG > 8u) */
        #if (Driver3_NUM_SEG > 16u) 
            Driver3_segHBuffer[i] = Driver3_backup.segHBackup[i];
        #endif /* (Driver3_NUM_SEG > 16u) */
    }
    
    if(Driver3_backup.ledEnableState == Driver3_ENABLED)
    {
        /* Enable the component */
        Driver3_Enable();
    }
}


/* [] END OF FILE */

