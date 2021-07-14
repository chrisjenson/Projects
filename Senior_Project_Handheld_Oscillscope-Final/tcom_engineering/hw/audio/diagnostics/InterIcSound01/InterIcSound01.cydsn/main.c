#include <project.h>

#define BUFFER_SIZE (3u)

static uint8_t rxBuff[BUFFER_SIZE] = {0};


/* Data recieved by Rx */
void read_sound(uint8_t* buffer, int length)
{
    int temp = I2S_1_ReadRxStatus();
    if (temp & I2S_1_RX_FIFO_OVERFLOW)
    {
        I2S_1_DisableRx();
        I2S_1_ClearRxFIFO();
        I2S_1_EnableRx();
    }
    
    if (temp & I2S_1_RX_FIFO_0_NOT_EMPTY)
    {
        int value;
        for ( int i = 0; i < length; ++i )
        {
            while (!(I2S_1_ReadRxStatus() & I2S_1_RX_FIFO_0_NOT_EMPTY)){}
            buffer[i] = I2S_1_ReadByte(0u);
        }
        int gain_shift = 1; // max is 2^31 - 1
        value = (((uint32_t)buffer[2])<<8u) | (((uint32_t)buffer[1])<<16u) | (((uint32_t)buffer[0])<<24u);
        
        if (value > ((1<<(31 - gain_shift)) - 1))
        {
            value = ((1<<(31 - gain_shift)) - 1);
        }
        if (value < (1<<(31 - gain_shift)))
        {
            value = (1<<(31 - gain_shift));
        }
        value = value + (1<<31);
        VDAC8_1_SetValue(value>>(24 - gain_shift));
        //VDAC8_1_SetValue(buffer[1]+128);
    }
}

static void DisplayUpdate(void)
{   
    uint8 idx;
    uint8 col;

    /* Set start position for data output */
    col = 4; 
	for(idx = 0; idx < BUFFER_SIZE; idx++) {
        LCD_Position(0u, col);
        LCD_PrintInt8(rxBuff[idx]);
        col += 3;
    }
}

int main()
{
    VDAC8_1_Start();
    LCD_Start();
    LCD_Position(0u, 0u);
    LCD_PrintString("RX:");

    I2S_1_Start();
    I2S_1_DisableRx();
    I2S_1_ClearRxFIFO();
    I2S_1_EnableRx();

    CyDelayUs(10);
   
    for(;;)
    {
        //CyDelay(50u);
        read_sound(rxBuff, BUFFER_SIZE);
        //DisplayUpdate();
    }
}
/* [] END OF FILE */
