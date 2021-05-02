#!/usr/bin/python
import sys
N,K=map(int,sys.stdin.readline().split())
A=sorted([int(e) for e in sys.stdin.readline().split()] for _ in range(N))
x,y=zip(*A)
Y=sorted(y)
r=(x[-1]-x[0])*(Y[-1]-Y[0])
for i in range(N):
 for j in range(i+1,N):
  for k in range(N):
   for l in range(k+1,N):
    ly=Y[k];ry=Y[l];q=(x[j]-x[i])*(ry-ly)
    if r>q and K<=(j-i+1) and K<=sum(ly<=y[z]<=ry for z in range(i,j+1)): r=q
print(r)
