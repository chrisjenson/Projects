/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"

int main(void)
{
    __enable_irq(); /* Enable global interrupts. */
    VDAC_1_Start();
    Clock_1_Enable();
    int32_t value = 0;
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        
        VDAC_1_SetValueBuffered(value);
        value++;
        //CyDelayUs(10);
        if(value == 512){
            value = -512;
        }
    }
}

/* [] END OF FILE */
