/*******************************************************************************
* File Name: DISP_TICK_TIMER.c
* Version 1.0
*
* Description:
*  This file provides the source code to the API for the DISP_TICK_TIMER
*  component
*
********************************************************************************
* Copyright 2016-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "DISP_TICK_TIMER.h"

/** Indicates whether or not the DISP_TICK_TIMER has been initialized. 
*  The variable is initialized to 0 and set to 1 the first time 
*  DISP_TICK_TIMER_Start() is called. This allows the Component to 
*  restart without reinitialization after the first call to 
*  the DISP_TICK_TIMER_Start() routine.
*/
uint8_t DISP_TICK_TIMER_initVar = 0U;

/** The instance-specific configuration structure. This should be used in the 
*  associated DISP_TICK_TIMER_Init() function.
*/ 
cy_stc_tcpwm_counter_config_t const DISP_TICK_TIMER_config =
{
        .period = 999UL,
        .clockPrescaler = 0UL,
        .runMode = 0UL,
        .countDirection = 1UL,
        .compareOrCapture = 2UL,
        .compare0 = 16384UL,
        .compare1 = 16384UL,
        .enableCompareSwap = false,
        .interruptSources = 1UL,
        .captureInputMode = 3UL,
        .captureInput = CY_TCPWM_INPUT_CREATOR,
        .reloadInputMode = 3UL,
        .reloadInput = CY_TCPWM_INPUT_CREATOR,
        .startInputMode = 3UL,
        .startInput = CY_TCPWM_INPUT_CREATOR,
        .stopInputMode = 3UL,
        .stopInput = CY_TCPWM_INPUT_CREATOR,
        .countInputMode = 3UL,
        .countInput = CY_TCPWM_INPUT_CREATOR,
};


/*******************************************************************************
* Function Name: DISP_TICK_TIMER_Start
****************************************************************************//**
*
*  Calls the DISP_TICK_TIMER_Init() when called the first time and enables 
*  the DISP_TICK_TIMER. For subsequent calls the configuration is left 
*  unchanged and the component is just enabled.
*
* \globalvars
*  \ref DISP_TICK_TIMER_initVar
*
*******************************************************************************/
void DISP_TICK_TIMER_Start(void)
{
    if (0U == DISP_TICK_TIMER_initVar)
    {
        (void)Cy_TCPWM_Counter_Init(DISP_TICK_TIMER_HW, DISP_TICK_TIMER_CNT_NUM, &DISP_TICK_TIMER_config); 

        DISP_TICK_TIMER_initVar = 1U;
    }

    Cy_TCPWM_Enable_Multiple(DISP_TICK_TIMER_HW, DISP_TICK_TIMER_CNT_MASK);
    
    #if (DISP_TICK_TIMER_INPUT_DISABLED == 7UL)
        Cy_TCPWM_TriggerStart(DISP_TICK_TIMER_HW, DISP_TICK_TIMER_CNT_MASK);
    #endif /* (DISP_TICK_TIMER_INPUT_DISABLED == 7UL) */    
}


/* [] END OF FILE */
