#ifndef MYSQL_QUERY_H
#define MYSQL_QUERY_H

//#include <MySQL_Connection.h>

#define WITH_SELECT          // Comment this if you don't need SELECT queries. 
                             // Reduces memory footprint of the library.
#define MAX_FIELDS    0x04   // Maximum number of fields. Reduce to save memory. Default=32


#ifdef WITH_SELECT
typedef struct {
  char *db;
  char *table;
  char *name;
} field_struct;

// Structure for storing result set metadata.
typedef struct {
  int num_fields;     // actual number of fields
  field_struct *fields[MAX_FIELDS];
} column_names;

// Structure for storing row data.
typedef struct {
  char *values[MAX_FIELDS];
} row_values;
#endif  // WITH_SELECT

    void
    mysql_cursor_constructor( void );
    int 
    mysql_execute(int socket_num, const char *query);
    int 
    mysql_execute_query(int socket_num, int query_len);

    void mysql_close();
    column_names *mysql_get_columns(int socket_num);
    row_values *mysql_get_next_row(int socket_num);
    void mysql_show_results(int socket_num);

    int mysql_clear_ok_packet(int socket_num);

    char *mysql_read_string(int *offset);
    int mysql_get_field(int socket_num, field_struct *fs);
    int mysql_get_row(int socket_num);
    int mysql_get_fields(int socket_num);
    int mysql_get_row_values(int socket_num);
    column_names *mysql_query_result();
    
    #endif
    