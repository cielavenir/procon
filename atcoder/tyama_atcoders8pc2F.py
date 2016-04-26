#!/usr/bin/python
import sys
if sys.version_info[0]>=3:raw_input=input

a,b,c=map(int,raw_input().split());M=10**9+7;I=[1,1];x=0;y=1;z=pow(b,a-1,M);B=pow(b,M-2,M)
for i in range(2,a+2):I+=[(M-M//i)*I[M%i]%M];x,y,z=(x+y*z)%M,y*(c+i-2)*I[i-1]%M,z*B%M
print(x)