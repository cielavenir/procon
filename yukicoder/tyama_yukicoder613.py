#!/usr/bin/env python
#cf: codejam 2008r1aC Numbers
k,M=map(int,input().split())
k=pow(2,k,M*M-1)
mul=lambda a,b:[(a[0]*b[0]+3*a[1]*b[1])%M,(a[1]*b[0]+b[1]*a[0])%M]
x=[2,1]
e=[1,0]
while k:
 if k%2:e=mul(e,x)
 x=mul(x,x);k//=2
print(2*~-e[0]%M)
