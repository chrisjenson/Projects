#connects and queries, returns a table of values to csv
import cx_Oracle
import csv
import sys

#get command line parameters
hostName = sys.argv[1]  
serviceName = sys.argv[2]   
userID = sys.argv[3]    
userPswd = sys.argv[4]  
port = int(sys.argv[5], 10)   #string to int base 10 
sqlStr = sys.argv[6]
actionType = int(sys.argv[7], 10)   #2:test con, 1:get data, 4:give command
rval = False

try:
    #connect to database,   string  string                      string    int   string
    con = cx_Oracle.connect(userID, userPswd, cx_Oracle.makedsn(hostName, port, service_name = serviceName))
    rval = True
except (ValueError, AttributeError) as error:
	print(error)

#action type will never not be 1,2,3, or 4
if rval and actionType != 4: 
    print("[1]")    #1 for true/successful connection

if rval and (actionType != 2):
    #create a cursor for 1,3,4
    cursor = con.cursor()
    cursor.execute(sqlStr)  #execute passed in sql string 

    if (actionType == 3):   #commit the insertion
        con.commit()

    #grab the data for 1,4
    if (actionType == 1 or actionType == 4):   #get data from sql execution
        rows = cursor.fetchall()    
        colNames = list(map(lambda x: x[0], cursor.description))    #get column names
    
        if(actionType == 1):    #write to csv for 1
            #"a" to append and "w+"" to truncate and write 
            with open("reqData.csv", "w+", newline='') as csvFile:     #open csvFile w/ requested data
                writer = csv.writer(csvFile)
                #writer.writerow([sqlStr]) #show what sql string was queryed 
                writer.writerow(colNames)   #write the column names
                writer.writerows(rows)  #write all the info
            csvFile.close()
        else:   #if actionType == 4, print data for 4
            print(rows)
    
    #close connections
    cursor.close()
    con.close()
    
if not rval:    #if failed to connect
    print("[0]")    #0 for false