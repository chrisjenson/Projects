#ifndef TCOM_CL_H
#define TCOM_CL_H  
#define LONG_TIMEOUT            (3000000)
#define TIMEOUT                 (5000)
#define CONNECT_DELAY_MS        (1000)
#define MAX_CONNECT_ATTEMPTS    (5)
#define MYSQL_DATA_TIMEOUT      (3000)   // Wifi client wait in milliseconds
#define MYSQL_WAIT_INTERVAL     (10)     // WiFi client wait interval
#define MAX_PKT_LEN             (1024)
#define CLOCK_TICKS_PER_MS      (24000)
    
#define MYSQL_OK_PACKET         0x00
#define MYSQL_EOF_PACKET        0xfe
#define MYSQL_ERROR_PACKET      0xff
#define MYSQL_VERSION_STR       "1.1.1a"
 
int 
get_lcb_len(int offset);

int 
read_int(int offset, int size);

int
get_packet_type();
    
int
wait_for_substr_or_error( char substr[], int timeout );

int
parse_usord_resp( int req_len, int socket_num, uint8_t buffer[] );

int
wait_until_at_least_n_bytes_in_stream( int n , int socket_num);

int
bytes_in_stream(int socket_num, int *bytes_avail);

void
tcom_cl_write_binary_at_cmds(int socket_num, int size , uint8_t buffer[]);

void 
store_int(uint8_t *buff, long value, int size);

void
send_at_question_txt( char *command_name );

void
send_at_cmd_txt( char *command_name, char *wdata );

void 
tcom_cl_write(int socket_num, int size , uint8_t buffer[]);

void
read_packet(int socket_num);

void
send_raw_cmd_txt( char *command_name );

void 
send_authentication_packet(char *user, char *password);

void 
parse_handshake_packet();

void 
parse_error_packet();

#endif