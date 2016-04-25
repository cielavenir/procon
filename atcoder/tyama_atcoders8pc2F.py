#!/usr/bin/python
import sys
if sys.version_info[0]>=3:raw_input=input
M=10**9+7
I=[1,1]
a,b,c=map(int,raw_input().split())
for i in range(2,a+1):I.append((M-M//i)*I[M%i]%M)
x=0;y=1;z=pow(b,a-1,M);B=pow(b,M-2,M)
for i in range(a):
	x=(x+y*z)%M
	y=y*(c+i)*I[i+1]%M
	z=z*B%M
print(x)