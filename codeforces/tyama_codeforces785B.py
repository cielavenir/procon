#!/usr/bin/python
import sys
a,b=[sorted(
	list(map(int,sys.stdin.readline().split()))
	for _ in range(int(sys.stdin.readline()))
) for _ in range(2)]
print(max(
	max(map(lambda (x,y):max(b[-1][0]-y,0),a)),
	max(map(lambda (x,y):max(a[-1][0]-y,0),b)),
))
