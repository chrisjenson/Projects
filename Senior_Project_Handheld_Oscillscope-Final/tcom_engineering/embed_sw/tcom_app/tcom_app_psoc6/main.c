#include "project.h"

#define DLY (0)
#define DSPL_SLEEP_OUT      (0x11)
#define DSPL_DISPLAY_ON     (0x29)
#define DSPL_COL_ADDR_SET   (0x2A)
#define DSPL_PAG_ADDR_SET   (0x2B)
#define DSPL_MEM_WR         (0x2C)
#define DSPL_MEM_RD         (0x2E)

#define BYTE_HI( x )        ( ((x) >> 8) & 0xFF )
#define BYTE_LO( x )        ( ((x) >> 0) & 0xFF )

#define FILL_WID (310)
#define FILL_HGT (470)

int main(void)
{
    int     d_cx;
    int     row_idx;
    int     col_idx;
    
    uint16_t    col_start   = 0;
    uint16_t    col_end     = FILL_WID-1;
    uint16_t    row_start   = 0;
    uint16_t    row_end     = FILL_HGT-1;
    
    CyGlobalIntEnable; /* Enable global interrupts. */
    Timer_Start();
    
    GraphicLCDIntf_1_Start();
    
    Pin_9_Write(1); // Turns on backlight

    d_cx = 0;   GraphicLCDIntf_1_Write8(d_cx, DSPL_SLEEP_OUT);
    CyDelay(10);
    
    while (1)
    {
        d_cx = 0;   GraphicLCDIntf_1_Write8(d_cx, DSPL_DISPLAY_ON);
        CyDelay(DLY);
        
        d_cx = 0;   GraphicLCDIntf_1_Write8(d_cx, DSPL_COL_ADDR_SET);
        d_cx = 1;   GraphicLCDIntf_1_Write8(d_cx, BYTE_HI(col_start));
                    GraphicLCDIntf_1_Write8(d_cx, BYTE_LO(col_start));
                    GraphicLCDIntf_1_Write8(d_cx, BYTE_HI(col_end));
                    GraphicLCDIntf_1_Write8(d_cx, BYTE_LO(col_end));
        CyDelay(DLY);

        d_cx = 0;   GraphicLCDIntf_1_Write8(d_cx, DSPL_PAG_ADDR_SET);
        d_cx = 1;   GraphicLCDIntf_1_Write8(d_cx, BYTE_HI(row_start));
                    GraphicLCDIntf_1_Write8(d_cx, BYTE_LO(row_start));
                    GraphicLCDIntf_1_Write8(d_cx, BYTE_HI(row_end));
                    GraphicLCDIntf_1_Write8(d_cx, BYTE_LO(row_end));
        CyDelay(DLY);

        d_cx = 0;   GraphicLCDIntf_1_Write8(d_cx, DSPL_MEM_WR);
        d_cx = 1;
        CyDelay(DLY);

        for (row_idx = 0; row_idx < FILL_WID; ++row_idx)
        {
            for (col_idx = 0; col_idx < FILL_HGT; ++col_idx)
            {
                int r;
                int g;
                int b;
                r = !((row_idx / 33) % 3);
                g = !((row_idx / 33) % 3);
                b = !((row_idx / 33) % 3);
                
                GraphicLCDIntf_1_Write8(d_cx, 0);
                GraphicLCDIntf_1_Write8(d_cx, 255);
                GraphicLCDIntf_1_Write8(d_cx, 255);
            }
        }
    }
    #if 0
    for(;;)
    {
        GraphicLCDIntf_1_Write8(0, 0xD3);
        
        for (i = 0; i < 4; ++i)
        {
            device_id[i] = GraphicLCDIntf_1_Read8(1);
        }
    }
    #endif
}
