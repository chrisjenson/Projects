/*******************************************************************************
* File Name: DISP_TICK_TIMER.h
* Version 1.0
*
* Description:
*  This file provides constants and parameter values for the DISP_TICK_TIMER
*  component.
*
********************************************************************************
* Copyright 2016-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(DISP_TICK_TIMER_CY_TCPWM_COUNTER_PDL_H)
#define DISP_TICK_TIMER_CY_TCPWM_COUNTER_PDL_H

#include "cyfitter.h"
#include "tcpwm/cy_tcpwm_counter.h"

   
/*******************************************************************************
* Variables
*******************************************************************************/
/**
* \addtogroup group_globals
* @{
*/
extern uint8_t  DISP_TICK_TIMER_initVar;
extern cy_stc_tcpwm_counter_config_t const DISP_TICK_TIMER_config;
/** @} group_globals */


/***************************************
*  Conditional Compilation Parameters
***************************************/

#define DISP_TICK_TIMER_INIT_COMPARE_OR_CAPTURE    (2UL)


/***************************************
*        Function Prototypes
****************************************/
/**
* \addtogroup group_general
* @{
*/
void DISP_TICK_TIMER_Start(void);
__STATIC_INLINE cy_en_tcpwm_status_t DISP_TICK_TIMER_Init(cy_stc_tcpwm_counter_config_t const *config);
__STATIC_INLINE void DISP_TICK_TIMER_DeInit(void);
__STATIC_INLINE void DISP_TICK_TIMER_Enable(void);
__STATIC_INLINE void DISP_TICK_TIMER_Disable(void);
__STATIC_INLINE uint32_t DISP_TICK_TIMER_GetStatus(void);

#if(CY_TCPWM_COUNTER_MODE_CAPTURE == DISP_TICK_TIMER_INIT_COMPARE_OR_CAPTURE)
    __STATIC_INLINE uint32_t DISP_TICK_TIMER_GetCapture(void);
    __STATIC_INLINE uint32_t DISP_TICK_TIMER_GetCaptureBuf(void);
#else
    __STATIC_INLINE void DISP_TICK_TIMER_SetCompare0(uint32_t compare0);
    __STATIC_INLINE uint32_t DISP_TICK_TIMER_GetCompare0(void);
    __STATIC_INLINE void DISP_TICK_TIMER_SetCompare1(uint32_t compare1);
    __STATIC_INLINE uint32_t DISP_TICK_TIMER_GetCompare1(void);
    __STATIC_INLINE void DISP_TICK_TIMER_EnableCompareSwap(bool enable);
#endif /* (CY_TCPWM_COUNTER_MODE_CAPTURE == DISP_TICK_TIMER_INIT_COMPARE_OR_CAPTURE) */

__STATIC_INLINE void DISP_TICK_TIMER_SetCounter(uint32_t count);
__STATIC_INLINE uint32_t DISP_TICK_TIMER_GetCounter(void);
__STATIC_INLINE void DISP_TICK_TIMER_SetPeriod(uint32_t period);
__STATIC_INLINE uint32_t DISP_TICK_TIMER_GetPeriod(void);
__STATIC_INLINE void DISP_TICK_TIMER_TriggerStart(void);
__STATIC_INLINE void DISP_TICK_TIMER_TriggerReload(void);
__STATIC_INLINE void DISP_TICK_TIMER_TriggerStop(void);
__STATIC_INLINE void DISP_TICK_TIMER_TriggerCapture(void);
__STATIC_INLINE uint32_t DISP_TICK_TIMER_GetInterruptStatus(void);
__STATIC_INLINE void DISP_TICK_TIMER_ClearInterrupt(uint32_t source);
__STATIC_INLINE void DISP_TICK_TIMER_SetInterrupt(uint32_t source);
__STATIC_INLINE void DISP_TICK_TIMER_SetInterruptMask(uint32_t mask);
__STATIC_INLINE uint32_t DISP_TICK_TIMER_GetInterruptMask(void);
__STATIC_INLINE uint32_t DISP_TICK_TIMER_GetInterruptStatusMasked(void);
/** @} general */


/***************************************
*           API Constants
***************************************/

/**
* \addtogroup group_macros
* @{
*/
/** This is a ptr to the base address of the TCPWM instance */
#define DISP_TICK_TIMER_HW                 (DISP_TICK_TIMER_TCPWM__HW)

/** This is a ptr to the base address of the TCPWM CNT instance */
#define DISP_TICK_TIMER_CNT_HW             (DISP_TICK_TIMER_TCPWM__CNT_HW)

/** This is the counter instance number in the selected TCPWM */
#define DISP_TICK_TIMER_CNT_NUM            (DISP_TICK_TIMER_TCPWM__CNT_IDX)

/** This is the bit field representing the counter instance in the selected TCPWM */
#define DISP_TICK_TIMER_CNT_MASK           (1UL << DISP_TICK_TIMER_CNT_NUM)
/** @} group_macros */

#define DISP_TICK_TIMER_INPUT_MODE_MASK    (0x3U)
#define DISP_TICK_TIMER_INPUT_DISABLED     (7U)


/*******************************************************************************
* Function Name: DISP_TICK_TIMER_Init
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_Init() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE cy_en_tcpwm_status_t DISP_TICK_TIMER_Init(cy_stc_tcpwm_counter_config_t const *config)
{
    return(Cy_TCPWM_Counter_Init(DISP_TICK_TIMER_HW, DISP_TICK_TIMER_CNT_NUM, config));
}


/*******************************************************************************
* Function Name: DISP_TICK_TIMER_DeInit
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_DeInit() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void DISP_TICK_TIMER_DeInit(void)                   
{
    Cy_TCPWM_Counter_DeInit(DISP_TICK_TIMER_HW, DISP_TICK_TIMER_CNT_NUM, &DISP_TICK_TIMER_config);
}

/*******************************************************************************
* Function Name: DISP_TICK_TIMER_Enable
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Enable_Multiple() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void DISP_TICK_TIMER_Enable(void)                   
{
    Cy_TCPWM_Enable_Multiple(DISP_TICK_TIMER_HW, DISP_TICK_TIMER_CNT_MASK);
}


/*******************************************************************************
* Function Name: DISP_TICK_TIMER_Disable
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Disable_Multiple() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void DISP_TICK_TIMER_Disable(void)                  
{
    Cy_TCPWM_Disable_Multiple(DISP_TICK_TIMER_HW, DISP_TICK_TIMER_CNT_MASK);
}


/*******************************************************************************
* Function Name: DISP_TICK_TIMER_GetStatus
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_GetStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t DISP_TICK_TIMER_GetStatus(void)                
{
    return(Cy_TCPWM_Counter_GetStatus(DISP_TICK_TIMER_HW, DISP_TICK_TIMER_CNT_NUM));
}


#if(CY_TCPWM_COUNTER_MODE_CAPTURE == DISP_TICK_TIMER_INIT_COMPARE_OR_CAPTURE)
    /*******************************************************************************
    * Function Name: DISP_TICK_TIMER_GetCapture
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_GetCapture() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE uint32_t DISP_TICK_TIMER_GetCapture(void)               
    {
        return(Cy_TCPWM_Counter_GetCapture(DISP_TICK_TIMER_HW, DISP_TICK_TIMER_CNT_NUM));
    }


    /*******************************************************************************
    * Function Name: DISP_TICK_TIMER_GetCaptureBuf
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_GetCaptureBuf() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE uint32_t DISP_TICK_TIMER_GetCaptureBuf(void)            
    {
        return(Cy_TCPWM_Counter_GetCaptureBuf(DISP_TICK_TIMER_HW, DISP_TICK_TIMER_CNT_NUM));
    }
#else
    /*******************************************************************************
    * Function Name: DISP_TICK_TIMER_SetCompare0
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_SetCompare0() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE void DISP_TICK_TIMER_SetCompare0(uint32_t compare0)      
    {
        Cy_TCPWM_Counter_SetCompare0(DISP_TICK_TIMER_HW, DISP_TICK_TIMER_CNT_NUM, compare0);
    }


    /*******************************************************************************
    * Function Name: DISP_TICK_TIMER_GetCompare0
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_GetCompare0() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE uint32_t DISP_TICK_TIMER_GetCompare0(void)              
    {
        return(Cy_TCPWM_Counter_GetCompare0(DISP_TICK_TIMER_HW, DISP_TICK_TIMER_CNT_NUM));
    }


    /*******************************************************************************
    * Function Name: DISP_TICK_TIMER_SetCompare1
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_SetCompare1() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE void DISP_TICK_TIMER_SetCompare1(uint32_t compare1)      
    {
        Cy_TCPWM_Counter_SetCompare1(DISP_TICK_TIMER_HW, DISP_TICK_TIMER_CNT_NUM, compare1);
    }


    /*******************************************************************************
    * Function Name: DISP_TICK_TIMER_GetCompare1
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_GetCompare1() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE uint32_t DISP_TICK_TIMER_GetCompare1(void)              
    {
        return(Cy_TCPWM_Counter_GetCompare1(DISP_TICK_TIMER_HW, DISP_TICK_TIMER_CNT_NUM));
    }


    /*******************************************************************************
    * Function Name: DISP_TICK_TIMER_EnableCompareSwap
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_EnableCompareSwap() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE void DISP_TICK_TIMER_EnableCompareSwap(bool enable)  
    {
        Cy_TCPWM_Counter_EnableCompareSwap(DISP_TICK_TIMER_HW, DISP_TICK_TIMER_CNT_NUM, enable);
    }
#endif /* (CY_TCPWM_COUNTER_MODE_CAPTURE == DISP_TICK_TIMER_INIT_COMPARE_OR_CAPTURE) */


/*******************************************************************************
* Function Name: DISP_TICK_TIMER_SetCounter
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_SetCounter() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void DISP_TICK_TIMER_SetCounter(uint32_t count)          
{
    Cy_TCPWM_Counter_SetCounter(DISP_TICK_TIMER_HW, DISP_TICK_TIMER_CNT_NUM, count);
}


/*******************************************************************************
* Function Name: DISP_TICK_TIMER_GetCounter
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_GetCounter() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t DISP_TICK_TIMER_GetCounter(void)               
{
    return(Cy_TCPWM_Counter_GetCounter(DISP_TICK_TIMER_HW, DISP_TICK_TIMER_CNT_NUM));
}


/*******************************************************************************
* Function Name: DISP_TICK_TIMER_SetPeriod
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_SetPeriod() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void DISP_TICK_TIMER_SetPeriod(uint32_t period)          
{
    Cy_TCPWM_Counter_SetPeriod(DISP_TICK_TIMER_HW, DISP_TICK_TIMER_CNT_NUM, period);
}


/*******************************************************************************
* Function Name: DISP_TICK_TIMER_GetPeriod
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_GetPeriod() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t DISP_TICK_TIMER_GetPeriod(void)                
{
    return(Cy_TCPWM_Counter_GetPeriod(DISP_TICK_TIMER_HW, DISP_TICK_TIMER_CNT_NUM));
}


/*******************************************************************************
* Function Name: DISP_TICK_TIMER_TriggerStart
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerStart() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void DISP_TICK_TIMER_TriggerStart(void)             
{
    Cy_TCPWM_TriggerStart(DISP_TICK_TIMER_HW, DISP_TICK_TIMER_CNT_MASK);
}


/*******************************************************************************
* Function Name: DISP_TICK_TIMER_TriggerReload
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerReloadOrIndex() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void DISP_TICK_TIMER_TriggerReload(void)     
{
    Cy_TCPWM_TriggerReloadOrIndex(DISP_TICK_TIMER_HW, DISP_TICK_TIMER_CNT_MASK);
}


/*******************************************************************************
* Function Name: DISP_TICK_TIMER_TriggerStop
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerStopOrKill() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void DISP_TICK_TIMER_TriggerStop(void)
{
    Cy_TCPWM_TriggerStopOrKill(DISP_TICK_TIMER_HW, DISP_TICK_TIMER_CNT_MASK);
}


/*******************************************************************************
* Function Name: DISP_TICK_TIMER_TriggerCapture
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerCaptureOrSwap() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void DISP_TICK_TIMER_TriggerCapture(void)     
{
    Cy_TCPWM_TriggerCaptureOrSwap(DISP_TICK_TIMER_HW, DISP_TICK_TIMER_CNT_MASK);
}


/*******************************************************************************
* Function Name: DISP_TICK_TIMER_GetInterruptStatus
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t DISP_TICK_TIMER_GetInterruptStatus(void)       
{
    return(Cy_TCPWM_GetInterruptStatus(DISP_TICK_TIMER_HW, DISP_TICK_TIMER_CNT_NUM));
}


/*******************************************************************************
* Function Name: DISP_TICK_TIMER_ClearInterrupt
****************************************************************************//**
*
* Invokes the Cy_TCPWM_ClearInterrupt() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void DISP_TICK_TIMER_ClearInterrupt(uint32_t source)     
{
    Cy_TCPWM_ClearInterrupt(DISP_TICK_TIMER_HW, DISP_TICK_TIMER_CNT_NUM, source);
}


/*******************************************************************************
* Function Name: DISP_TICK_TIMER_SetInterrupt
****************************************************************************//**
*
* Invokes the Cy_TCPWM_SetInterrupt() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void DISP_TICK_TIMER_SetInterrupt(uint32_t source)
{
    Cy_TCPWM_SetInterrupt(DISP_TICK_TIMER_HW, DISP_TICK_TIMER_CNT_NUM, source);
}


/*******************************************************************************
* Function Name: DISP_TICK_TIMER_SetInterruptMask
****************************************************************************//**
*
* Invokes the Cy_TCPWM_SetInterruptMask() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void DISP_TICK_TIMER_SetInterruptMask(uint32_t mask)     
{
    Cy_TCPWM_SetInterruptMask(DISP_TICK_TIMER_HW, DISP_TICK_TIMER_CNT_NUM, mask);
}


/*******************************************************************************
* Function Name: DISP_TICK_TIMER_GetInterruptMask
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptMask() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t DISP_TICK_TIMER_GetInterruptMask(void)         
{
    return(Cy_TCPWM_GetInterruptMask(DISP_TICK_TIMER_HW, DISP_TICK_TIMER_CNT_NUM));
}


/*******************************************************************************
* Function Name: DISP_TICK_TIMER_GetInterruptStatusMasked
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptStatusMasked() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t DISP_TICK_TIMER_GetInterruptStatusMasked(void)
{
    return(Cy_TCPWM_GetInterruptStatusMasked(DISP_TICK_TIMER_HW, DISP_TICK_TIMER_CNT_NUM));
}

#endif /* DISP_TICK_TIMER_CY_TCPWM_COUNTER_PDL_H */


/* [] END OF FILE */
