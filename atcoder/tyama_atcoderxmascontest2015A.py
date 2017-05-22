#!/usr/bin/python
n,x,t,a,b,c=map(int,open(0).read().split());g=pow(a,t,c);h=pow(a,t,c*~-a)//~-a*b;s=0
for _ in[0]*n:s+=x;x=(x*g+h)%c
print(s)
#z=lambda n,x:n and x+z(n-1,(x*g+h)%c);print(z(n,x))
