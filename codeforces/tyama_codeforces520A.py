#!/usr/bin/python
import sys,string
if sys.version_info[0]>=3:raw_input=input
check_pangram=lambda t:string.ascii_uppercase in ''.join(sorted(list(set(t.upper()))))
raw_input()
print('YES' if check_pangram(raw_input()) else 'NO')