/*******************************************************************************
* File Name: Driver2_PM.c
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

#include "Driver2.h"
static Driver2_backupStruct Driver2_backup;


/*******************************************************************************
* Function Name: Driver2_Sleep
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
void Driver2_Sleep(void) 
{
    uint8 i;
    
    /* Store the component enable state */
    Driver2_backup.ledEnableState = Driver2_enableVar;
    
    /* Save the segment buffers */
    for(i = 0u; i < Driver2_NUM_COM; i++)
    {
        Driver2_backup.segLBackup[i] = Driver2_segLBuffer[i];
        #if (Driver2_NUM_SEG > 8u) 
            Driver2_backup.segMBackup[i] = Driver2_segMBuffer[i];
        #endif /* (Driver2_NUM_SEG > 8u) */
        #if (Driver2_NUM_SEG > 16u) 
            Driver2_backup.segHBackup[i] = Driver2_segHBuffer[i];
        #endif /* (Driver2_NUM_SEG > 16u) */
    }
    
    Driver2_Stop();
}


/*******************************************************************************
* Function Name: Driver2_Wakeup
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
void Driver2_Wakeup(void) 
{
    uint8 i;
    
    /* Restore the segment buffers */
    for(i = 0u; i < Driver2_NUM_COM; i++)
    {
        Driver2_segLBuffer[i] = Driver2_backup.segLBackup[i];
        #if (Driver2_NUM_SEG > 8u) 
            Driver2_segMBuffer[i] = Driver2_backup.segMBackup[i];
        #endif /* (Driver2_NUM_SEG > 8u) */
        #if (Driver2_NUM_SEG > 16u) 
            Driver2_segHBuffer[i] = Driver2_backup.segHBackup[i];
        #endif /* (Driver2_NUM_SEG > 16u) */
    }
    
    if(Driver2_backup.ledEnableState == Driver2_ENABLED)
    {
        /* Enable the component */
        Driver2_Enable();
    }
}


/* [] END OF FILE */

