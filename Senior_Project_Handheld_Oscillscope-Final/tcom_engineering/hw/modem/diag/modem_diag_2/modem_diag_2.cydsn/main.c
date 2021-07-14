#include "project.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "tcom_cl.h"
#include "mysql_cursor.h"
#include "dump.h"

extern uint8_t buffer[];

   //      send_at_cmd( "USOWR", "3,12,\"Hello world!\"", 19 );
   //
   //          would cause the following to be sent to the modem:
   //
   //              AT+USOWR=3,12,"Hello world!"
   //
   //      The function automatically inserts "AT+", and the "="
   //
//   void send_at_cmd( char *command_name, uint8_t *wdata, int num_bytes_of_wdata );


   // Deposits incoming data into the array 'data'
   //
//   void get_bytes( uint8_t *rdata, int num_bytes_to_get );

char INSERT_SQL[] = "INSERT INTO test_tcom.hello_tcom (message) VALUES ('Hello, TCOM');";
char query[] = "SELECT * FROM test_tcom.hello_tcom WHERE num < 3;";


int
connection(unsigned int a , unsigned int b, unsigned int c, unsigned int d, int port)
{
    char cmd_str[256];
    CyDelay(1000);
    
    send_raw_cmd_txt( "AT");
    wait_for_substr_or_error( "OK", TIMEOUT );
    
    send_at_cmd_txt( "CFUN", "1" );
    wait_for_substr_or_error( "OK", TIMEOUT );
    
    send_raw_cmd_txt( "ATE0" );
    wait_for_substr_or_error( "OK", TIMEOUT );
    
    send_raw_cmd_txt( "AT" );
    wait_for_substr_or_error( "OK", LONG_TIMEOUT );
    
    send_at_cmd_txt( "UPSDA", "0,3" );
    wait_for_substr_or_error( "OK", LONG_TIMEOUT );
    
    send_at_cmd_txt( "CREG", "1" );
    wait_for_substr_or_error( "OK", TIMEOUT );
    
    send_at_cmd_txt("UPSND","0,0");
    wait_for_substr_or_error( "OK", TIMEOUT );
    
    send_at_cmd_txt( "USOCR", "6" );
    wait_for_substr_or_error( "+USOCR:", TIMEOUT );
 
    sprintf( cmd_str, "0,\"%d.%d.%d.%d\",%d", a ,b , c , d, port );
    send_at_cmd_txt( "USOCO", cmd_str);  
    if (wait_for_substr_or_error( "OK", TIMEOUT ) == 0)
        return 0;
    else 
        return -1;    
}

int
connect(unsigned int a , unsigned int b, unsigned int c, unsigned int d, int port, char *user,char *password)
{
    
    int connected = -1;
    int retries = MAX_CONNECT_ATTEMPTS;
    
    // Retry up to MAX_CONNECT_ATTEMPTS times.
    while (retries--)
    {
        connected = connection(a,b,c,d, port);
        if (connected == 0)
            break;

        CyDelay(CONNECT_DELAY_MS);
    }
    
    if (connected != 0)
        return -1;
    
    //send_at_question_txt( "CREG");
    //wait_for_substr_or_error( "OK", LONG_TIMEOUT );
    
    read_packet(0); // '0' socket num
    parse_handshake_packet();
    send_authentication_packet(user, password);
    read_packet(0);
    if (get_packet_type() != MYSQL_OK_PACKET) {
        parse_error_packet();
        return -1;
    }else
        return 1;
    
    
}


int
main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    //int err_flag;
    
    UART_Start();
    UART_DEBUG_Start();
    
    LCD_Start();
    LCD_Position( 0, 0 );
    LCD_PrintString( "Hi there!" );
    
    DTR_Write(0);       // Active low
    SIM_DET_Write(1);   // Indicate to module that a SIM is detected

//    AT+CFUN=1
//    AT+UPSDA=0,3
//    AT+USOCR=6
//    AT+USOCO=0[SOCKET NUM.],"AA.BB.CC.DD",3303[PORT NUM.]
//    AT+USOWR=0[SOCKET NUM.],12[LENGTH OF THE PACKAGE],"Hello World!"[PACKAGE IN ""]
//    AT+USOCL=0[SOCKET NUM.]
//    server[in]      IP address of the server as IPAddress type
//    port[in]        port number of the server
//    user[in]        user name
//    password[in]    (optional) user password
    char user[]     = "host";
    char password[] = "12345678";
    mysql_cursor_constructor();
    if(connect(3,88,212,103, 3306, user, password)==1)
    {
        //send_at_question_txt( "CREG");
        //wait_for_substr_or_error( "OK", LONG_TIMEOUT );
        
        UART_DEBUG_PutString("CONNECTION MADE\r\n");
        
          // mysql_execute(0,INSERT_SQL);
          row_values *row = NULL;

          CyDelay(1000);

          UART_DEBUG_PutString("\r\n*****----hello_tcom----*****\r\n");
          // Initiate the query class instance
            //MySQL_Cursor *cur_mem = new MySQL_Cursor(&conn);
          // Execute the query
          mysql_execute(0,query);
          // Fetch the columns (required) but we don't use them.

          column_names *cols = mysql_get_columns(0);
          for (int f = 0; f < cols->num_fields; f++) {
            UART_DEBUG_PutString(cols->fields[f]->name);
            if (f < cols->num_fields-1) {
              UART_DEBUG_PutChar(',');
            }
          }
          UART_DEBUG_PutString("\r\n");
          // Read the rows and print them
          do {
            row = mysql_get_next_row(0);
            if (row != NULL) {
              for (int f = 0; f < cols->num_fields; f++) {
                UART_DEBUG_PutString(row->values[f]);
                if (f < cols->num_fields-1) {
                  UART_DEBUG_PutChar(',');
                }
              }
              UART_DEBUG_PutString("\r\n");
            }
          } while (row != NULL);
          UART_DEBUG_PutString("\r\n*****end of the data*****\r\n");
        

        send_at_cmd_txt( "USOCL", "0" );
        wait_for_substr_or_error( "OK", LONG_TIMEOUT );
   
    }else
        UART_DEBUG_PutString("\r\nFAILED ON CONNECTION!!\r\n");
    
}

