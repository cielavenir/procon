#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input
N = int(raw_input())
print('Weird' if N%2 or 6<=N<=20 else 'Not Weird')