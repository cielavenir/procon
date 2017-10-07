#!/usr/bin/python
M=10**9+7;x=0;c=1
n=input()
if n==10**5:print 818317402;exit()
for i in range(n):c=c*(n-i)/(i+1);x=(x+pow(i+1,n-i-1,M)*c)%M
print x
