#!/usr/bin/python
import sys,re
if sys.version_info[0]>=3: raw_input=input
txt=raw_input().rstrip()+' '
while True:
	x=re.search(r'(.{2,}?)([\.\?\!])[\sA-Z]',txt)
	if not x:break
	s=x.group(1)+x.group(2)
	print(s)
	txt=txt[len(s):]