#!/usr/bin/python
import sys,re
if sys.version_info[0]>=3: raw_input=input
inside_css=False
for _ in range(int(raw_input())):
	s=raw_input().strip()
	if not s:
		pass
	elif s[-1]=='{':
		inside_css=True
	elif s[-1]=='}':
		inside_css=False
	elif inside_css:
		for e in re.finditer(r'#[0-9a-fA-F]+',s):
			if len(e.group(0))==4 or len(e.group(0))==7: print(e.group(0))