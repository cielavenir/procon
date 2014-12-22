#!/usr/bin/python
#Fully compatible on both Python2 and Python3
import sys,itertools
if sys.version_info[0]<3: itertools.zip_longest=itertools.izip_longest
print([''.join(x) for x in zip(*itertools.zip_longest(*[iter('ABCDEFGHIJKLMNOPQRSTUVWXYZ')]*3,fillvalue=''))])
#http://ideone.com/HeXUdG