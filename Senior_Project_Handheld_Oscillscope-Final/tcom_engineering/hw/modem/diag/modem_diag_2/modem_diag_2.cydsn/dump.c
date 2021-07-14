#include <stdint.h>
#include <stdio.h>
#include "project.h"
#include "dump.h"


// buf          - pointer to the buffer to be dumped
// size         - number of bytes to dump
// row_size     - how many bytes per terminal line, before newline
// desc_string  - any string that could be helpful in understanding which buffer this is
void
dump_buf( uint8_t *buf, int size, int row_size, char descr_string[] )
{
    int i;
    
    int row_idx;
   
    UART_DEBUG_PutString( "\r\n***********\r\n" );
    UART_DEBUG_PutString(descr_string);
    UART_DEBUG_PutString( "\r\n***********\r\n" );
    
    row_idx = 0;
    for (i = 0; i < size; ++i)
    {
        char the_str[10];
        
        sprintf( the_str, "%02X ", buf[i] );
        UART_DEBUG_PutString(the_str);
        ++row_idx;
        
        if (row_idx == row_size)
        {
            row_idx = 0;
            UART_DEBUG_PutString("\r\n");
            
        }
    }
}