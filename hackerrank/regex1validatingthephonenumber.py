#!/usr/bin/python
import sys,re
if sys.version_info[0]>=3: raw_input=input
for i in range(int(raw_input())):
	print('YES' if re.match(r'^[7-9][0-9]{9}$',raw_input().rstrip()) else 'NO')