#! /usr/bin/python3

import sys
import os
import re
import subprocess
import numpy as np
import argparse
import scipy.io
import matplotlib.pyplot as plt
import matplotlib as mpl
import pylab

parser = argparse.ArgumentParser()
parser.add_argument('rawfile', help='path of input file, e.g. pf.raw' )

args = parser.parse_args()

rawfile = args.rawfile

if rawfile == "-":
    #print( "Reading from STDIN" )
    fd = sys.stdin
else:
    fd = open( rawfile, "r" )


sys.stdout.write( "const uint32_t bmp_img[] = {\n" );

first_line = 1
while (1):
    r = fd.readline()
    g = fd.readline()
    b = fd.readline()
    
    if r == "":
        break
    
    pattern = "[0-9A-Fa-f]"
    m = re.search( pattern, r )
    if m:

        if first_line != 1:
            sys.stdout.write( ",\n" )
        else:
            first_line = 0

        r = re.search( "\s*([0-9a-fA-F]+)\s*", r )
        r = r.group(1)
        g = re.search( "\s*([0-9a-fA-F]+)\s*", g )
        g = g.group(1)
        b = re.search( "\s*([0-9a-fA-F]+)\s*", b )
        b = b.group(1)

        sys.stdout.write( "    0x00%s%s%s" % (r, g, b) )

        
sys.stdout.write( "\n};\n" )



