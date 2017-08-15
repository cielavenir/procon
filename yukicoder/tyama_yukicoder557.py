#!/usr/bin/python
M=10**9+7
n=input()
if n<2:print 2;exit()
r=[1,3][n%2]
n/=2
if n:n-=1;r*=4
print pow(5,n,M)*r%M
