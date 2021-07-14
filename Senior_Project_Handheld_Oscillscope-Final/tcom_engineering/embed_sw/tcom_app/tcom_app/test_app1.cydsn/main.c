#include "project.h"
#include "lv_conf.h"
#include "lvgl.h"
#include "stdio.h"
#include "roscoe.h"

// Call `lv_tick_inc(x)` every `x` milliseconds **in a Timer or Task** (`x` should be between 1 and 10). It is required for the internal timing of LittlevGL. **It's very important that you don't call `lv_task_handler` in the same loop.**
// Call `lv_task_handler()` periodically every few milliseconds in the main `while(1)` loop, in Timer interrupt or in an Operation system task. It will redraw the screen if required, handle input devices etc. **It's very important that you don't call `lv_tick_inc` in the same loop.**

#define DLY (0)
#define DSPL_READ_MADCTL    (0x0B)
#define DSPL_SLEEP_OUT      (0x11)
#define DSPL_DISPLAY_ON     (0x29)
#define DSPL_COL_ADDR_SET   (0x2A)
#define DSPL_PAG_ADDR_SET   (0x2B)
#define DSPL_MEM_WR         (0x2C)
#define DSPL_MEM_RD         (0x2E)
#define DSPL_MEM_ACC_CTL    (0x36)

#define CTP_I2C_ADDR        (0x38)

#define BYTE_HI( x )        ( ((x) >> 8) & 0xFF )
#define BYTE_LO( x )        ( ((x) >> 0) & 0xFF )

const uint8_t tcnj_blue[] = { 41, 63, 111 };
const uint8_t tcnj_gold[] = { 166, 122, 0 };

bool
touchpad_read(lv_indev_data_t * data)
{
    data->point.x = 100;
    data->point.y = 100;
    data->state = LV_INDEV_STATE_REL;         // LV_INDEV_STATE_REL or LV_INDEV_STATE_PR
    return false;
}

void
ili9488_init()
{
    int     D_CX;
    LCD_INTERFACE_Start();
    CyDelay(10);
    
    BACKLIGHT_CTL_Write(1); // Turns on backlight

    D_CX = 0;   LCD_INTERFACE_Write8(D_CX, DSPL_SLEEP_OUT);
    CyDelay(10);
    
    D_CX = 0;   LCD_INTERFACE_Write8(D_CX, DSPL_DISPLAY_ON);
    CyDelay(10);
    
    D_CX = 0;   LCD_INTERFACE_Write8(D_CX, DSPL_MEM_ACC_CTL);
    D_CX = 1;   LCD_INTERFACE_Write8(D_CX, 0x44);               // set MX & MH bits to '1' to mirror horizontally!!    
}

void
ili9488_map(int32_t x1, int32_t y1, int32_t x2, int32_t y2, const lv_color_t *color_p)
{
    int     D_CX;
    int     y;
    int     x;
    
    D_CX = 0;   LCD_INTERFACE_Write8(D_CX, DSPL_COL_ADDR_SET);
    D_CX = 1;   LCD_INTERFACE_Write8(D_CX, BYTE_HI(x1));
                LCD_INTERFACE_Write8(D_CX, BYTE_LO(x1));
                LCD_INTERFACE_Write8(D_CX, BYTE_HI(x2));
                LCD_INTERFACE_Write8(D_CX, BYTE_LO(x2));

    D_CX = 0;   LCD_INTERFACE_Write8(D_CX, DSPL_PAG_ADDR_SET);
    D_CX = 1;   LCD_INTERFACE_Write8(D_CX, BYTE_HI(y1));
                LCD_INTERFACE_Write8(D_CX, BYTE_LO(y1));
                LCD_INTERFACE_Write8(D_CX, BYTE_HI(y2));
                LCD_INTERFACE_Write8(D_CX, BYTE_LO(y2));

    D_CX = 0;   LCD_INTERFACE_Write8(D_CX, DSPL_MEM_WR);
    D_CX = 1;

    for(y = y1; y <= y2; y++) 
    {
        for(x = x1; x <= x2; x++) 
        {
            uint8_t r;
            uint8_t g;
            uint8_t b;
            
            uint32_t val;
            
            val = (*color_p).full;
            
            r = (val >> 16) & 0xFF;
            g = (val >>  8) & 0xFF;
            b = (val >>  0) & 0xFF;
            
            LCD_INTERFACE_Write8(D_CX, b);
            LCD_INTERFACE_Write8(D_CX, g);
            LCD_INTERFACE_Write8(D_CX, r);
            
            color_p++;
        }
    }    
}


void
ili9488_zoom(int32_t x1, int32_t y1, int32_t x2, int32_t y2, const lv_color_t *color_p)
{
    int     D_CX;
    int     y;
    int     x;
    
    int32_t x_end;
    int32_t y_end;
    
    x_end = x1 - 1 + ((x2-x1+1) << 1);
    y_end = y1 - 1 + ((y2-y1+1) << 1);
    
    D_CX = 0;   LCD_INTERFACE_Write8(D_CX, DSPL_COL_ADDR_SET);
    D_CX = 1;   LCD_INTERFACE_Write8(D_CX, BYTE_HI(x1));
                LCD_INTERFACE_Write8(D_CX, BYTE_LO(x1));
                LCD_INTERFACE_Write8(D_CX, BYTE_HI(x_end));
                LCD_INTERFACE_Write8(D_CX, BYTE_LO(x_end));

    D_CX = 0;   LCD_INTERFACE_Write8(D_CX, DSPL_PAG_ADDR_SET);
    D_CX = 1;   LCD_INTERFACE_Write8(D_CX, BYTE_HI(y1));
                LCD_INTERFACE_Write8(D_CX, BYTE_LO(y1));
                LCD_INTERFACE_Write8(D_CX, BYTE_HI(y_end));
                LCD_INTERFACE_Write8(D_CX, BYTE_LO(y_end));

    D_CX = 0;   LCD_INTERFACE_Write8(D_CX, DSPL_MEM_WR);
    D_CX = 1;

    for(y = y1; y <= y2; y++) 
    {
        for (int zoom_idx = 0; zoom_idx < 2; ++zoom_idx)
        {
            for(x = x1; x <= x2; x++) 
            {
                uint8_t r;
                uint8_t g;
                uint8_t b;
                
                uint32_t val;
                
                val = color_p[x-x1].full;
                
                r = (val >> 16) & 0xFF;
                g = (val >>  8) & 0xFF;
                b = (val >>  0) & 0xFF;
                
                LCD_INTERFACE_Write8(D_CX, b);
                LCD_INTERFACE_Write8(D_CX, g);
                LCD_INTERFACE_Write8(D_CX, r);
                LCD_INTERFACE_Write8(D_CX, b);
                LCD_INTERFACE_Write8(D_CX, g);
                LCD_INTERFACE_Write8(D_CX, r);
            }
        }
        color_p += (x2-x1+1);
    }    
}


void
ili9488_fill(int32_t x1, int32_t y1, int32_t x2, int32_t y2, lv_color_t color_p)
{
    int     D_CX;
    int     y;
    int     x;
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint32_t val;
    
    val = color_p.full;

    r = (val >> 16) & 0xFF;
    g = (val >>  8) & 0xFF;
    b = (val >>  0) & 0xFF;

    D_CX = 0;   LCD_INTERFACE_Write8(D_CX, DSPL_COL_ADDR_SET);
    D_CX = 1;   LCD_INTERFACE_Write8(D_CX, BYTE_HI(x1));
                LCD_INTERFACE_Write8(D_CX, BYTE_LO(x1));
                LCD_INTERFACE_Write8(D_CX, BYTE_HI(x2));
                LCD_INTERFACE_Write8(D_CX, BYTE_LO(x2));

    D_CX = 0;   LCD_INTERFACE_Write8(D_CX, DSPL_PAG_ADDR_SET);
    D_CX = 1;   LCD_INTERFACE_Write8(D_CX, BYTE_HI(y1));
                LCD_INTERFACE_Write8(D_CX, BYTE_LO(y1));
                LCD_INTERFACE_Write8(D_CX, BYTE_HI(y2));
                LCD_INTERFACE_Write8(D_CX, BYTE_LO(y2));

    D_CX = 0;   LCD_INTERFACE_Write8(D_CX, DSPL_MEM_WR);
    D_CX = 1;

    for(y = y1; y <= y2; y++) 
    {
        for(x = x1; x <= x2; x++) 
        {
            LCD_INTERFACE_Write8(D_CX, r);
            LCD_INTERFACE_Write8(D_CX, g);
            LCD_INTERFACE_Write8(D_CX, b);
        }
    }    
}


lv_res_t btn_action(lv_obj_t * btn)
{
    return LV_RES_OK;
}    

int
main( void )
{
    lv_init();
    ili9488_init();
    
    CLOCK1_Start();
    I2C_MASTER_Start();
    DISP_TICK_ISR_Start();
    DISP_TICK_TIMER_Start();
    
    lv_disp_drv_t   disp_drv;
    lv_indev_drv_t indev_drv;

    lv_disp_drv_init(&disp_drv);        // Basic initialization
    disp_drv.disp_fill  = ili9488_fill;
    disp_drv.disp_map   = ili9488_map;
    disp_drv.disp_flush = NULL;
    lv_disp_drv_register(&disp_drv);    // Register the driver in LittlevGL

    lv_indev_drv_init(&indev_drv);     // Descriptor of a input device driver
    indev_drv.type = LV_INDEV_TYPE_POINTER;    /*Touch pad is a pointer-like device*/
    indev_drv.read = touchpad_read;            /*Set your driver function*/
    lv_indev_drv_register(&indev_drv);         /*Finally register the driver*/

    CyGlobalIntEnable; /* Enable global interrupts. */

#define FILL_WID (320)
#define FILL_HGT (480)

    uint16_t    col_start   = 0;
    uint16_t    col_end     = FILL_WID-1;
    uint16_t    row_start   = 0;
    uint16_t    row_end     = FILL_HGT-1;
    int         d_cx;
    lv_color_t  color; color.full = 0xFF8040;
    
    d_cx = 0;   LCD_INTERFACE_Write8(d_cx, DSPL_COL_ADDR_SET);
    d_cx = 1;   LCD_INTERFACE_Write8(d_cx, BYTE_HI(col_start));
                LCD_INTERFACE_Write8(d_cx, BYTE_LO(col_start));
                LCD_INTERFACE_Write8(d_cx, BYTE_HI(col_end));
                LCD_INTERFACE_Write8(d_cx, BYTE_LO(col_end));
    CyDelay(DLY);

    d_cx = 0;   LCD_INTERFACE_Write8(d_cx, DSPL_PAG_ADDR_SET);
    d_cx = 1;   LCD_INTERFACE_Write8(d_cx, BYTE_HI(row_start));
                LCD_INTERFACE_Write8(d_cx, BYTE_LO(row_start));
                LCD_INTERFACE_Write8(d_cx, BYTE_HI(row_end));
                LCD_INTERFACE_Write8(d_cx, BYTE_LO(row_end));
    CyDelay(DLY);

    d_cx = 0;   LCD_INTERFACE_Write8(d_cx, DSPL_MEM_WR);
    d_cx = 1;
    CyDelay(DLY);

    int row_idx;
    int col_idx;
    for (row_idx = 0; row_idx < FILL_WID; ++row_idx)
    {
        for (col_idx = 0; col_idx < FILL_HGT; ++col_idx)
        {
            
            LCD_INTERFACE_Write8(d_cx, 0);
            LCD_INTERFACE_Write8(d_cx, 255);
            LCD_INTERFACE_Write8(d_cx, 255);
        }
    }

    int retval;
    char val_str[16];
    d_cx = 0;   LCD_INTERFACE_Write8(d_cx, DSPL_READ_MADCTL);
    d_cx = 1;   retval = LCD_INTERFACE_Read8(d_cx);
    d_cx = 1;   retval = LCD_INTERFACE_Read8(d_cx);
    sprintf( val_str, "MAC=%02X", retval );
    
//    lv_obj_t * btn = lv_btn_create(lv_scr_act(), NULL);     /*Add a button the current screen*/
//    lv_obj_set_pos(btn, 10, 10);                            /*Set its position*/
//    lv_obj_set_size(btn, 100, 50);                          /*Set its size*/
//    
//    lv_btn_set_action(btn, LV_BTN_ACTION_CLICK, btn_action);/*Assign a callback to the button*/
//    lv_obj_t * label = lv_label_create(btn, NULL);          /*Add a label to the button*/
//    lv_label_set_text(label, val_str);                     /*Set the labels text*/
//
//    lv_obj_t * btn2 = lv_btn_create(lv_scr_act(), NULL);     /*Add a button the current screen*/
//    lv_obj_set_pos(btn2, 10, 70);                            /*Set its position*/
//    lv_obj_set_size(btn2, 100, 50);                          /*Set its size*/
//    
//    lv_btn_set_action(btn2, LV_BTN_ACTION_CLICK, btn_action);/*Assign a callback to the button*/
//    lv_obj_t * label2 = lv_label_create(btn2, NULL);          /*Add a label to the button*/
//    lv_label_set_text(label2, "Condor");                     /*Set the labels text*/

    color.full = (tcnj_gold[2] << 16) | (tcnj_gold[1] << 8) | tcnj_gold[0];
    ili9488_fill(0, 0, 319, 479, color);
    
    color.full = (tcnj_blue[2] << 16) | (tcnj_blue[1] << 8) | tcnj_blue[0];
    ili9488_fill(20, 30, 299, 459, color);
    
    ili9488_zoom( 40, 60, 159, 230, (lv_color_t *) roscoe_img);

    while (1)
    {
        uint8_t write_buf[1] = {0x0};
        uint8_t read_buf[7];
        int     xp;
        int     yp;
        
        //lv_task_handler();
        CyDelay(5);

        while (I2C_MASTER_MasterStatus() & I2C_MASTER_MSTAT_XFER_INP) {}
        I2C_MASTER_MasterWriteBuf( CTP_I2C_ADDR, write_buf, 1, I2C_MASTER_MODE_COMPLETE_XFER );
        
        while (I2C_MASTER_MasterStatus() & I2C_MASTER_MSTAT_XFER_INP) {}
        I2C_MASTER_MasterReadBuf(  CTP_I2C_ADDR, read_buf,  7, I2C_MASTER_MODE_COMPLETE_XFER );

        while (I2C_MASTER_MasterStatus() & I2C_MASTER_MSTAT_XFER_INP) {}
        
        xp = ((read_buf[3] << 8) + read_buf[4]) & 0x1FF;
        yp = ((read_buf[5] << 8) + read_buf[6]) & 0x1FF;
        
        //sprintf( val_str, "xp=%04X", (read_buf[3] << 8) + read_buf[4] );
        //lv_label_set_text(label2, val_str);
    }
}
