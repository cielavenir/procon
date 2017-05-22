#!/usr/bin/python
N,*A=map(int,open(0).read().split());C=[0]*N;M=10**9+7;r=1
for e in A:C[e]+=1
for i in range(1,N):r=r*pow(pow(2,C[i-1],M)-1,C[i],M)*pow(2,C[i]*~-C[i]//2,M)%M
print(0 if A[0]>0 or A.count(0)>1 else r)
