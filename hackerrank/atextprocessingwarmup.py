#!/usr/bin/python
month=['january','february','march','april','may','june','july','august','september','october','november','december']
import sys
if sys.version_info[0]>=3: raw_input=input
for i in range(int(raw_input())):
	txt=''.join(e.lower() for e in raw_input().rstrip() if e.isalnum() or e=='/' or e==' ').split()
	print(sum(e=='a' for e in txt))
	print(sum(e=='an' for e in txt))
	print(sum(e=='the' for e in txt))
	print(sum(e in month for e in txt))
	raw_input()