::turn off output to the termimal
@echo off

::run a python script with following parameters
::python %~dp0dbQuery.py %1 %2 %3 %4 %5 %6

::change directory to that of bat file and make it the working directory
cd /d %~dp0
dbQuery.exe %1 %2 %3 %4 %5 %6 %7

::1 "%7" == "1" connect and return csv table
::2 "%7" == "2" test connection 
::3 "%7" == "3" connect and send sql command (send command)
::4 "%7" == "4" connect and return single text value (systemDate)   
    
::%1 is host name
::%2 is service name
::%3 is user ID
::%4 is user password
::%5 is the port#
::%6 is the sql string
::%7 is the action type