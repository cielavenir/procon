#!/usr/bin/env python3
M=10**9+7;F=[1];a,b=sorted(map(int,input().split()))
for i in range(1,10**6):F.append(F[-1]*i%M)
print(0 if b-a>1 else F[a]*F[b]*(1 if b-a else 2)%M)
