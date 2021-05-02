#!/usr/bin/python
M=10**9+7;r=1;n=input();k=input();n+=k-1
for i in range(k):r=r*(n-i)*pow(i+1,M-2,M)%M
print r
