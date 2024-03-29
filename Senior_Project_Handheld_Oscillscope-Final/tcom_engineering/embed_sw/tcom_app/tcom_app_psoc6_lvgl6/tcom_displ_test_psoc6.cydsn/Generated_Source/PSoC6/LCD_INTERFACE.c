/*******************************************************************************
* File Name: LCD_INTERFACE.c  
* Version 1.80
*
* Description:
*  This file contains the setup, control and status commands for the 
*  GraphicLCDIntf component.   
*
*******************************************************************************
* Copyright 2008-2018, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include "LCD_INTERFACE.h"  

uint8 LCD_INTERFACE_initVar = 0u;


/*******************************************************************************
* Function Name: LCD_INTERFACE_Enable
********************************************************************************
*
* Summary:
*  There is no need to reset or enable this component.  This component is 
*  naturally a slave that waits for the API calls to perform any 
*  function and after a request is made that request will always complete in 
*  finite time as long as a clock is provided. The only thing provided
*  by this API is setting the Command FIFO to drive at least the half-empty status
*  from the FIFO.
*
*******************************************************************************/
void LCD_INTERFACE_Enable(void) 
{   
    /* Nothing to enable */
}


/*******************************************************************************
* Function Name: LCD_INTERFACE_Init
********************************************************************************
*
* Summary:
*  Inits/Restores default GraphicLCDIntf configuration provided with the customizer.
* 
*******************************************************************************/
void LCD_INTERFACE_Init(void) 
{
    /* Set low and high pulse widths for a read transaction */
    LCD_INTERFACE_READ_LO_PULSE_REG = LCD_INTERFACE_READ_LOW_PULSE;
    LCD_INTERFACE_READ_HI_PULSE_REG = LCD_INTERFACE_READ_HIGH_PULSE;
}


/*******************************************************************************
* Function Name: LCD_INTERFACE_Start
********************************************************************************
*
* Summary:
*  Starts the GraphicLCDIntf interface.
*
* Global Variables:
*  LCD_INTERFACE_initVar - Used to check the initial configuration, modified on 
*  the first function call.
*
*******************************************************************************/
void LCD_INTERFACE_Start(void) 
{
    if (LCD_INTERFACE_initVar == 0u)
    {
        LCD_INTERFACE_Init();
        LCD_INTERFACE_initVar = 1u;
    }
      
    LCD_INTERFACE_Enable();
}


/*******************************************************************************
* Function Name: LCD_INTERFACE_Stop
********************************************************************************
*
* Summary:
*  Disables the GraphicLCDIntf interface.
*
*******************************************************************************/
void LCD_INTERFACE_Stop(void) 
{
    /* Nothing to stop */
}


/*******************************************************************************
* Function Name: LCD_INTERFACE_Write8
********************************************************************************
*
* Summary:
*  Initiates a write transaction on the 8-bit parallel
*  interface.
*  The write is a posted write, so this function will return before the write 
*  has actually completed on the interface. If the command queue is full, this 
*  function will not return until space is available to queue this write request.
*
* Parameters:
*  d_c:  Data(1) or Command(0) indication. Passed to the d_c pin.
*
*  wrData: Data sent to the do_msb[7:0] (most significant byte) 
*          and do_lsb[7:0] (least significant byte) pins. do_msb[7:0]
*          presents only for the 16-bit interface.
*
*******************************************************************************/
void LCD_INTERFACE_Write8(uint8 d_c, uint8 wrData) 
{
    while((LCD_INTERFACE_STATUS_REG & LCD_INTERFACE_CMD_QUEUE_FULL) != 0u)
    {
        /* The command queue is full */
    }   
    LCD_INTERFACE_CMD_FIFO_REG = d_c;
    #if (LCD_INTERFACE_BUS_WIDTH == 16u)
        CY_SET_REG16(LCD_INTERFACE_DATA_FIFO_PTR, wrData);
    #else /* 8-bit interface */
        LCD_INTERFACE_DATA_FIFO_REG = wrData;
    #endif /* LCD_INTERFACE_BUS_WIDTH == 16u */
}
	

/*******************************************************************************
* Function Name: LCD_INTERFACE_WriteM8
********************************************************************************
*
* Summary:
*  Initiates multiple write transactions on the 8-bit 
*  parallel interface. The write is a posted write, so this function will return
*  before the write has actually completed on the interface. If the command 
*  queue is full, this function will not return until space is available to queue
*  this write request.
*
* Parameters:
*  d_c:    The Data(1) or Command(0) indication. Passed to the d_c pin.
*
*  wrData: The pointer to the the first element of a data buffer sent to the do_msb[7:0]
*          (most significant byte) and do_lsb[7:0] (least significant byte) pins. 
*          do_msb[7:0] presents only for the 16-bit interface.
*
*  num:    The number of words/bytes to write.
*
*******************************************************************************/
void LCD_INTERFACE_WriteM8(uint8 d_c, uint8 wrData[], uint16 num) 
{
    uint32 i;
    
    for(i = 0u; i < num; i++)
    {
        while((LCD_INTERFACE_STATUS_REG & LCD_INTERFACE_CMD_QUEUE_FULL) != 0u)
        {
            /* The command queue is full */
        }   
        LCD_INTERFACE_CMD_FIFO_REG = d_c;  
 
        #if (LCD_INTERFACE_BUS_WIDTH == 16u)
            CY_SET_REG16(LCD_INTERFACE_DATA_FIFO_PTR, wrData[i]);
        #else /* 8-bit interface */
            LCD_INTERFACE_DATA_FIFO_REG = wrData[i];
        #endif /* LCD_INTERFACE_BUS_WIDTH == 16u */
    }
}


/*******************************************************************************
* Function Name: LCD_INTERFACE_Read8
********************************************************************************
*
* Summary:
*  Initiates a read transaction on the 8-bit parallel interface.
*  The read will execute after all currently posted writes have completed. This 
*  function will wait until the read completes and then returns the read value.
*
* Parameters:
*  d_c: Data(1) or Command(0) indication. Passed to the d_c pin.
*
* Return:
*  The 16-bit read value from the di_msb[7:0] (most significant byte) and 
*  di_lsb[7:0] (least significant byte) pins for the 16-bit interface or the 
*  8-bit read value from the di_lsb[7:0] for 8-bit interface.
*
*******************************************************************************/
uint8 LCD_INTERFACE_Read8(uint8 d_c) 
{
    while((LCD_INTERFACE_STATUS_REG & LCD_INTERFACE_CMD_QUEUE_FULL) != 0u)
    {
        /* The command queue is full */
    }   
    LCD_INTERFACE_CMD_FIFO_REG = d_c | LCD_INTERFACE_READ_COMMAND;
    
    while((LCD_INTERFACE_STATUS_REG & LCD_INTERFACE_DATA_VALID) != LCD_INTERFACE_DATA_VALID)
    {
        /* Wait until input data is valid */
    }
    
    #if (LCD_INTERFACE_BUS_WIDTH == 8u)  /* 8-bit interface */
        return (LCD_INTERFACE_DIN_LSB_DATA_REG);
    #else   /* 16-bit interface */
        return (uint16)((uint16)LCD_INTERFACE_DIN_MSB_DATA_REG << 8u) | LCD_INTERFACE_DIN_LSB_DATA_REG; 
    #endif /* LCD_INTERFACE_BUS_WIDTH == 8u */
}


/*******************************************************************************
* Function Name: LCD_INTERFACE_ReadM8
********************************************************************************
*
* Summary:
*  Initiates multiple read transactions on the 8-bit 
*  parallel interface. The read will execute after all currently posted writes 
*  have completed. This function will wait until the read completes and then 
*  returns the read value.
*
* Parameters:
*  d_c:    The Data(1) or Command(0) indication. Passed to the d_c pin.
*
*  rdData: The pointer to the the first element of a data buffer read from the do_msb[7:0]
*          (most significant byte) and do_lsb[7:0] (least significant byte) pins. 
*          do_msb[7:0] presents only for the 16-bit interface.
*
*  num:    The number of words/bytes to read.
*
*******************************************************************************/
void LCD_INTERFACE_ReadM8(uint8 d_c, uint8 rdData[], uint16 num) 
{
    uint32 i;
    
    for(i = 0u; i < num; i++)
    {
        rdData[i] = LCD_INTERFACE_Read8(d_c);
    }
}


/*******************************************************************************
* Function Name: LCD_INTERFACE_Write8_A0
********************************************************************************
*
* Summary:
*  Initiates a write transaction on the 8-bit parallel
*  interface with the d_c pin set to 0.
*  The write is a posted write, so this function will return before the write 
*  has actually completed on the interface. If the command queue is full, this 
*  function will not return until space is availale to queue this write request.
*
* Parameters:
*  wrData: Data sent on the do_msb[7:0] (most significant byte) 
*         and do_lsb[7:0] (least significant byte) pins. do_msb[7:0]
*         presents only for 16-bit interface.
*
*******************************************************************************/
void LCD_INTERFACE_Write8_A0(uint8 wrData) 
{
    while((LCD_INTERFACE_STATUS_REG & LCD_INTERFACE_CMD_QUEUE_FULL) != 0u)
    {
        /* Command queue is full */
    }   
    LCD_INTERFACE_CMD_FIFO_REG = 0u;
    #if (LCD_INTERFACE_BUS_WIDTH == 16u)
        CY_SET_REG16(LCD_INTERFACE_DATA_FIFO_PTR, wrData);
    #else /* 8-bit interface */
        LCD_INTERFACE_DATA_FIFO_REG = wrData;
    #endif /* LCD_INTERFACE_BUS_WIDTH == 16u */
}


/*******************************************************************************
* Function Name: LCD_INTERFACE_Write8_A1
********************************************************************************
*
* Summary:
*  Initiates a write transaction on the 8-bit 
*  parallel interface with the d_c pin set to 1. The write is a posted write, 
*  so this function will return before the write has actually completed on the 
*  interface. If the command queue is full, this function will not return until
*  space is availale to queue this write request.
*
* Parameters:
*  wrData: Data sent on the do_msb[7:0] (most significant byte) 
*          and do_lsb[7:0] (least significant byte) pins. do_msb[7:0]
*          presents only for 16-bit interface.
*
*******************************************************************************/
void LCD_INTERFACE_Write8_A1(uint8 wrData) 
{
    while((LCD_INTERFACE_STATUS_REG & LCD_INTERFACE_CMD_QUEUE_FULL) != 0u)
    {
        /* Command queue is full */
    }   
    LCD_INTERFACE_CMD_FIFO_REG = 1u;
    #if (LCD_INTERFACE_BUS_WIDTH == 16u)
        CY_SET_REG16(LCD_INTERFACE_DATA_FIFO_PTR, wrData);
    #else /* 8-bit interface */
        LCD_INTERFACE_DATA_FIFO_REG = wrData;
    #endif /* LCD_INTERFACE_BUS_WIDTH == 16u */
}


/*******************************************************************************
* Function Name: LCD_INTERFACE_WriteM8_A0
********************************************************************************
*
* Summary:
*  Initiates multiple write transactions on the 8-bit 
*  parallel interface with the d_c pin set to 0. The write is a posted write, 
*  so this function will return before the write has actually completed on the 
*  interface. If the command queue is full, this function will not return until
*  space is availale to queue this write request.
*
* Parameters:
*  wrData: Pointer to the the first element of a data buffer sent on the 
*          do_msb[7:0] (most significant byte) and do_lsb[7:0] (least significant
*          byte) pins. do_msb[7:0] presents only for 16-bit interface.
*
*  num:  Number of words/bytes to write.
*
*******************************************************************************/
void LCD_INTERFACE_WriteM8_A0(uint8 wrData[], int num) 
{
    LCD_INTERFACE_WriteM8(0u, wrData, (uint16)num);
}


/*******************************************************************************
* Function Name: LCD_INTERFACE_WriteM8_A1
********************************************************************************
*
* Summary:
*  Initiates multiple data write transactions on the 8-bit 
*  parallel interface with the d_c pin set to 1. The write is a posted write, 
*  so this function will return before the write has actually completed on the 
*  interface. If the command queue is full, this function will not return until
*  space is availale to queue this write request.
*
* Parameters:
*  wrData: Pointer to the the first element of a data buffer sent on the 
*          do_msb[7:0] (most significant byte) and do_lsb[7:0] (least significant
*          byte) pins. do_msb[7:0] presents only for 16-bit interface.
*
*  num:  Number of words/bytes to write.
*
*******************************************************************************/
void LCD_INTERFACE_WriteM8_A1(uint8 wrData[], int num) 
{
    LCD_INTERFACE_WriteM8(1u, wrData, (uint16)num);
}


/*******************************************************************************
* Function Name: LCD_INTERFACE_Read8_A1
********************************************************************************
*
* Summary:
*  Initiates data read transaction on the 8-bit 
*  parallel interface with the d_c pin set to 1. The read will execute after 
*  all currently posted writes have completed. This function will wait until 
*  the read completes and then returns the read value.
*
* Return:
*  The 16-bit read value from the di_msb[7:0] (most significant byte) and 
*  di_lsb[7:0] (least significant byte) pins for the 16-bit interface or the 
*  8-bit read value from the di_lsb[7:0] for 8-bit interface.
*
*******************************************************************************/
uint8 LCD_INTERFACE_Read8_A1(void) 
{
    return LCD_INTERFACE_Read8(1u);
}


/*******************************************************************************
* Function Name: LCD_INTERFACE_ReadM8_A1
********************************************************************************
*
* Summary:
*  Initiates multiple data read transactions on the 8-bit 
*  parallel interface with the d_c pin set to 1. The read will execute after all 
*  currently posted writes have completed. This function will wait until the 
*  read completes and then returns the read value.
*
* Parameters:
*  rdData: Pointer to the the first element of a data buffer read from the do_msb[7:0]
*        (most significant byte) and do_lsb[7:0] (least significant byte) pins. 
*        do_msb[7:0] presents only for 16-bit interface.
*
*  num:  Number of words/bytes to read.
*
*******************************************************************************/
void LCD_INTERFACE_ReadM8_A1(uint8 rdData[], int num) 
{
    LCD_INTERFACE_ReadM8(1u, rdData, (uint16)num);
}


/* [] END OF FILE */
