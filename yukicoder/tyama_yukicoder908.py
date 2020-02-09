#!/usr/bin/python
import sys
s=sys.stdin.readline()
print('Yes' if all(getattr(e,['islower','isspace'][i%2])() for i,e in enumerate(s)) else 'No')
