#!/usr/bin/python
n=input()
a=sorted(map(int,raw_input().split()))
b=[0]+[a[j]*(-1)**j%24 for j in range(n)]
s=24
for j in range(n):
 for k in range(j+1,n+1):s=min(s,(b[j]-b[k])%24,(b[k]-b[j])%24)
print s
