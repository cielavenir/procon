#!/usr/bin/python
M=10**9+7
c=[0]*5000
N=input()
for i in range(N):c[input()]+=1
a=[1]+[0]*N
f=list(a)
for i in range(N):
	f[i+1]=f[i]*-~i%M
	for j in range(N,0,-1):a[j]=(a[j]+a[j-1]*c[i])%M
r=0
for i in range(N+1):r=(r+(-1)**(i%2)*a[i]*f[N-i])%M
print r