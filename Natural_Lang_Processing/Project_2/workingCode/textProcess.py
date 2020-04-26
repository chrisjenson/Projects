import math
import random

def writeFile():
    with open('training2.txt', 'r') as f, open('training2Pre.txt', 'w') as fo:
        for line in f:
            fo.write(line.replace(' ,',' ').replace(',',' ')
                .replace(' \'\' ',' ').replace('\n',' ').replace(' .', ' </s>\n<s>').replace('.', '')
                .replace('\\/', ' ').replace(' \'', '\'').replace(' `` ',' ').replace('`` ','')
                .replace(' \'\' ', ' ').replace('$', ' ').replace(' $ ', ' ').replace('%', ' ').replace(' % ', ' ')
                .replace('\'', '').replace(' ; ', ' ').replace(' - ', ' ').replace(' & ', ' ').replace(' ` ', '')
                .replace(' :', '').replace(':', '').replace(' :','').replace('--',' ').replace(' -- ',' ')
                .replace(':','').replace('  ',' ').replace('?', ' </s>\n<s>').replace('!', ' </s>\n<s>')
                .replace(' ?', ' </s>\n<s>').replace(' !', ' </s>\n<s>'))
writeFile()
