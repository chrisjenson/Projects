/******************************************************************************
* File Name: Driver1_DMA_Seg_dma.h  
* Version 1.70
*
*  Description:
*   Provides the function definitions for the DMA Controller.
*
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/
#if !defined(CY_DMA_Driver1_DMA_Seg_DMA_H__)
#define CY_DMA_Driver1_DMA_Seg_DMA_H__



#include <CYDMAC.H>
#include <CYFITTER.H>

#define Driver1_DMA_Seg__TD_TERMOUT_EN (((0 != Driver1_DMA_Seg__TERMOUT0_EN) ? TD_TERMOUT0_EN : 0) | \
    (Driver1_DMA_Seg__TERMOUT1_EN ? TD_TERMOUT1_EN : 0))

/* Zero based index of Driver1_DMA_Seg dma channel */
extern uint8 Driver1_DMA_Seg_DmaHandle;


uint8 Driver1_DMA_Seg_DmaInitialize(uint8 BurstCount, uint8 ReqestPerBurst, uint16 UpperSrcAddress, uint16 UpperDestAddress) ;
void  Driver1_DMA_Seg_DmaRelease(void) ;


/* CY_DMA_Driver1_DMA_Seg_DMA_H__ */
#endif
