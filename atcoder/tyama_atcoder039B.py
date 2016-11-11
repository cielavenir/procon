#!/usr/bin/python
M=10**9+7;r=1;n,k=map(int,input().split());n,k=[n+k-1,n-1]if n>k else[n,k%n]
for i in range(k):r=r*(n-i)*pow(i+1,M-2,M)%M
print(r)
