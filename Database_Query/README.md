Dependencies:
The Python script requires the cx_Oracle, csv, and sys modules
The connection requires oci.dll, oraociei12.dll, and oraons.dll  

The program accepts seven parameters
1: Host Name
2: Service Name
3: User ID
4: User Pass
5: Port
6: SQL String
7: Action Type

There are four Action Types
1: Connect to the database, query it, write the returned values to a csv, print true/false to txt based on success  
2: Connect to the database, print true/false to txt based on success
3: Connect to the database, send an SQL command, commit the action, print true/false to txt based on success 
4: Connect to the database, query for a single value to be printed, does not print true/false
	should be prefaced by a call using Action Type 2 to ensure a connection

The executable is called by a bat file since it was previously mulitple executables.
It first attempts to connect to the database using User ID (string), User Pass (string),
Host Hame (string), Port (int), and then Service Name (string); in that order. If there
is an SQL string to execute, a cursor is created and the string executed. If a change 
was made than it is than committed. If data was requested, the cursor fetches it. 
Action Type 1 will write the fetched data to a csv with headers and Action Type 2
will write the data to a txt. The connection and cursor are then closed. For Action
Type 1,2,3 a [1] or [0] is printed depending on the success of the connection to the
database as a check. In the monitor this print is written to response.txt to confirm.
Action Type 1 is mainly used for Get Messages and Update Linkage Lable, the data is 
writen to a csv called reqData. Type 2 is for checking the connection. Type 3 is for 
Send CMD, inserts into a table in the database. Type 4 is used for Send CMD, gets the 
system date from the database.
