#!/usr/bin/python
import sys
if sys.version_info[0]<3: input=raw_input

n,m=map(int,input().split());M=10**9+7;I=[1,1];F=I+[];R=I+[]
for i in range(2,m+1):I+=[(M-M//i)*I[M%i]%M];F+=[i*F[-1]%M];R+=[I[i]*R[-1]%M]
print(sum((-1)**k*F[m]*R[k]*R[m-k]*pow(m-k,n,M)for k in range(m))%M)