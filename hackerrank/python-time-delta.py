#!/usr/bin/python
from dateutil.parser import parse
import sys
if sys.version_info[0]>=3: raw_input=input
for _ in range(int(raw_input())):
	s=parse(raw_input())
	t=parse(raw_input())
	print(abs(int((s-t).total_seconds())))