#!/usr/bin/python
from heapq import *
import sys
q=[]
while True:
	a=sys.stdin.readline().split()
	if a[0]=='end': break
	if a[0]=='insert':
		heappush(q,-int(a[1]))
	else:
		print(-heappop(q))
