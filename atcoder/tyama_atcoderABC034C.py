#!/usr/bin/python
M=10**9+7;r=1;W,H=map(int,input().split())
for i in range(H-1):r=r*(W+i)*pow(-~i,M-2,M)%M
print(r)