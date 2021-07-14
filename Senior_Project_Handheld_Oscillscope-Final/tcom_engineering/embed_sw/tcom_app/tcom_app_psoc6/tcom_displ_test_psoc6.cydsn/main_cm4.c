#include "project.h"
#include "lv_conf.h"
#include "lvgl.h"
#include "stdio.h"
#include "yolo_tengo_310x480.h" 
//#include "swirly_80x120.h"

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

    for(y = y1; y < y2+1; y+=2) 
    {
        for (int zoom_idx = 0; zoom_idx < 2; ++zoom_idx)
        {
            for(x = x1; x < x2+1; x+=2) 
            {
                uint8_t r;
                uint8_t g;
                uint8_t b;
                
                uint32_t val;
                
                val = color_p[(x-x1)>>1].full;
                
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
        color_p += ((x2-x1+1)>>1);
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

#define FILL_WID (320)
#define FILL_HGT (480)


void Interrupt_Handler_DISP_TICK(void)
{
    lv_tick_inc(1);
    DISP_TICK_TIMER_GetStatus();
}

extern cy_stc_scb_i2c_context_t I2C_MASTER_context;
int
main( void )
{
    GPIO_PRT_Type   *port_addr;
    
    lv_disp_drv_t   disp_drv;
    lv_indev_drv_t indev_drv;

    cy_stc_scb_i2c_master_xfer_config_t i2c_xfer_config;

    uint8_t write_buf[1] = {0x0};
    uint8_t read_buf[7];

    __enable_irq(); /* Enable global interrupts. */

    /* Initialize the interrupt with vector at Interrupt_Handler_Port0() */
    Cy_SysInt_Init(&DISP_TICK_ISR_cfg, &Interrupt_Handler_DISP_TICK);
    /* Enable the interrupt */
    NVIC_EnableIRQ(DISP_TICK_ISR_cfg.intrSrc);
        
    LCD_INTERFACE_Start();
    I2C_MASTER_Start();
    DISP_TICK_TIMER_Start();
    UART_KITPROG_USB_Start();    
    
    lv_init();
    ili9488_init();
    
    lv_theme_t *th = lv_theme_material_init(30, &lv_font_dejavu_30);       //Set a HUE value and a Font for the Night Theme
    lv_theme_set_current(th);                                               //Apply the theme

    lv_disp_drv_init(&disp_drv);        // Basic initialization
    disp_drv.disp_fill  = ili9488_fill;
    disp_drv.disp_map   = ili9488_map;
    disp_drv.disp_flush = NULL;
    lv_disp_drv_register(&disp_drv);    // Register the driver in LittlevGL

    lv_indev_drv_init(&indev_drv);     // Descriptor of a input device driver
    indev_drv.type = LV_INDEV_TYPE_POINTER;    /*Touch pad is a pointer-like device*/
    indev_drv.read = touchpad_read;            /*Set your driver function*/
    lv_indev_drv_register(&indev_drv);         /*Finally register the driver*/

    /* Set the port address */
    port_addr = GPIO_PRT6;

    // P6_2 (Backlight control)
    CY_SET_REG32(&port_addr->OUT, _CLR_SET_FLD32U(port_addr->OUT, GPIO_PRT_OUT_OUT2, 1u));
    
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

//    int row_idx;
//    int col_idx;
//    for (row_idx = 0; row_idx < FILL_WID; ++row_idx)
//    {
//        for (col_idx = 0; col_idx < FILL_HGT; ++col_idx)
//        {
//            
//            LCD_INTERFACE_Write8(d_cx, 0);
//            LCD_INTERFACE_Write8(d_cx, 255);
//            LCD_INTERFACE_Write8(d_cx, 255);
//        }
//    }

    int retval;
    const char co_btn_txt[]  = "Measure\nBreath\nQuality";
    const char gam_btn_txt[] = "Collect\nRibbons";
    const char msg_btn_txt[] = "Messages\nFor You";
    const char ci_btn_txt[]  = "Check In\nwith your\nTeam";
    
    const int  btn_wid       = 145;
    const int  btn_hgt       = 190;
    const int  btn_h_offs    = 10;
    const int  btn_v_offs    = 85;
    const int  btn_gap       = 10;
    
    lv_obj_t   *my_label;
    lv_style_t* lbl_style;
    
    lbl_style = lv_label_get_style(my_label);
    
    lv_obj_t *btn1 = lv_btn_create(lv_scr_act(), NULL);             /*Add a button the current screen*/
    lv_obj_set_pos(btn1, btn_h_offs, btn_v_offs);                   /*Set its position*/
    lv_obj_set_size(btn1, btn_wid, btn_hgt);                        /*Set its size*/
    lv_btn_set_action(btn1, LV_BTN_ACTION_CLICK, btn_action);       /*Assign a callback to the button*/
    lv_obj_t *label1 = lv_label_create(btn1, NULL);                 /*Add a label to the button*/
    my_label = label1;
    lv_label_set_text(my_label, co_btn_txt);                        /*Set the labels text*/
    lv_label_set_align(my_label, LV_LABEL_ALIGN_CENTER );
    lbl_style = lv_label_get_style(my_label);
    lbl_style->text.color.full = 0x000000;
    
    lv_obj_t *btn2 = lv_btn_create(lv_scr_act(), NULL);             /*Add a button the current screen*/
    lv_obj_set_pos(btn2, btn_h_offs+btn_wid+btn_gap, btn_v_offs);   /*Set its position*/
    lv_obj_set_size(btn2, btn_wid, btn_hgt);                        /*Set its size*/
    lv_btn_set_action(btn2, LV_BTN_ACTION_CLICK, btn_action);       /*Assign a callback to the button*/
    lv_obj_t *label2 = lv_label_create(btn2, NULL);                 /*Add a label to the button*/
    my_label = label2;
    lv_label_set_text(my_label, gam_btn_txt);                       /*Set the labels text*/
    lv_label_set_align(my_label, LV_LABEL_ALIGN_CENTER );

    lv_obj_t *btn3 = lv_btn_create(lv_scr_act(), NULL);             /*Add a button the current screen*/
    lv_obj_set_pos(btn3, btn_h_offs, btn_v_offs+btn_hgt+btn_gap);   /*Set its position*/
    lv_obj_set_size(btn3, btn_wid, btn_hgt);                        /*Set its size*/
    lv_btn_set_action(btn3, LV_BTN_ACTION_CLICK, btn_action);       /*Assign a callback to the button*/
    lv_obj_t *label3 = lv_label_create(btn3, NULL);                 /*Add a label to the button*/
    my_label = label3;
    lv_label_set_text(my_label, msg_btn_txt);                       /*Set the labels text*/
    lv_label_set_align(my_label, LV_LABEL_ALIGN_CENTER );

    lv_obj_t *btn4 = lv_btn_create(lv_scr_act(), NULL);              /*Add a button the current screen*/
    lv_obj_set_pos(btn4, btn_h_offs+btn_wid+btn_gap, btn_v_offs+btn_hgt+btn_gap);   /*Set its position*/
    lv_obj_set_size(btn4, btn_wid, btn_hgt);                        /*Set its size*/
    lv_btn_set_action(btn4, LV_BTN_ACTION_CLICK, btn_action);       /*Assign a callback to the button*/
    lv_obj_t *label4 = lv_label_create(btn4, NULL);                 /*Add a label to the button*/
    lv_label_set_text(label4, ci_btn_txt);                          /*Set the labels text*/
    my_label = label4;
    lv_label_set_text(my_label, ci_btn_txt);                       /*Set the labels text*/
    lv_label_set_align(my_label, LV_LABEL_ALIGN_CENTER );

    static lv_style_t btn_style1;
    static lv_style_t btn_style2;
    static lv_style_t btn_style3;
    static lv_style_t btn_style4;
    
    lv_style_copy(&btn_style1, lv_obj_get_style(btn1));
    lv_style_copy(&btn_style2, lv_obj_get_style(btn2));
    lv_style_copy(&btn_style3, lv_obj_get_style(btn3));
    lv_style_copy(&btn_style4, lv_obj_get_style(btn4));
    
    btn_style1.body.main_color.full = 0x0040C0;
    btn_style1.body.grad_color.full = btn_style1.body.main_color.full;
    lv_btn_set_style( btn1, LV_BTN_STATE_REL, &btn_style1 );
    
    btn_style2.body.main_color.full = 0xC04000;
    btn_style2.body.grad_color.full = btn_style2.body.main_color.full;
    lv_btn_set_style( btn2, LV_BTN_STATE_REL, &btn_style2 );
    
    btn_style3.body.main_color.full = 0x00C040;
    btn_style3.body.grad_color.full = btn_style3.body.main_color.full;
    lv_btn_set_style( btn3, LV_BTN_STATE_REL, &btn_style3 );
    
    btn_style4.body.main_color.full = 0x40C000;
    btn_style4.body.grad_color.full = btn_style4.body.main_color.full;
    lv_btn_set_style( btn4, LV_BTN_STATE_REL, &btn_style4 );
    
    lv_obj_t *label_dat = lv_label_create(lv_scr_act(), NULL);
    lv_label_set_text( label_dat, "Tuesday, September 17  2022" );
    lv_obj_align( label_dat, NULL, LV_ALIGN_IN_TOP_MID, 0,5 );
    
    lv_obj_t *label_tim = lv_label_create(lv_scr_act(), NULL);
    lv_label_set_text( label_tim, "10:28 AM" );
    lv_obj_align( label_tim, NULL, LV_ALIGN_IN_TOP_MID, 0,40 );
    
//    color.full = (tcnj_gold[2] << 16) | (tcnj_gold[1] << 8) | tcnj_gold[0];
//    ili9488_fill(0, 0, 319, 479, color);
//    
//    color.full = (tcnj_blue[2] << 16) | (tcnj_blue[1] << 8) | tcnj_blue[0];
//    ili9488_fill(20, 30, 299, 459, color);
    
    ili9488_map( 5, 0, 314, 479, (lv_color_t *) bmp_img);
    CyDelay(10000);
    
//    ili9488_zoom(   0,   0, 159, 239, (lv_color_t *) swirly_img);
//    ili9488_zoom( 160,   0, 319, 239, (lv_color_t *) swirly_img);
//    ili9488_zoom(   0, 240, 159, 479, (lv_color_t *) swirly_img);
//    ili9488_zoom( 160, 240, 319, 479, (lv_color_t *) swirly_img);
//    CyDelay(5000);
    
    while (1)
    {
//        int     xp;
//        int     yp;
        
        lv_task_handler();
        CyDelay(5);

//        while (I2C_MASTER_MasterGetStatus() & CY_SCB_I2C_MASTER_BUSY) {}
//        i2c_xfer_config.slaveAddress = CTP_I2C_ADDR;    // address of instance
//        i2c_xfer_config.buffer = write_buf;             // buffer
//        i2c_xfer_config.bufferSize = 1;                 // byte count = 1
//        i2c_xfer_config.xferPending = 0;                // complete transfer (generate a STOP)
//        
//        Cy_SCB_I2C_MasterWrite(I2C_MASTER_HW, &i2c_xfer_config, &I2C_MASTER_context);
//        
//        while (I2C_MASTER_MasterGetStatus() & CY_SCB_I2C_MASTER_BUSY) {}
//
//        i2c_xfer_config.buffer = read_buf;             // buffer
//        i2c_xfer_config.bufferSize = 7;                 // byte count = 1
//        Cy_SCB_I2C_MasterRead(I2C_MASTER_HW, &i2c_xfer_config, &I2C_MASTER_context);
//        
//        while (I2C_MASTER_MasterGetStatus() & CY_SCB_I2C_MASTER_BUSY) {}
//        
//        xp = ((read_buf[3] << 8) + read_buf[4]) & 0x3FF;
//        yp = ((read_buf[5] << 8) + read_buf[6]) & 0x3FF;
//        
//        sprintf( val_str, "xp=%04X, yp=%04X\r\n", (read_buf[3] << 8) + read_buf[4], (read_buf[5] << 8) + read_buf[6] );
//        sprintf( val_str, "xp=0.%02d, yp=0.%02d\r\n", xp * 100/320, yp * 100/480 );
//        UART_KITPROG_USB_PutString( val_str );
//        lv_label_set_text(label2, val_str);
    }
}
