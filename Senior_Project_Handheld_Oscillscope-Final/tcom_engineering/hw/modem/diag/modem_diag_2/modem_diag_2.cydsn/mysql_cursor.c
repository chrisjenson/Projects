
/*
  Copyright (c) 2012, 2016 Oracle and/or its affiliates. All rights reserved.

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; version 2 of the License.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301  USA

  MySQL_Cursor.cpp - Run queries on a MySQL Server

  Change History:

  Version 1.0.0a Created by Dr. Charles A. Bell, April 2012.
  Version 1.0.0b Updated by Dr. Charles A. Bell, October 2013.
  Version 1.0.1b Updated by Dr. Charles A. Bell, February 2014.
  Version 1.0.2b Updated by Dr. Charles A. Bell, April 2014.
  Version 1.0.3rc Updated by Dr. Charles A. Bell, March 2015.
  Version 1.0.4ga Updated by Dr. Charles A. Bell, July 2015.
  Version 1.1.0a Created by Dr. Charles A. Bell, January 2016.
  Version 1.1.1a Created by Dr. Charles A. Bell, January 2016.
*/

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "tcom_cl.h"
#include "project.h"
#include "mysql_cursor.h"
const char BAD_MOJO[]  = "Bad mojo. EOF found reading column header.";
const char ROWS[]  = " rows in result.";
const char READ_COLS[]  = "ERROR: You must read the columns first!";
const char NOT_CONNECTED[]  = "ERROR: Class requires connected server.";

extern uint8_t      *rd_buf;
static int          columns_read;
static int          num_cols;
static column_names columns;
static row_values   row;

static uint8_t      query_buf[1024];
/*
  Constructor

  Requires an instance of the MySQL_Connection class to communicate with a
  MySQL server.

  connection[in]  Connection to a MySQL server - must be connected.
*/


static field_struct field_arr[MAX_FIELDS][128];
   
void
mysql_cursor_constructor( void ) 
{
    #ifdef WITH_SELECT
    columns.num_fields = 0;
    columns_read = 0;

    for (int f = 0; f < MAX_FIELDS; f++) 
    {
        field_struct *field = field_arr[f];
        columns.fields[f] = field;
    }
    #endif
}



/*
  execute - Execute a SQL statement

  This method executes the query specified as a character array. It copies
  the query to the local buffer then calls the execute_query() method to
  execute the query.

  If a result set is available after the query executes, the field
  packets and rows can be read separately using the get_field() and
  get_row() methods.

  query[in]       SQL statement (using normal memory access)
  progmem[in]     True if string is in program memory

  Returns boolean - True = a result set is available for reading
*/
int 
mysql_execute(int socket_num, const char *query)
{
    int query_len;   // length of query

    //  if (!conn->connected()) {
    //    UART_DEBUG_PutString("NOT_CONNECTED\r\n");
    //    return -1;
    //  }

    query_len = (int)strlen((char *)query);

    memcpy(query_buf + 5, query, query_len);

    // Send the query
    return mysql_execute_query(socket_num, query_len);
}


/*
  execute_query - execute a query

  This method sends the query string to the server and waits for a
  response. If the result is a result set, it returns true, if it is
  an error, it processes the error packet and prints the error via
  Serial.print(). If it is an Ok packet, it parses the packet and
  returns false.

  query_len[in]   Number of bytes in the query string

  Returns boolean - true = result set available,
                    false = no result set returned.
*/
int 
mysql_execute_query(int socket_num, int query_len)
{
    store_int(query_buf, query_len+1, 3);
    query_buf[3] = 0x00;
    query_buf[4] = 0x03;  // command packet

    // Send the query
    tcom_cl_write_binary_at_cmds(socket_num, query_len + 5 , (uint8_t*)query_buf);
    //conn->client->write((uint8_t*)query_buf, query_len + 5);

    // Read a response packet and check it for Ok or Error.
    read_packet(socket_num);
    int res = get_packet_type();
    if (res == MYSQL_ERROR_PACKET) 
    {
        parse_error_packet();
        return 0;
    } else if (res == MYSQL_OK_PACKET || res == MYSQL_EOF_PACKET) 
    {
    return 1;
    }

    // Not an Ok packet, so we now have the result set to process.
#ifdef WITH_SELECT
    columns_read = 0;
#endif
    return 1;
}

#ifdef WITH_SELECT
/*
  Close

  Takes care of removing allocated memory.
*/
void 
mysql_close() 
{
    UART_DEBUG_PutString( "Closing ... \r\n" );
}

/*
  get_columns - Get a list of the columns (fields)

  This method returns an instance of the column_names structure
  that contains an array of fields.

  Note: you should call free_columns_buffer() after consuming
        the field data to free memory.
*/
column_names 
*mysql_get_columns(int socket_num) 
{
    num_cols = 0;
    if (mysql_get_fields(socket_num)) 
    {
        columns_read = 1;
        return &columns;
    }
    else 
    {
        return NULL;
    }
}

/*
  get_next_row - Iterator for reading rows from a result set

  This method returns an instance of a structure (row_values)
  that contains an array of strings representing the row
  values returned from the server.

  The caller can use the values however needed - by first
  converting them to a specific type or as a string.
*/
row_values 
*mysql_get_next_row(int socket_num) 
{
    int res = 0;

    // Read the rows
    res = mysql_get_row_values(socket_num);
    if (res != MYSQL_EOF_PACKET) 
    {
        return &row;
    }
    return NULL;
}


/*
  show_results - Show a result set from the server via Serial.print

  This method reads a result from the server and displays it via the
  via the Serial.print methods. It can be used in cases where
  you may want to issue a SELECT or SHOW and see the results on your
  computer from the Arduino.

  It is also a good example of how to read a result set from the
  because it uses the public methods designed to return result
  sets from the server.
*/
void 
mysql_show_results(int socket_num) 
{
    char the_str[10];

    column_names *cols;
    int rows = 0;

    // Get the columns
    cols = mysql_get_columns(socket_num);
    if (cols == NULL) 
    {
        return;
    }

    for (int f = 0; f < columns.num_fields; f++) 
    {

        UART_DEBUG_PutString( (char *) columns.fields[f] );
        //Serial.print(columns.fields[f]->name);
        if (f < columns.num_fields-1)
            UART_DEBUG_PutChar(',');
    }
    UART_DEBUG_PutString("\r\n");

    // Read the rows
    while (mysql_get_next_row( socket_num)) 
    {
        rows++;
        for (int f = 0; f < columns.num_fields; f++) 
        {
            UART_DEBUG_PutString( row.values[f] );
            if (f < columns.num_fields-1)
            UART_DEBUG_PutChar(',');
        }
        UART_DEBUG_PutString("\r\n");
    }

    // Report how many rows were read
    sprintf( the_str, "%d", rows );
    UART_DEBUG_PutString(the_str);
    //conn->show_error(ROWS, true);

    // Free any post-query messages in queue for stored procedures
    mysql_clear_ok_packet( socket_num);
}


/*
  clear_ok_packet - clear last Ok packet (if present)

  This method reads the header and status to see if this is an Ok packet.
  If it is, it reads the packet and discards it. This is useful for
  processing result sets from stored procedures.

  Returns False if the packet was not an Ok packet.
*/
int 
mysql_clear_ok_packet(int socket_num) 
{
    int num = 0;
    int err_code;

    do {
        err_code = bytes_in_stream(socket_num, &num);

    //num = conn->client->available();
        if (num > 0) 
        {
            read_packet(socket_num);
            if (get_packet_type() != MYSQL_OK_PACKET) 
            {
                parse_error_packet();
                return 0;
            }
        }
    } while (num > 0);
    UART_DEBUG_PutString("mysql clear ok packet :***");
    UART_DEBUG_PutChar(err_code);
    UART_DEBUG_PutString("***\r\n");
    return 1;
}


/*
  free_columns_buffer - Free memory allocated for column names

  This method frees the memory allocated during the get_columns()
  method.

  NOTICE: Failing to call this method after calling get_columns()
          and consuming the column names, types, etc. will result
          in a memory leak. The size of the leak will depend on
          the size of the combined column names (bytes).
*/
//void mysql_free_columns_buffer() {
//  num_cols = 0;
//  columns_read = 0;
//}


/*
  free_row_buffer - Free memory allocated for row values

  This method frees the memory allocated during the get_next_row()
  method.

  NOTICE: You must call this method at least once after you
          have consumed the values you wish to process. Failing
          to do will result in a memory leak equal to the sum
          of the length of values and one byte for each max cols.
*/
//void mysql_free_row_buffer() {
//  // clear the row
//}


/*
  read_string - Retrieve a string from the buffer

  This reads a string from the buffer. It reads the length of the string
  as the first byte.

  offset[in]      offset from start of buffer

  Returns string - String from the buffer
*/
char *mysql_read_string(int *offset) 
{
    static char str[1024];

    int len_bytes = get_lcb_len(rd_buf[*offset]);
    int len = read_int(*offset, len_bytes);
    //char *str = (char *)malloc(len+1);
    strncpy(str, ((char *)rd_buf) + *offset + len_bytes, len);
    str[len] = 0x00;
    *offset += len_bytes+len;
    return str;
}


/*
  get_field - Read a field from the server

  This method reads a field packet from the server. Field packets are
  defined as:

  Bytes                      Name
  -----                      ----
  n (Length Coded String)    catalog
  n (Length Coded String)    db
  n (Length Coded String)    table
  n (Length Coded String)    org_table
  n (Length Coded String)    name
  n (Length Coded String)    org_name
  1                          (filler)
  2                          charsetnr
  4                          length
  1                          type
  2                          flags
  1                          decimals
  2                          (filler), always 0x00
  n (Length Coded Binary)    default

  Note: the sum of all db, column, and field names must be < 255 in length
*/
int mysql_get_field(int socket_num, field_struct *fs) 
{
    int len_bytes;
    int len;
    int offset;

    // Read field packets until EOF
    read_packet(socket_num);
    if (rd_buf[4] != MYSQL_EOF_PACKET) 
    {
        // calculate location of db
        len_bytes = get_lcb_len(4);
        len = read_int(4, len_bytes);
        offset = 4+len_bytes+len;
        fs->db = mysql_read_string(&offset);
        // get table
        fs->table = mysql_read_string(&offset);
        // calculate location of name
        len_bytes = get_lcb_len(offset);
        len = read_int(offset, len_bytes);
        offset += len_bytes+len;
        fs->name = mysql_read_string(&offset);
        return 0;
    }
    return MYSQL_EOF_PACKET;
}


/*
  get_row - Read a row from the server and store it in the buffer

  This reads a single row and stores it in the buffer. If there are
  no more rows, it returns MYSQL_EOF_PACKET. A row packet is defined as
  follows.

  Bytes                   Name
  -----                   ----
  n (Length Coded String) (column value)
  ...

  Note: each column is store as a length coded string concatenated
        as a single stream

  Returns integer - MYSQL_EOF_PACKET if no more rows, 0 if more rows available
*/
int mysql_get_row(int socket_num) {
  // Read row packets
  read_packet(socket_num);
  if (rd_buf[4] != MYSQL_EOF_PACKET)
    return 0;
  return MYSQL_EOF_PACKET;
}


/*
  get_fields - reads the fields from the read buffer

  This method is used to read the field names, types, etc.
  from the read buffer and store them in the columns structure
  in the class.
*/


int mysql_get_fields(int socket_num)
{
  int num_fields = 0;
  int res = 0;

  
  num_fields = rd_buf[4]; // From result header packet
  columns.num_fields = num_fields;
  num_cols = num_fields; // Save this for later use
  for (int f = 0; f < num_fields; f++) {
    field_struct *field = field_arr[f];
    res = mysql_get_field(socket_num, field);
    if (res == MYSQL_EOF_PACKET) {
      //conn->show_error(BAD_MOJO, true);
      UART_DEBUG_PutString("Bad mojo. EOF found reading column header.");
      return 0;
    }
    columns.fields[f] = field;
  }
  read_packet(socket_num); // EOF packet
  return 1;
}


/*
  get_row_values - reads the row values from the read buffer

  This method is used to read the row column values
  from the read buffer and store them in the row structure
  in the class.
*/
int mysql_get_row_values(int socket_num) {
  int res = 0;
  int offset = 0;

  // It is an error to try to read rows before columns
  // are read.
  if (!columns_read) {
    UART_DEBUG_PutString("ERROR: You must read the columns first!");
    return MYSQL_EOF_PACKET;
  }
  // Drop any row data already read
  //free_row_buffer();

  // Read a row
  res = mysql_get_row(socket_num);
  if (res != MYSQL_EOF_PACKET) {
    offset = 4;
    for (int f = 0; f < num_cols; f++) {
      row.values[f] = mysql_read_string(&offset);
    }
  }
  return res;
}  
#endif // WITH_SELECT
