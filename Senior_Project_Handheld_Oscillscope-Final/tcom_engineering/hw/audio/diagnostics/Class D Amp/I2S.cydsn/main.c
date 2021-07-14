#include <project.h>
#include <stdlib.h>
#include <math.h>
 
/* I2S_1 */
#define SAMPLERATE_HZ               (16000)     // The sample rate of the audio.
#define AMPLITUDE                   ((1<<23)-1) // Set the amplitude of generated waveforms.
#define WAV_SIZE                    (64)        // The size of each generated waveform.
#define WS                          (0x00)      // left channel.

/* I2C_1 */ 
#define I2C_TX_BYTE_CNT_1           (1)         // # of bytes transmitted.
#define I2C_TX_BYTE_CNT_2           (2)         // # of bytes transmitted.
#define I2C_TX_BYTE_CNT_3           (3)         // # of bytes transmitted.

/* TFA I2C DEVICE ADDRESS */
#define TFA_9879_ADDRESS            (0x6C)

/* TFA9879 REGISTER ADDRESSES */
#define TFA9879_DEVICE_CONTROL		(0x00)
#define TFA9879_SERIAL_INTERFACE_1	(0x01)
#define TFA9879_VOLUME_CONTROL		(0x13)
#define TFA9879_MISC_STATUS		    (0x15)

/* TFA9879_DEVICE_CONTROL */
#define DEVICE_CONTROL_MSB          (0x00)
#define DEVICE_CONTROL_LSB_1        (0x01)
#define DEVICE_CONTROL_LSB_2        (0x09)

/* TFA9879_SERIAL_INTERFACE */
#define SERIAL_INTERFACE_1_MSB      (0x08)
#define SERIAL_INTERFACE_1_LSB      (0xD8)

/* TFA9879_VOLUME_CONTROL */
#define VOLUME_CONTROL_MSB          (0x10)
#define VOLUME_CONTROL_LSB          (0x00)


/* Variable declarations for I2S_1 */
int32_t sine_table[WAV_SIZE] = {0}; // Store basic waveforms in memory.


/* Variable declarations for I2C_1 */
uint8_t volume_buf[3]             = {TFA9879_VOLUME_CONTROL, VOLUME_CONTROL_MSB, VOLUME_CONTROL_LSB};
uint8_t device_control_buf_1[3]   = {TFA9879_DEVICE_CONTROL, DEVICE_CONTROL_MSB, DEVICE_CONTROL_LSB_1};
uint8_t device_control_buf_2[3]   = {TFA9879_DEVICE_CONTROL, DEVICE_CONTROL_MSB, DEVICE_CONTROL_LSB_2};
uint8_t serial_interface_buf[3]   = {TFA9879_SERIAL_INTERFACE_1, SERIAL_INTERFACE_1_MSB, SERIAL_INTERFACE_1_LSB};
uint8_t misc_addr                 = TFA9879_MISC_STATUS;
uint8_t read_buf[2];

void generateSine(int32_t amplitude, int32_t* buffer, int length) // Generate Sine Wave Function.
{
    // Generate a sine wave signal with the provided amplitude and store it in
    // the provided buffer (sine_table) of size length.
    for ( int i=0; i < length; ++i ) {
//        buffer[i] = (int)(amplitude*sin(2.0*M_PI*(1.0/length)*i));
        if (i < (length / 2)) {
            buffer[i] = 0x3FFFFF;
        } else {
            buffer[i] = 0xC00000;
        }
    }
}

void playWave(int32_t* buffer, int length) {
    int tab_idx = 0;
    int byte_idx = 2;
    while (1) {
        int temp = I2S_1_ReadTxStatus();
        if (temp & I2S_1_TX_FIFO_UNDERFLOW) {
            I2S_1_DisableTx();
            I2S_1_ClearTxFIFO();
            I2S_1_EnableTx();
        }
        if ((temp & I2S_1_TX_FIFO_0_NOT_FULL)) {
            int val = buffer[tab_idx];
            uint8_t byte = (val >> (8*byte_idx)) & 0xFF;
            I2S_1_WriteByte(byte, WS);
            --byte_idx;
            if (byte_idx < 0) {
                byte_idx = 2;
                ++ tab_idx;
                if (tab_idx == length) {
                    tab_idx = 0;
                }
            }
        }
    }
}

int main()
{
    CyGlobalIntEnable;
    
    I2S_1_Start();
    I2S_1_DisableTx();
    I2S_1_ClearTxFIFO();
    I2S_1_EnableTx();
    I2C_1_Start();
    
    generateSine(AMPLITUDE, sine_table, WAV_SIZE);  // Generate waveforms.
  
    //while (1) {
    while (I2C_1_MasterStatus() & I2C_1_MSTAT_XFER_INP){};
    I2C_1_MasterWriteBuf(TFA_9879_ADDRESS, device_control_buf_1, I2C_TX_BYTE_CNT_3, I2C_1_MODE_COMPLETE_XFER);
    
    CyDelay(10);
    
    while (I2C_1_MasterStatus() & I2C_1_MSTAT_XFER_INP){};
    I2C_1_MasterWriteBuf(TFA_9879_ADDRESS, device_control_buf_2, I2C_TX_BYTE_CNT_3, I2C_1_MODE_COMPLETE_XFER);
    
    CyDelay(10);
    
    while (I2C_1_MasterStatus() & I2C_1_MSTAT_XFER_INP){};
    I2C_1_MasterWriteBuf(TFA_9879_ADDRESS, serial_interface_buf, I2C_TX_BYTE_CNT_3, I2C_1_MODE_COMPLETE_XFER);
    
    while (I2C_1_MasterStatus() & I2C_1_MSTAT_XFER_INP){};
    I2C_1_MasterWriteBuf(TFA_9879_ADDRESS, &misc_addr, I2C_TX_BYTE_CNT_1, I2C_1_MODE_NO_STOP);
    
    while (!(I2C_1_MasterStatus() & I2C_1_MSTAT_WR_CMPLT)){}; 
    I2C_1_MasterReadBuf(TFA_9879_ADDRESS, read_buf, I2C_TX_BYTE_CNT_2, I2C_1_MODE_REPEAT_START);
    
    while (I2C_1_MasterStatus() & I2C_1_MSTAT_XFER_INP){};
    I2C_1_MasterWriteBuf(TFA_9879_ADDRESS, volume_buf, I2C_TX_BYTE_CNT_3, I2C_1_MODE_COMPLETE_XFER);
    //}
    
    CyDelay(1);
    
    for(;;) // Main loop. 
    {
        playWave(sine_table, WAV_SIZE);
    }  
 }
 /* [] END OF FILE */