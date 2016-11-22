#!/usr/bin/env python
def f(n):
	e=[1,0,0,1];z=[1,1,1,0]
	while n:e=[e,g(e,z)][n%2];z=g(z,z);n/=2
	return e[1]
M=998244353;g=lambda a,b:[(a[x]*b[y]+a[z]*b[w])%M for x,y,z,w in[[0,0,1,2],[0,1,1,3],[2,0,3,2],[2,1,3,3]]];n,m=map(int,raw_input().split());I=[1,1];r=f(m+2*n-2);c=1
for i in range(2,n):I+=[(M-M/i)*I[M%i]%M]
for i in range(n-1):r=(r+c*(M-f(2*n-2-2*i)))%M;c=c*(m+i)*I[i+1]%M
print r
