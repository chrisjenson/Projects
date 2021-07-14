#include "tcom_drv.h"

// Call `lv_tick_inc(x)` every `x` milliseconds **in a Timer or Task** (`x` should be between 1 and 10). It is required for the internal timing of LittlevGL. **It's very important that you don't call `lv_task_handler` in the same loop.**
// Call `lv_task_handler()` periodically every few milliseconds in the main `while(1)` loop, in Timer interrupt or in an Operation system task. It will redraw the screen if required, handle input devices etc. **It's very important that you don't call `lv_tick_inc` in the same loop.**

bool
touchpad_read(lv_indev_data_t * data)
{
    data->point.x = 100;
    data->point.y = 100;
    return false;
}

void
ili9488_init()
{
    GraphicLCDIntf_1_Start();
    
    Pin_9_Write(1); // Turns on backlight

    d_cx = 0;   GraphicLCDIntf_1_Write8(d_cx, DSPL_SLEEP_OUT);
    CyDelay(10);
    
    d_cx = 0;   GraphicLCDIntf_1_Write8(d_cx, DSPL_DISPLAY_ON);
    CyDelay(10);
}

void
ili9488_flush(int32_t x1, int32_t y1, int32_t x2, int32_t y2, const lv_color_t *color_p)
{
    int     d_cx;
    
    d_cx = 0;   GraphicLCDIntf_1_Write8(d_cx, DSPL_COL_ADDR_SET);
    d_cx = 1;   GraphicLCDIntf_1_Write8(d_cx, BYTE_HI(x1));
                GraphicLCDIntf_1_Write8(d_cx, BYTE_LO(x1));
                GraphicLCDIntf_1_Write8(d_cx, BYTE_HI(x2));
                GraphicLCDIntf_1_Write8(d_cx, BYTE_LO(x2));

    d_cx = 0;   GraphicLCDIntf_1_Write8(d_cx, DSPL_PAG_ADDR_SET);
    d_cx = 1;   GraphicLCDIntf_1_Write8(d_cx, BYTE_HI(y1));
                GraphicLCDIntf_1_Write8(d_cx, BYTE_LO(y1));
                GraphicLCDIntf_1_Write8(d_cx, BYTE_HI(y2));
                GraphicLCDIntf_1_Write8(d_cx, BYTE_LO(y2));

    d_cx = 0;   GraphicLCDIntf_1_Write8(d_cx, DSPL_MEM_WR);
    d_cx = 1;

    for(y = y1; y <= y2; y++) 
    {
        for(x = x1; x <= x2; x++) 
        {
            uint8_t r;
            uint8_t g;
            uint8_t b;
            
            uint32_t val;
            
            val = *color_p;
            
            r = (val >> 16) & 0xFF;
            g = (val >>  8) & 0xFF;
            b = (val >>  0) & 0xFF;
            
            GraphicLCDIntf_1_Write8(d_cx, b);
            GraphicLCDIntf_1_Write8(d_cx, g);
            GraphicLCDIntf_1_Write8(d_cx, r);
            
            color_p++;
        }
    }    
    
    lv_flush_ready();                  /* Tell you are ready with the flushing*/
}

int
lv_res_t btn_action(lv_obj_t * btn)
{
    return LV_RES_OK;
}    

main( void )
{
    lv_init();
    
    lv_disp_drv_t   disp_drv;
    lv_indev_drv_t indev_drv;

    lv_disp_drv_init(&disp_drv);        // Basic initialization
    disp_drv.disp_flush = ili9488_flush;
    lv_disp_drv_register(&disp_drv);    // Register the driver in LittlevGL

    lv_indev_drv_init(&indev_drv);     // Descriptor of a input device driver
    indev_drv.type = LV_INDEV_TYPE_POINTER;    /*Touch pad is a pointer-like device*/
    indev_drv.read = touchpad_read;            /*Set your driver function*/
    lv_indev_drv_register(&indev_drv);         /*Finally register the driver*/

    lv_obj_t * btn = lv_btn_create(lv_scr_act(), NULL);     /*Add a button the current screen*/
    lv_obj_set_pos(btn, 10, 10);                            /*Set its position*/
    lv_obj_set_size(btn, 100, 50);                          /*Set its size*/
    
    lv_btn_set_action(btn, LV_BTN_ACTION_CLICK, btn_action);/*Assign a callback to the button*/
    lv_obj_t * label = lv_label_create(btn, NULL);          /*Add a label to the button*/
    lv_label_set_text(label, "Button");                     /*Set the labels text*/

    while (1)
    {
        lv_task_handler();
        CyDelay(5);
    }
}
