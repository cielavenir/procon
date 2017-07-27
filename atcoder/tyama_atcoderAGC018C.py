#!/usr/bin/python
from heapq import*
X,Y,Z=map(int,input().split());N=X+Y+Z;A=[];p=[];q=[];L=[0];R=[0]
for _ in[0]*N:A.append([int(e)for e in input().split()])
A.sort(key=lambda a:a[0]-a[1])
for i in range(N):
	L+=[L[i]+A[i][1]];heappush(p,A[i][1]-A[i][2]);R+=[R[i]+A[-1-i][0]];heappush(q,A[~i][0]-A[~i][2])
	if i>=Y:L[i+1]-=heappop(p)
	if i>=X:R[i+1]-=heappop(q)
print(max(L[i]+R[~i]for i in range(Y,N-X+1)))
