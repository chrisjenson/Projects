#include "project.h"
#include "lv_conf.h"
#include "lvgl.h"
#include "lv_conf.h"

#include "stdio.h"
//#include "yolo_tengo_310x480.h" 
//#include "swirly_80x120.h"

#define DO_IMAGES
#ifdef DO_IMAGES
#include "blow.c"
#include "message.c"
#include "ribbons.c"
#include "team.c"
#endif

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
    UART_KITPROG_USB_PutString( val_str );
//    lv_label_set_text(label2, val_str);

    
    data->point.x = xp;
    data->point.y = yp;
    
    if (event_flag == 2)    data->state = LV_INDEV_STATE_PR;         
    else                    data->state = LV_INDEV_STATE_REL;        
    
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
ili9488_zoom(int32_t x1, int32_t y1, int32_t wid, int32_t hgt, const lv_color_t *color_p)
{
    int     D_CX;
    int     x2;
    int     y2;
    int     y;
    int     x;
    
    x2 = x1 + wid - 1;
    y2 = y1 + hgt - 1;
    
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

static int btn_anime_state = 0;

lv_res_t btn_action(lv_obj_t * btn)
{
    btn_anime_state = 1;
    return LV_RES_OK;
}

void
btn_anime(void)
{
    static lv_obj_t     *my_label = NULL;
    static lv_obj_t     *my_btn = NULL;
    static lv_style_t   btn_style;
    static lv_style_t   lbl_style;

    static lv_style_t   style_led;
    static lv_obj_t     *led_arr[10];

    static lv_obj_t     *init_screen;
    
    if (btn_anime_state == 1)
    {
        init_screen = lv_scr_act();
        
        my_btn = lv_obj_create(NULL, NULL);
        lv_scr_load(my_btn);
        lv_obj_set_size(my_btn, 320, 480);                        /*Set its size*/

        lv_style_copy(&btn_style, lv_obj_get_style(my_btn));
        btn_style.body.main_color.full = 0x40C0FF;
        btn_style.body.grad_color.full = btn_style.body.main_color.full;
        btn_style.body.empty = 0;
        lv_obj_set_style( my_btn, &btn_style );
        
        my_label = lv_label_create(my_btn, NULL);
        lv_style_copy(&lbl_style, lv_obj_get_style(my_label));
        lv_label_set_text( my_label, "Hold breath for\n10 seconds ...\n\n... then breathe\ninto device\nslowly for\n15 seconds" );
        lv_obj_align( my_label, NULL, LV_ALIGN_IN_TOP_LEFT, 5,100 );
        lv_label_set_long_mode(my_label, LV_LABEL_LONG_EXPAND);
        lbl_style.text.font = &lv_font_dejavu_40;
        lv_label_set_style(my_label, &lbl_style);

        lv_style_copy(&style_led, &lv_style_pretty_color);
        style_led.body.radius       = LV_RADIUS_CIRCLE;
        style_led.body.main_color   = LV_COLOR_MAKE(0x04, 0x0f, 0xb5);
        style_led.body.grad_color   = LV_COLOR_MAKE(0x02, 0x07, 0x50);
        style_led.body.border.color = LV_COLOR_MAKE(0x00, 0x0f, 0xfa);
        style_led.body.border.width = 3;
        style_led.body.border.opa   = LV_OPA_30;
        style_led.body.shadow.color = LV_COLOR_MAKE(0x04, 0x0f, 0xb5);
        style_led.body.shadow.width = 10;

            /*Create a LED and switch it ON*/
        int i = 0;
        led_arr[i] = lv_led_create(my_btn, NULL);
        lv_obj_set_size(led_arr[i], 25, 25);
        lv_obj_set_style(led_arr[i], &style_led);
        lv_obj_align(led_arr[i], NULL, LV_ALIGN_IN_TOP_RIGHT, -10, 50);
        lv_led_set_bright( led_arr[i], 20 );
        for (i = 1; i < 10; ++i)
        {
            /*Copy the previous LED and set a brightness*/
            led_arr[i] = lv_led_create(lv_scr_act(), led_arr[0]);
            lv_obj_set_size(led_arr[i], 25, 25);
            lv_obj_align(led_arr[i], led_arr[i-1], LV_ALIGN_OUT_BOTTOM_MID, 0, 15);
            lv_led_set_bright( led_arr[i], 20 );
        }
    }
    
    if (btn_anime_state != 0)
    {
        int led_num;
    
        led_num = btn_anime_state/800;
        
        if (led_num <= 10)
        {
            for (int i = 0; i < led_num; ++i)
            {
                lv_led_on(led_arr[i]);
            }
            btn_anime_state += 5;
        }
        else if (led_num < 20)
        {
            btn_anime_state += 5;
        }
        else
        {
            lv_obj_del(my_label);
            lv_obj_del(my_btn);
            lv_scr_load(init_screen);
            
            btn_anime_state = 0;
        }
    }
}    

#define FILL_WID (320)
#define FILL_HGT (480)


void Interrupt_Handler_DISP_TICK(void)
{
    lv_tick_inc(1);
    DISP_TICK_TIMER_GetStatus();
    /* Clear the interrupt */
    DISP_TICK_TIMER_ClearInterrupt(CY_TCPWM_INT_ON_TC);
}

extern cy_stc_scb_i2c_context_t I2C_MASTER_context;
int
main( void )
{
    GPIO_PRT_Type   *port_addr;
    
    lv_disp_drv_t   disp_drv;
    lv_indev_drv_t indev_drv;

    __enable_irq(); /* Enable global interrupts. */

    /* Initialize the interrupt with vector at Interrupt_Handler_Port0() */
    Cy_SysInt_Init(&DISP_TICK_ISR_cfg, &Interrupt_Handler_DISP_TICK);
    /* Enable the interrupt */
    NVIC_EnableIRQ(DISP_TICK_ISR_cfg.intrSrc);
    
//    CLOCK_2_Enable();
    LCD_INTERFACE_Start();
    I2C_MASTER_Start();
    DISP_TICK_TIMER_Start();
    UART_KITPROG_USB_Start();    
    
    lv_init();
    ili9488_init();
    
    lv_theme_t *th = lv_theme_material_init(30, &lv_font_dejavu_20);       //Set a HUE value and a Font for the Night Theme
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
    lv_indev_init();
    
    /* Set the port address */
    port_addr = GPIO_PRT6;

    // P6_2 (Backlight control)
    CY_SET_REG32(&port_addr->OUT, _CLR_SET_FLD32U(port_addr->OUT, GPIO_PRT_OUT_OUT2, 1u));
    
    int retval;
    const int icn_sz    = 140;
    
    const int h_ban_1 = 20;
    const int h_lab_1 = 10;
    const int h_lab_2 = 170;

    const int v_ban_1 = 10;
    const int v_ban_2 = 40;
    const int v_lab_1 = 90;
    const int v_img_1 = 130;
    const int v_lab_2 = 290;
    const int v_img_2 = 330;

    const char co_btn_txt[]  = "Measure\nBreath";
    const char gam_btn_txt[] = "Collect\nRibbons";
    const char msg_btn_txt[] = "Messages\nFor You";
    const char ci_btn_txt[]  = "Check In";
    
    const int  btn_wid       = 140;
    const int  btn_hgt       = 40;
    
    lv_obj_t   *my_label;
    lv_style_t* lbl_style;
    
    lbl_style = lv_label_get_style(my_label);
    
    lv_obj_t *btn1 = lv_btn_create(lv_scr_act(), NULL);             /*Add a button the current screen*/
    lv_obj_set_pos(btn1, h_lab_1, v_lab_1);                   /*Set its position*/
    lv_obj_set_size(btn1, btn_wid, btn_hgt);                        /*Set its size*/
    lv_btn_set_action(btn1, LV_BTN_ACTION_CLICK, btn_action);       /*Assign a callback to the button*/
    lv_obj_t *label1 = lv_label_create(btn1, NULL);                 /*Add a label to the button*/
    my_label = label1;
    lv_label_set_text(my_label, co_btn_txt);                        /*Set the labels text*/
    lv_label_set_align(my_label, LV_LABEL_ALIGN_CENTER );
    lbl_style = lv_label_get_style(my_label);
    lbl_style->text.color.full = 0x000000;
    
    lv_obj_t *btn2 = lv_btn_create(lv_scr_act(), NULL);             /*Add a button the current screen*/
    lv_obj_set_pos(btn2, h_lab_2, v_lab_1);   /*Set its position*/
    lv_obj_set_size(btn2, btn_wid, btn_hgt);                        /*Set its size*/
    lv_btn_set_action(btn2, LV_BTN_ACTION_CLICK, btn_action);       /*Assign a callback to the button*/
    lv_obj_t *label2 = lv_label_create(btn2, NULL);                 /*Add a label to the button*/
    my_label = label2;
    lv_label_set_text(my_label, gam_btn_txt);                       /*Set the labels text*/
    lv_label_set_align(my_label, LV_LABEL_ALIGN_CENTER );

    lv_obj_t *btn3 = lv_btn_create(lv_scr_act(), NULL);             /*Add a button the current screen*/
    lv_obj_set_pos(btn3, h_lab_1, v_lab_2);   /*Set its position*/
    lv_obj_set_size(btn3, btn_wid, btn_hgt);                        /*Set its size*/
    lv_btn_set_action(btn3, LV_BTN_ACTION_CLICK, btn_action);       /*Assign a callback to the button*/
    lv_obj_t *label3 = lv_label_create(btn3, NULL);                 /*Add a label to the button*/
    my_label = label3;
    lv_label_set_text(my_label, msg_btn_txt);                       /*Set the labels text*/
    lv_label_set_align(my_label, LV_LABEL_ALIGN_CENTER );

    lv_obj_t *btn4 = lv_btn_create(lv_scr_act(), NULL);              /*Add a button the current screen*/
    lv_obj_set_pos(btn4, h_lab_2, v_lab_2);   /*Set its position*/
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

#ifdef DO_IMAGES

    lv_obj_t * img1 = lv_img_create(lv_scr_act(), NULL);
    lv_img_set_src(img1, &blow);
    lv_obj_align(img1, NULL, LV_ALIGN_IN_TOP_LEFT, h_lab_1, v_img_1);
    
    lv_obj_t * img2 = lv_img_create(lv_scr_act(), NULL);
    lv_img_set_src(img2, &ribbons);
    lv_obj_align(img2, NULL, LV_ALIGN_IN_TOP_LEFT, h_lab_2, v_img_1);
    
    lv_obj_t * img3 = lv_img_create(lv_scr_act(), NULL);
    lv_img_set_src(img3, &message);
    lv_obj_align(img3, NULL, LV_ALIGN_IN_TOP_LEFT, h_lab_1, v_img_2);
    
    lv_obj_t * img4 = lv_img_create(lv_scr_act(), NULL);
    lv_img_set_src(img4, &team);
    lv_obj_align(img4, NULL, LV_ALIGN_IN_TOP_LEFT, h_lab_2, v_img_2);

#endif
    
    while (1)
    {
        lv_task_handler();
        btn_anime();
        CyDelay(5);
    }
}
