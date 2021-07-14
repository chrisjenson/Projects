#! /bin/csh

if ( $#argv != 1 ) then

    echo "Usage: ${0:t} <file_root>, where the input file is <file_root>.raw and the output is <file_root>.h"

else

    if ( -f ${1}.raw ) then

        /usr/bin/od -t x1 -An -v -w1 ${1}.raw | hex2header.py - > ${1}.h

    else
    
        echo "Usage: ${0:t} <file_root>, where the input file is <file_root>.raw and the output is <file_root>.h"

    endif
    
endif


