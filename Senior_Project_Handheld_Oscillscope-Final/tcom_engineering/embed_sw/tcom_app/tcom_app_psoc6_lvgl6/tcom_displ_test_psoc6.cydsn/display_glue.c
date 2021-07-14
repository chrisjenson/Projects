#include <stdio.h>
#include "project.h"
#include "lvgl.h"
#include "my_macros.h"
#include "display_glue.h"

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

static uint8_t linebuf[LV_HOR_RES_MAX*3];

//I swapped the x's and y's in the below
//original:   ili9488_map(int32_t x1, int32_t y1, int32_t x2, int32_t y2, const lv_color_t *color_p)
//Pearlstein: ili9488_map(int32_t y2, int32_t x1, int32_t y1, int32_t x2, const lv_color_t *color_p)

void
ili9488_map(int32_t x1, int32_t y1, int32_t x2, int32_t y2, const lv_color_t *color_p)
{
    int     D_CX;
    int     y;
    int     x;
    
    uint8_t *lbuf;
    
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
        lbuf = linebuf;
        
        for(x = x1; x <= x2; x++) 
        {
//            uint8_t r;
//            uint8_t g;
//            uint8_t b;
            
            uint32_t val;
            
            val = (*color_p).full;
            
            *lbuf++ = (val >>  0) & 0xFF;
            *lbuf++ = (val >>  8) & 0xFF;
            *lbuf++ = (val >> 16) & 0xFF;

            //r = (val >> 16) & 0xFF;
            //g = (val >>  8) & 0xFF;
            //b = (val >>  0) & 0xFF;
            
            //LCD_INTERFACE_Write8(D_CX, b);
            //LCD_INTERFACE_Write8(D_CX, g);
            //LCD_INTERFACE_Write8(D_CX, r);
            
            color_p++;
        }
        LCD_INTERFACE_WriteM8_A1(linebuf, (x2-x1+1)*3);
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

/** MANDATORY: Write the internal buffer (VDB) to the display. 'lv_disp_flush_ready()' has to be
 * called when finished */
void my_flush_cb(struct _disp_drv_t * disp_drv, const lv_area_t * area, lv_color_t * color_p)
{
    ili9488_map(area->x1, area->y1, area->x2, area->y2, color_p);
    //for (int src_row = area->y1; src_row <= area->y2; ++src_row)
    //{  
        // Draw a column on the display according to a row in the buffer passed to my_flush_cb
        //ili9488_map(area->x1, area->y1, area->x2, area->y2, color_p);
    //    ili9488_map(LV_VER_RES_MAX-1-src_row, area->x1, LV_VER_RES_MAX-src_row, area->x2, color_p);
        
    //    color_p += (area->x2 - area->x1 + 1);       // advance the pointer to the next source row
    //}
    
    lv_disp_flush_ready(disp_drv);
}

