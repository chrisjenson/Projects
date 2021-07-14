#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include "project.h"
#include "tcom_cl.h"
#include "tcom_mysql_encrypt_sha1.h"
#include "dump.h"
#include "ctype.h"


#define MIN(x, y)           ( (x) <= (y) ? (x) : (y) )

uint8_t             rd_buf[1200];      // Big buffer, but still need to do error checking everywhere!!

static uint8_t      wr_buf[1200];      // Big buffer, but still need to do error checking everywhere!!
static uint8_t      big_buf[2048];
static int          packet_len;
static uint8_t      seed[20];
static char         the_str[3];

int millis( void )
{
    return CySysTickGetValue()/CLOCK_TICKS_PER_MS;
}
/*
   int n = number of OKs to wait for
   int timeout = timeout delay in milliseconds

   Returns:
       0 = no error
       1 = timeout
*/
void
send_at_question_txt( char *command_name )
{
    char            the_char;
    
    // Get rid of any characters sitting in the RXD buffer
    UART_DEBUG_PutString( "\r\n... Flushing ... \r\n" );
    while (UART_GetRxBufferSize())
    {
        the_char = UART_ReadRxData();
        UART_DEBUG_PutChar( '<' );
        if (the_char >= 0x20 && the_char <= 0x7E)
            UART_DEBUG_PutChar( the_char );
        else
        {
            sprintf( the_str, "%02X", the_char );
            UART_DEBUG_PutString( the_str );
        }
        UART_DEBUG_PutChar( '>' );
    }
    UART_DEBUG_PutChar( '\r' );
    UART_DEBUG_PutChar( '\n' );
    
    sprintf( (char *)wr_buf, "AT+%s?\r", command_name );
    UART_PutString( (char *) wr_buf );

    UART_DEBUG_PutString( (char *) wr_buf );
    UART_DEBUG_PutChar( '\r' );
    UART_DEBUG_PutChar( '\n' );
}

void
send_raw_cmd_txt( char *command_name )
{
    char            the_char;
    
    // Get rid of any characters sitting in the RXD buffer
    UART_DEBUG_PutString( "\r\n... Flushing ... \r\n" );
    while (UART_GetRxBufferSize())
    {
        the_char = UART_ReadRxData();
        UART_DEBUG_PutChar( '<' );
        if (the_char >= 0x20 && the_char <= 0x7E)
            UART_DEBUG_PutChar( the_char );
        else
        {
            sprintf( the_str, "%02X", the_char );
            UART_DEBUG_PutString( the_str );
        }
        UART_DEBUG_PutChar( '>' );
    }
    UART_DEBUG_PutChar( '\r' );
    UART_DEBUG_PutChar( '\n' );
    
    sprintf( (char *)wr_buf, "%s\r" , command_name );
    UART_PutString( (char *) wr_buf );

    UART_DEBUG_PutString( (char *) wr_buf );
    UART_DEBUG_PutChar( '\r' );
    UART_DEBUG_PutChar( '\n' );
}
void
send_at_cmd_txt( char *command_name, char *wdata )
{
    char            the_char;
    
    // Get rid of any characters sitting in the RXD buffer
    UART_DEBUG_PutString( "\r\n... Flushing ... \r\n" );
    while (UART_GetRxBufferSize())
    {
        the_char = UART_ReadRxData();
        UART_DEBUG_PutChar( '<' );
        if (the_char >= 0x20 && the_char <= 0x7E)
                UART_DEBUG_PutChar( the_char );
        else
        {
            sprintf( the_str, "%02X", the_char );
            UART_DEBUG_PutString( the_str );
        }
        UART_DEBUG_PutChar( '>' );
    }
    UART_DEBUG_PutChar( '\r' );
    UART_DEBUG_PutChar( '\n' );
    
    sprintf( (char *)wr_buf, "AT+%s=%s\r", command_name, wdata );
    
    UART_PutString( (char *) wr_buf );

    UART_DEBUG_PutString( (char *) wr_buf );
    UART_DEBUG_PutChar( '\r' );
    UART_DEBUG_PutChar( '\n' );
}

void
tcom_cl_write_binary_at_cmds(int socket_num, int size , uint8_t buffer[])
{
    sprintf( (char *) big_buf, "AT+USOWR=%d,%d\r", socket_num, size );       // big_buf gets, for example 0,12,"

    UART_PutString( (char *) big_buf );
    
    if (wait_for_substr_or_error( "@" , LONG_TIMEOUT)==0)
    {
        CyDelay(100);
        UART_PutArray( (uint8_t *) buffer, size );
    }    
    
    wait_for_substr_or_error("OK", LONG_TIMEOUT);
    
    dump_buf(buffer, size, 16 , "tcom_cl_write_binary_at_cmds()");
}
#if 0
void
send_at_cmd_binary( char *command_name, char *wdata, int binary_data_size )
{

    
    // Get rid of any characters sitting in the RXD buffer
    UART_DEBUG_PutString( "\n... Flushing ... \n" );
    while (UART_GetRxBufferSize())
    {
        the_char = UART_ReadRxData();
        //UART_DEBUG_PutChar( '.' );
        UART_DEBUG_PutChar( the_char );
        //UART_DEBUG_PutChar( '.' );
    }
    UART_DEBUG_PutChar( '\n' );
    UART_DEBUG_PutChar( '\n' );
    
    sprintf( (char *)buffer, "AT+%s=", command_name );
    prefix_len = strlen( (char *) buffer);
    
    memcpy( buffer + prefix_len, wdata, binary_data_size );
    buffer[prefix_len+binary_data_size]='\r';
    
    
    UART_PutArray( (uint8_t *) buffer, prefix_len+binary_data_size+1 );
    UART_DEBUG_PutString("***");
    UART_DEBUG_PutArray( (uint8_t *) buffer, prefix_len+binary_data_size+1 );
    UART_DEBUG_PutString("***");
}
#endif

int
wait_for_substr_or_error( char substr[], int timeout )
{
   // If we encounter ERROR or timeout, then return a value of -1
   // If we succeed, return value of 0
   
    int     substr_len;
    int     substr_match_idx;
    int     start_time;
    int     time_elapsed;
    
    char   err_str[6] = "ERROR";
    int      err_idx;
    
    uint8_t the_char;
    
    //char     debug_str[256];
    
    start_time = millis();
    
    substr_len = strlen( substr );
    
    //sprintf( debug_str, "start_time=%d, timeout=%d, waiting for %d OKs\n", start_time, timeout, n );
    //UART_DEBUG_PutString( debug_str );
    
    do
    {
        time_elapsed = millis() - start_time;
        
        while (UART_GetRxBufferSize() == 0) {}     // wait until at least 1 char in UART buffer

        the_char = UART_ReadRxData();
        UART_DEBUG_PutChar( the_char );
        
        if (the_char == substr[substr_match_idx])
            ++substr_match_idx;
        else 
            substr_match_idx = 0;
        
        if (the_char == err_str[err_idx])
            ++err_idx;
        else
            err_idx = 0;
        

    } while (substr_match_idx < substr_len && time_elapsed < timeout && err_idx < 5);
        
    if (time_elapsed >= timeout)
    {
        UART_DEBUG_PutString( "TIMEOUT!!!\r\n" );
        return -1;
    }else if (err_idx == 5)
    {
        UART_DEBUG_PutString("\r\n");
        UART_DEBUG_PutString("matched --> ");
        UART_DEBUG_PutString( "ERROR\r\n" );
        return -1;
    }
    else{
        UART_DEBUG_PutString("\r\n");
        UART_DEBUG_PutString("matched --> ");
        UART_DEBUG_PutString(substr);
        UART_DEBUG_PutString("\r\n");
        return 0;
    }
}



void
tcom_cl_write(int socket_num, int size , uint8_t buffer[])
{
    //send_at_cmd_txt( "USOWR", (char *) big_buf );

    sprintf( (char *) big_buf, "%d,%d,\"", socket_num, size );       // big_buf gets, for example 0,12,"

    int prefix_size = strlen((char *)big_buf);  // all text

    strcpy( (char *)big_buf + prefix_size, (char *)buffer );          // copy binary data into big buf

    big_buf[prefix_size + size] = '\"';                     
    big_buf[prefix_size + size + 1] = '\0';
    
    send_at_cmd_txt( "USOWR", (char *) big_buf);
    
    UART_DEBUG_PutString( (char *)big_buf );
    UART_DEBUG_PutString( " &&&& \r\n");
    
}


int
parse_usord_resp( int req_len, int socket_num, uint8_t buffer[] )
{
    char    socket_info[64];
    char    the_char;
    
    int     time_elapsed;
    int     start_time;
    int     buffer_idx;
 
    // Wait for the string:
    //      +USORD:
    
    //  Issue:
    //      AT+USORD=<socket>,0
    //
    //  Parse response:
    //      get <# of bytes = resp_len>
    
    sprintf(socket_info, "%d,%d", socket_num, req_len);
    send_at_cmd_txt( "USORD", socket_info );
    sprintf(socket_info, "+USORD: %d,%d,\"" , socket_num, req_len);
    
    start_time = millis();
    
    if((wait_for_substr_or_error( socket_info , LONG_TIMEOUT ) == 0))
    {
        // Collect bytes until non-numeric character, i.e. not in range 0-9
        // But also, return with error if exceed timeout
        buffer_idx = 0;
        
        while (1)
        {
            if (UART_GetRxBufferSize() != 0)
            {
                the_char = UART_ReadRxData();
                UART_DEBUG_PutChar( the_char );
                
                buffer[buffer_idx] = the_char;
                ++buffer_idx;
                
                if (buffer_idx == req_len)
                    break;
            }
            time_elapsed = millis() - start_time;
            if (time_elapsed >= LONG_TIMEOUT)
                return( -1 );
        }
    }
    else
        return( -1 );
        
    return(0);   
    char str[20];
    sprintf(str, "parse_usord_resp(%d)", req_len);
    dump_buf( buffer,  req_len, 16, str);
    UART_DEBUG_PutString( "\r\n" );
}

/*
 wait_for_bytes - Wait until data is available for reading

  This method is used to permit the connector to respond to servers
  that have high latency or execute long queries. The timeout is
  set by MYSQL_DATA_TIMEOUT. Adjust this value to match the performance of
  your server and network.

  It is also used to read how many bytes in total are available from the
  server. Thus, it can be used to know how large a data burst is from
  the server.

  bytes_need[in]    Bytes count to wait for

  Returns integer - Number of bytes available to read.

=================================================================
*/


int
wait_until_at_least_n_bytes_in_stream( int n , int socket_num)
{
    char    socket_info[64];
    char    stream_len_str[16];
    char    the_char;
    
    int     time_elapsed;
    int     start_time;
    int     stream_len_str_idx;
    int     resp_len;
    
    start_time = millis();

    do
    {
    //  Issue:
    //      AT+USORD=<socket>,0
    //
    //  Parse response:
    //      get <# of bytes = resp_len>
        sprintf(socket_info, "%d,0", socket_num);
        send_at_cmd_txt( "USORD", socket_info );
        sprintf(socket_info, "+USORD: %d," , socket_num);
        if((wait_for_substr_or_error( socket_info , LONG_TIMEOUT ) == 0))
        {
            
            stream_len_str_idx = 0;
            while (1)
            {
                if (UART_GetRxBufferSize() != 0)
                {
                    the_char = UART_ReadRxData();
                    UART_DEBUG_PutChar( the_char );
                    
                    if (the_char >= '0' && the_char <= '9')
                    {
                        stream_len_str[stream_len_str_idx] = the_char;
                        ++stream_len_str_idx;
                    }
                    else
                    {
                        stream_len_str[stream_len_str_idx] = '\0';
                        break;
                    }
                }
                
                time_elapsed = millis() - start_time;
                if (time_elapsed >= LONG_TIMEOUT)
                    break;
            }
            
            // Did we exit normally?
            if (time_elapsed >= LONG_TIMEOUT || stream_len_str_idx == 0)
                return( -1 );
        }
        else
            return( -1 );   // We timed out waiting for expected prefix to the stream length
        
        sscanf( stream_len_str, "%d", &resp_len );  // get an integer value from the characters extracted
        
        CyDelay(5);
    } while (resp_len < n);
    
    UART_DEBUG_PutString( "Total digits : " );
    UART_DEBUG_PutString( stream_len_str );
    UART_DEBUG_PutString( "\r\n" );

    return( 0 );
}

int
bytes_in_stream(int socket_num, int *bytes_avail)
{
    char    socket_info[64];
    char    stream_len_str[16];
    char    the_char;
    
    int     time_elapsed;
    int     start_time;
    int     stream_len_str_idx;
    int     resp_len;
    
    start_time = millis();

    //  Issue:
    //      AT+USORD=<socket>,0
    //
    //  Parse response:
    //      get <# of bytes = resp_len>
    sprintf(socket_info, "%d,0", socket_num);
    send_at_cmd_txt( "USORD", socket_info );
    sprintf(socket_info, "+USORD: %d," , socket_num);
    if((wait_for_substr_or_error( socket_info , LONG_TIMEOUT ) == 0))
    {
        
        stream_len_str_idx = 0;
        while (1)
        {
            if (UART_GetRxBufferSize() != 0)
            {
                the_char = UART_ReadRxData();
                UART_DEBUG_PutChar( the_char );
                
                if (the_char >= '0' && the_char <= '9')
                {
                    stream_len_str[stream_len_str_idx] = the_char;
                    ++stream_len_str_idx;
                }
                else
                {
                    stream_len_str[stream_len_str_idx] = '\0';
                    break;
                }
            }
            
            time_elapsed = millis() - start_time;
            if (time_elapsed >= LONG_TIMEOUT)
                break;
        }
        
        // Did we exit normally?
        if (time_elapsed >= LONG_TIMEOUT || stream_len_str_idx == 0)
            return( -1 );
    }
    else
    return( -1 );   // We timed out waiting for expected prefix to the stream length

    sscanf( stream_len_str, "%d", &resp_len );  // get an integer value from the characters extracted
        
    
    UART_DEBUG_PutString( "Total digits : " );
    UART_DEBUG_PutString( stream_len_str );
    UART_DEBUG_PutString("\r\n");

    *bytes_avail = resp_len;
    
    return( 0 );
}

/*
  read_packet - Read a packet from the server and store it in the buffer

  This method reads the bytes sent by the server as a packet. All packets
  have a packet header defined as follows.

  Bytes                 Name
  -----                 ----
  3                     Packet Length
  1                     Packet Number

  Thus, the length of the packet (not including the packet header) can
  be found by reading the first 4 bytes from the server then reading
  N bytes for the packet payload.
*/

void
 read_packet(int socket_num) {
    uint8_t local[4];
    
    int     bytes_received;
    int     req_len;
    
    wait_until_at_least_n_bytes_in_stream( 4 , socket_num);     // Need first 4 bytes to get packet length
    
    parse_usord_resp(4, socket_num, rd_buf);
    // issue_usord( 4, local );        // Get 4 bytes from the stream in local
    for ( int i=0; i<4; i++)
        local[i] = rd_buf[i];

    // Get packet length
    packet_len = local[0];
    packet_len += (local[1] << 8);
    packet_len += ((uint32_t)local[2] << 16);
#if 0 
    UART_DEBUG_PutString( "\nHere is the first 4 byte in the packet \n" );
    UART_DEBUG_PutChar( local[0] );
    UART_DEBUG_PutChar( local[1] );
    UART_DEBUG_PutChar( local[2] );
    UART_DEBUG_PutChar( local[3] );
    UART_DEBUG_PutString( "   \n");
#endif
    bytes_received = 0;
    do
    {
        req_len = MIN(MAX_PKT_LEN, packet_len);

        wait_until_at_least_n_bytes_in_stream( req_len, socket_num );

        parse_usord_resp( req_len, socket_num, rd_buf + bytes_received + 4 );
        // rd_buf[bytes_received + 4]

        bytes_received += req_len;

        packet_len -= req_len;

    } while (packet_len > 0);
    
    dump_buf( rd_buf,  bytes_received + 4, 16, "read_packet()");
}

/*
  scramble_password - Build a SHA1 scramble of the user password

  This method uses the password hash seed sent from the server to
  form a SHA1 hash of the password. This is used to send back to
  the server to complete the challenge and response step in the
  authentication handshake.

  password[in]    User's password in clear text
  pwd_hash[in]    Seed from the server

  Returns boolean - True = scramble succeeded
*/

int 
scramble_password(char *password, uint8_t *pwd_hash) {
  uint8_t *digest;
  uint8_t hash1[20];
  uint8_t hash2[20];
  uint8_t hash3[20];
  uint8_t pwd_buffer[40];

  if (strlen(password) == 0)
    return (0);

  // hash1
  sha1_init();
  sha1_write_2((uint8_t *)password, strlen(password));
  digest = sha1_result();
  memcpy(hash1, digest, 20);

  // hash2
  sha1_init();
  sha1_write_2(hash1, 20);
  digest = sha1_result();
  memcpy(hash2, digest, 20);

  // hash3 of seed + hash2
  sha1_init();
  memcpy(pwd_buffer, &seed, 20);
  memcpy(pwd_buffer+20, hash2, 20);
  sha1_write_2(pwd_buffer, 40);
  digest = sha1_result();
  memcpy(hash3, digest, 20);

  // XOR for hash4
  for (int i = 0; i < 20; i++)
    pwd_hash[i] = hash1[i] ^ hash3[i];

  return 1;
}  

/*
  send_authentication_packet

  This method builds a response packet used to respond to the server's
  challenge packet (called the handshake packet). It includes the user
  name and password scrambled using the SHA1 seed from the handshake
  packet. It also sets the character set (default is 8 which you can
  change to meet your needs).

  Note: you can also set the default database in this packet. See
        the code before for a comment on where this happens.

  The authentication packet is defined as follows.

  Bytes                        Name
  -----                        ----
  4                            client_flags
  4                            max_packet_size
  1                            charset_number
  23                           (filler) always 0x00...
  n (Null-Terminated String)   user
  n (Length Coded Binary)      scramble_buff (1 + x bytes)
  n (Null-Terminated String)   databasename (optional

  user[in]        User name
  password[in]    password
*/
void 
send_authentication_packet(char *user, char *password)
{
  
  int size_send = 4;

  // client flags
  wr_buf[size_send] =   0x85;
  wr_buf[size_send+1] = 0xa6;
  wr_buf[size_send+2] = 0x03;
  wr_buf[size_send+3] = 0x00;
  size_send += 4;

  // max_allowed_packet
  wr_buf[size_send] = 0;
  wr_buf[size_send+1] = 0;
  wr_buf[size_send+2] = 0;
  wr_buf[size_send+3] = 1;
  size_send += 4;

  // charset - default is 8
  wr_buf[size_send] = 0x08;
  size_send += 1;
  for(int i = 0; i < 24; i++)
    wr_buf[size_send+i] = 0x00;
  size_send += 23;

  // user name
  memcpy((char *)&wr_buf[size_send], user, strlen(user));
  size_send += strlen(user) + 1;
  wr_buf[size_send-1] = 0x00;

  // password - see scramble password

  static uint8_t scramble[20];

  if (scramble_password(password, scramble)) {
    wr_buf[size_send] = 0x14;
    size_send += 1;
    for (int i = 0; i < 20; i++)
      wr_buf[i+size_send] = scramble[i];
    size_send += 20;
    wr_buf[size_send] = 0x00;
  }

  // terminate password response
  wr_buf[size_send] = 0x00;
  size_send += 1;

  // database
  wr_buf[size_send+1] = 0x00;
  size_send += 1;

  // Write packet size
  int p_size = size_send - 4;
  store_int(&wr_buf[0], p_size, 3);
  wr_buf[3] = 0x01;

  // Write the packet
  
  dump_buf( wr_buf, size_send, 16, "send_authentication_packet()");
  tcom_cl_write_binary_at_cmds(0, size_send , (uint8_t*)wr_buf);
  
}


   

/*
  parse_handshake_packet - Decipher the server's challenge data

  This method reads the server version string and the seed from the
  server. The handshake packet is defined as follows.

   Bytes                        Name
   -----                        ----
   1                            protocol_version
   n (Null-Terminated String)   server_version
   4                            thread_id
   8                            scramble_buff
   1                            (filler) always 0x00
   2                            server_capabilities
   1                            server_language
   2                            server_status
   2                            server capabilities (two upper bytes)
   1                            length of the scramble seed
  10                            (filler)  always 0
   n                            rest of the plugin provided data
                                (at least 12 bytes)
   1                            \0 byte, terminating the second part of
                                 a scramble seed
*/
void 
parse_handshake_packet() 
{

    char server_version[100];

    int i;
    int j;

    i = 5;
    do {
        i++;
    } while (rd_buf[i-1] != 0x00);

    strncpy(server_version, (char *)&rd_buf[5], i-5);

    // Capture the first 8 characters of seed
    i += 4; // Skip thread id
    for ( j = 0; j < 8; j++) {
        seed[j] = rd_buf[i+j];
    }

    // Capture rest of seed
    i += 27; // skip ahead
    for ( j = 0; j < 12; j++) {
        seed[j+8] = rd_buf[i+j];
    }

    dump_buf( rd_buf, i+j, 16, "parse_handshake_packet()");
    
}

/*
  parse_error_packet - Display the error returned from the server

  This method parses an error packet from the server and displays the
  error code and text via Serial.print. The error packet is defined
  as follows.

  Note: the error packet is already stored in the buffer since this
        packet is not an expected response.

  Bytes                       Name
  -----                       ----
  1                           field_count, always = 0xff
  2                           errno
  1                           (sqlstate marker), always '#'
  5                           sqlstate (5 characters)
  n                           message
*/
void parse_error_packet() {
#ifdef DEBUG
    char my_string[32];
    UART_DEBUG_PutString("Error: ");
    sprintf(my_string , "%d" , read_int(5, 2));
    UART_DEBUG_PutString(my_string);
    UART_DEBUG_PutString(" = ");

    for (int i = 0; i < packet_len-9; i++)
        UART_DEBUG_PutChar((char)rd_buf[i+13]);
    UART_DEBUG_PutString(".");
    #endif
}

/*
  get_lcb_len - Retrieves the length of a length coded binary value

  This reads the first byte from the offset into the buffer and returns
  the number of bytes (size) that the integer consumes. It is used in
  conjunction with read_int() to read length coded binary integers
  from the buffer.

  Returns integer - number of bytes integer consumes
*/
int get_lcb_len(int offset) {
  int read_len = rd_buf[offset];
  if (read_len > 250) {
    // read type:
    uint8_t type = rd_buf[offset+1];
    if (type == 0xfc)
      read_len = 2;
    else if (type == 0xfd)
      read_len = 3;
    else if (type == 0xfe)
      read_len = 8;
  }
  return 1;
}

/*
  read_int - Retrieve an integer from the buffer in size bytes.

  This reads an integer from the buffer at offset position indicated for
  the number of bytes specified (size).

  offset[in]      offset from start of buffer
  size[in]        number of bytes to use to store the integer

  Returns integer - integer from the buffer
*/
int read_int(int offset, int size) {
  int value = 0;
  int new_size = 0;
  if (size == 0)
     new_size = get_lcb_len(offset);
  if (size == 1)
     return rd_buf[offset];
  new_size = size;
  int shifter = (new_size - 1) * 8;
  for (int i = new_size; i > 0; i--) {
    value += (uint8_t)(rd_buf[i-1] << shifter);
    shifter -= 8;
  }
  return value;
}


/*
  store_int - Store an integer value into a byte array of size bytes.

  This writes an integer into the buffer at the current position of the
  buffer. It will transform an integer of size to a length coded binary
  form where 1-3 bytes are used to store the value (set by size).

  buff[in]        pointer to location in internal buffer where the
                  integer will be stored
  value[in]       integer value to be stored
  size[in]        number of bytes to use to store the integer
*/
void store_int(uint8_t *buff, long value, int size) {
  memset(buff, 0, size);
  if (value < 0xff)
    buff[0] = (uint8_t)value;
  else if (value < 0xffff) {
    buff[0] = (uint8_t)value;
    buff[1] = (uint8_t)(value >> 8);
  } else if (value < 0xffffff) {
    buff[0] = (uint8_t)value;
    buff[1] = (uint8_t)(value >> 8);
    buff[2] = (uint8_t)(value >> 16);
  } else if (value < 0xffffff) {
    buff[0] = (uint8_t)value;
    buff[1] = (uint8_t)(value >> 8);
    buff[2] = (uint8_t)(value >> 16);
    buff[3] = (uint8_t)(value >> 24);
  }
}


/*
  get_packet_type - Returns the packet type received from the server.

   Bytes                       Name
   -----                       ----
   1   (Length Coded Binary)   field_count, always = 0
   1-9 (Length Coded Binary)   affected_rows
   1-9 (Length Coded Binary)   insert_id
   2                           server_status
   2                           warning_count
   n   (until end of packet)   message

  Returns integer - 0 = successful parse, packet type if not an Ok packet
*/
int get_packet_type() {

  int type = rd_buf[4];
  return type;
}


#if 0
/*
  print_packet - Print the contents of a packet via Serial.print

  This method is a diagnostic method. It is best used to decipher a
  packet from the server (or before being sent to the server). If you
  are looking for additional program memory space, you can safely
  delete this method.
*/
void MySQL_Packet::print_packet() {
  if (!buffer)
    return;

  Serial.print("Packet: ");
  Serial.print(buffer[3]);
  Serial.print(" contains ");
  Serial.print(packet_len+3);
  Serial.println(" bytes.");

  Serial.print("  HEX: ");
  for (int i = 0; i < packet_len+3; i++) {
    Serial.print(buffer[i], HEX);
    Serial.print(' ');
  }
  Serial.println();
  Serial.print("ASCII: ");
  for (int i = 0; i < packet_len+3; i++)
    Serial.print((char)buffer[i]);
  Serial.println();
}

/*
  close - cancel the connection

  This method closes the connection to the server and frees up any memory
  used in the buffer.
*/
void MySQL_Connection::close()
{
  if (connected())
  {
    client->flush();
    client->stop();
    show_error(DISCONNECTED, true);
  }
}

#endif
