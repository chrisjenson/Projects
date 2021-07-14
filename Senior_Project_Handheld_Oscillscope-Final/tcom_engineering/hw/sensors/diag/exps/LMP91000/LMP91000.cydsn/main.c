#include "project.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    uint8_t slaveAddress = 0x48;
    uint8_t mode = I2C_1_MODE_COMPLETE_XFER;
    char string1[256];
    
    // Format is {Register, Configuration Bit String}
    uint8_t unlock[2] = {0x01,0x00}; //Unlocks
    //uint8_t setup1[2] = {0x10, 0x04 | 0x00}; //Sets Gain and Rload
    //uint8_t setup2[2] = {0x11, 0x80 | 0x20 | 0x00 | 0x10}; //Sets Internal Ref, Internal Zero, Bias, and Pos Bias
    //uint8_t setup3[2] = {0x12, 0x80 | 0x03}; //Disables FET and Enables 3-electrode configuation
    
    uint8_t setup1[2] = {0x10, 0x03}; //Sets Rload = 100ohms
    uint8_t setup2[2] = {0x11, 0x80 | 0x10 | 0x01}; //Sets external Ref, 50% Internal Zero, 1% Bias
    uint8_t setup3[2] = {0x12, 0x03}; //Enables 3-electrode configuation
    
    UART_Start();
    ADC_SAR_Start();
    I2C_1_Start();
    //I2C_1_EnableInt();
    
    //Sets up Configurations
    I2C_1_MasterWriteBuf(slaveAddress, unlock, 2, mode); while (I2C_1_MasterStatus() & I2C_1_MSTAT_XFER_INP) {}
    I2C_1_MasterWriteBuf(slaveAddress, setup1, 2, mode); while (I2C_1_MasterStatus() & I2C_1_MSTAT_XFER_INP) {}
    I2C_1_MasterWriteBuf(slaveAddress, setup2, 2, mode); while (I2C_1_MasterStatus() & I2C_1_MSTAT_XFER_INP) {}
    I2C_1_MasterWriteBuf(slaveAddress, setup3, 2, mode); while (I2C_1_MasterStatus() & I2C_1_MSTAT_XFER_INP) {}
    
    int count = 0;
    while(1)
    {
        ADC_SAR_StartConvert();
        ADC_SAR_IsEndConversion(ADC_SAR_WAIT_FOR_RESULT);
        sprintf(string1,"%d,%d\r\n",count,ADC_SAR_GetResult16());
        UART_PutString(string1);
        count++;
        CyDelay(1000);
    }
}