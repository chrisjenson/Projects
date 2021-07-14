#include <stdio.h>
#include "project.h"
#include "lvgl.h"

/***************************************
*            Constants
****************************************/
#define PACKET_SIZE     (3u)

/* Commands */
#define CMD_SET_OFF     (0u)
#define CMD_SET_RED     (1u)
#define CMD_SET_RG      (2u)
#define CMD_SET_GREEN   (3u)
#define CMD_SET_GB      (4u)
#define CMD_SET_BLUE    (5u)
#define CMD_END         (6u)
#define CMD_SET_UNKNOWN (0xFFu)

/* Start and end of the packet markers */
#define PACKET_SOP      (0x01u)
#define PACKET_EOP      (0x17u)

/* Byte position within the packet */
#define PACKET_SOP_POS  (0u)
#define PACKET_CMD_POS  (1u)

/* Command execution status */
#define STS_CMD_DONE    (0x07u)
#define STS_CMD_FAIL    (0xFFu)

/* Command and status share the same offset */
#define PACKET_STS_POS  (PACKET_CMD_POS)
#define PACKET_EOP_POS  (2u)

/* Controls the frequency at which the light changes */
#define CMD_TO_CMD_DELAY    (500u)
#define CMD_STALL           (20u)

/* A dummy buffer to send to the slave when the master needs to receive
   the status packet*/
const uint8 dummyBuffer[PACKET_SIZE] = {0xFFu, 0xFFu, 0xFFu};

/*******************************************************************************
* Function Name: SPIM_SendCommandPacket
********************************************************************************
* Summary:
*  Loads a three byte packet into the Tx buffer and sends it to the slave device. Waits
*  until the entire transmission is completed. The master receives dummy bytes which can 
*  be cleared from the Rx buffer.
*
* Parameters:
*  cmd - The commmand to be sent to the slave device
*
* Return:
*  None
*
*******************************************************************************/
void SPIM_SendCommandPacket(uint8 cmd)
{
    /* SPIM TX buffer */
    static uint8 mTxBuffer[PACKET_SIZE] = {PACKET_SOP, CMD_SET_BLUE, PACKET_EOP};

    mTxBuffer[PACKET_CMD_POS] = cmd;

    /* Start transfer */
    SPIM_SpiUartPutArray(mTxBuffer, PACKET_SIZE);

    /* Wait for the end of the transfer. In SPI, the number of transmitted data
       elements has to be equal to the number of received data elements. */
    while(PACKET_SIZE != SPIM_SpiUartGetRxBufferSize());

    /* Clear dummy bytes from RX buffer */
    SPIM_SpiUartClearRxBuffer();
}

/*******************************************************************************
* Function Name: SPIM_ReadStatusPacket
********************************************************************************
* Summary:
*  SPIM initiates the transmission of a dummy packet to collect the status
*  information from the SPIS. After the transfer is complete the format of
*  the packet is verified and the status is returned. If the format of the
*  packet is invalid the unknown status is returned.
*
* Parameters:
*  None
*
* Return:
*  Status - Returns the status byte of the recieved packet
*
*******************************************************************************/
static uint32 SPIM_ReadStatusPacket(void)
{
    uint8 tmpBuffer[PACKET_SIZE];
    uint8 status;
    uint8 i = 0;

    /* Start transfer */
    SPIM_SpiUartPutArray(dummyBuffer, PACKET_SIZE);

    /* Wait for the end of the transfer. The number of transmitted data
    * elements has to be equal to the number of received data elements. */
    while (PACKET_SIZE != SPIM_SpiUartGetRxBufferSize());

    /* Clear dummy bytes from TX buffer */
    SPIM_SpiUartClearTxBuffer();

    
    /* Read data from the RX buffer */
    while(0u != SPIM_SpiUartGetRxBufferSize())
    {
        tmpBuffer[i] = (uint8) SPIM_SpiUartReadRxData();
        i++;
    }

    /* Clears the Rx buffer after reading it */
    SPIM_SpiUartClearRxBuffer();
    
    /* Check packet format */
    if ((tmpBuffer[PACKET_SOP_POS] == PACKET_SOP) &&
        (tmpBuffer[PACKET_EOP_POS] == PACKET_EOP))
    {
        /* Return status */
        status = tmpBuffer[PACKET_STS_POS];
    }
    else
    {
        /* Invalid packet format, return fail status */
        status = STS_CMD_FAIL;
    }

    return ((uint32)status);
}