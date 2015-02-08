#!/usr/bin/python
N,P=map(float,input().split())
M=int(N)+1
h=[1.]*M
r=0
for i in range(2,M):
	r+=h[i]
	for j in range(i*2,M,i):h[j]*=1-P
print(r)