#include <stdio.h>

#include "project.h"
#include "lvgl.h"
#include "touchpad_glue.h"

#define CTP_I2C_ADDR        (0x38)

bool
touchpad_read(lv_indev_drv_t *drv, lv_indev_data_t * data)
{
    char    val_str[20];
    int     xp;
    int     yp;
        
    cy_stc_scb_i2c_master_xfer_config_t i2c_xfer_config;

    uint8_t write_buf[1] = {0x0};
    uint8_t read_buf[7];
    
    int event_flag;

    while (I2C_MASTER_MasterGetStatus() & CY_SCB_I2C_MASTER_BUSY) {}
    i2c_xfer_config.slaveAddress = CTP_I2C_ADDR;    // address of instance
    i2c_xfer_config.buffer = write_buf;             // buffer
    i2c_xfer_config.bufferSize = 1;                 // byte count = 1
    i2c_xfer_config.xferPending = 0;                // complete transfer (generate a STOP)

    Cy_SCB_I2C_MasterWrite(I2C_MASTER_HW, &i2c_xfer_config, &I2C_MASTER_context);

    while (I2C_MASTER_MasterGetStatus() & CY_SCB_I2C_MASTER_BUSY) {}

    i2c_xfer_config.buffer = read_buf;             // buffer
    i2c_xfer_config.bufferSize = 7;                 // byte count = 1
    Cy_SCB_I2C_MasterRead(I2C_MASTER_HW, &i2c_xfer_config, &I2C_MASTER_context);

    while (I2C_MASTER_MasterGetStatus() & CY_SCB_I2C_MASTER_BUSY) {}

    xp = ((read_buf[3] << 8) + read_buf[4]) & 0x3FF;
    yp = ((read_buf[5] << 8) + read_buf[6]) & 0x3FF;
    
    event_flag = (read_buf[3] >> 6) & 0x3;

    sprintf( val_str, "xp=%04X, yp=%04X\r\n", (read_buf[3] << 8) + read_buf[4], (read_buf[5] << 8) + read_buf[6] );
    sprintf( val_str, "xp=0.%02d, yp=0.%02d\r\n", xp * 100/320, yp * 100/480 );
//    UART_KITPROG_USB_PutString( val_str );
//    lv_label_set_text(label2, val_str);

    
    data->point.x = xp;
    data->point.y = yp;
    
    if (event_flag == 2)    data->state = LV_INDEV_STATE_PR;         
    else                    data->state = LV_INDEV_STATE_REL;        
    
    return false;
}

