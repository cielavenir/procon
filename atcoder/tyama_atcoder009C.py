#!/usr/bin/python
M=1777777777;n,k=map(int,raw_input().split());r,a,b=n,1,0
for i in range(1,k):r,a,b=r*(n-i)*pow(i+1,M-2,M)%M,b,i*(a+b)%M
print r*b%M
