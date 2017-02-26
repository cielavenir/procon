#!/usr/bin/python
import sys
def f(pos,t,n):
	if n<2: return n
	if pos+1==2*t: return n%2
	n//=2
	pos//=2
	return f(pos,t-(pos+1 if t>pos+1 else 0),n)

n,l,r=map(int,sys.stdin.readline().split())
x=1
while x<=n: x*=2
x-=1
s=0
for i in range(l,r+1): s+=f(x,i,n)
print(s)
