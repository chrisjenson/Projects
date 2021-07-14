#include "project.h"
#include "string.h"
#include "stdio.h"

int row;
int col;
    
int  strs_sent;

void lcd_write( char *str )
{
    int     i;
    int     len;
    char    c;
    
    // if ( (strs_sent % 10) == 0)
    if ( 1 )
    {
        len = strlen(str);
        
        for (i = 0; i < len; ++i)
        {
            c = str[i];
            
            LCD_Character_Display_Position(row, col);
            
            if (c >= 32 && c <= 126)
                LCD_Character_Display_PutChar(c);
            
            ++col;
            
            if (col == 16)
            {
                row = (row + 1) % 2;
                col = 0;
            }
        }
    }
}

int main(void)
{
    char out_str[64];
    
    int  i;
    int  bytes_avail;
    
    CyGlobalIntEnable; /* Enable global interrupts. */

    LCD_Character_Display_Start();
    UART_Start();

    strs_sent = 0;
    row = col = 0;
    for(;;)
    {
        sprintf( out_str, "AT+IPR=115200\015\012" );
        UART_PutString( out_str );
        lcd_write( "*1*" );
        
        CyDelay(1000);
        bytes_avail = UART_GetRxBufferSize();
        
        for (i = 0; i < bytes_avail; ++i)
        {
            char val[2];
            val[1] = '\0';
            
            val[0] = UART_ReadRxData();
            lcd_write(val);
        }

        lcd_write(";");
        
        ++strs_sent;
        #if 0
        sprintf( out_str, "AT&K0\015\012" );
        UART_PutString( out_str );
        lcd_write( "*2*" );
        
        CyDelay(1000);
        bytes_avail = UART_GetRxBufferSize();
        
        for (i = 0; i < bytes_avail; ++i)
        {
            char val[2];
            val[1] = '\0';
            
            val[0] = UART_ReadRxData();
            lcd_write(val);
        }
        lcd_write( ";" );
#endif
    }
}

