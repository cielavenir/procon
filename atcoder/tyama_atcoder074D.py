#!/usr/bin/python
def f(l,m,n,d):
	s=0;q=[]
	for i in range(l,m,d):s+=a[i];heappush(q,a[i]*d)
	r=[s]
	for i in range(m,n,d):s+=a[i];heappush(q,a[i]*d);s-=heappop(q)*d;r+=[s]
	return r
import sys;from heapq import*;n,*a=list(map(int,sys.stdin.read().split()));print(max(x-y for x,y in zip(f(0,n,2*n,1),reversed(f(3*n-1,2*n-1,n-1,-1)))))
