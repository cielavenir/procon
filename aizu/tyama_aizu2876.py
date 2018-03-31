#!/usr/bin/python
import sys,heapq
n=int(sys.stdin.readline())
a=[int(e) for e in sys.stdin.readline().split()]
r=[]
x=[]
y=[]
for i in range(1,n+1):
	heapq.heappush(x,a[i-1])
	heapq.heappush(y,a[n-i])
	while x and y and x[0]==y[0]:
		heapq.heappop(x)
		heapq.heappop(y)
	if not x and not y: r.append(i)
print(' '.join(str(e) for e in r))
