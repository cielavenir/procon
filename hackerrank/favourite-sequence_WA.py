#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input
r=set()
for i in range(int(raw_input())):
	raw_input()
	r.update({int(e) for e in raw_input().split()})
print(' '.join(map(str,sorted(r))))

'''
2
3
68 7 18
10
67 46 11 99 48 69 57 19 45 95

67 46 11 68 7 18 99 48 69 57 19 45 95
'''