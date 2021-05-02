#!/usr/bin/env python3
K=10**9+7
N,M=map(int,raw_input().split())
A=[[[0]*(N+2) for j in range(N+2)] for i in range(M+1)]
A[0][1][1]=1
for i in range(M):
	for j in range(N+1):
		for k in range(N+1):
			A[i+1][j+1][k]=(A[i+1][j+1][k]+A[i][j][k]*(N-j))%K
			A[i+1][j][k]=(A[i+1][j][k]+A[i][j][k]*(j-k))%K
			A[i+1][j][j]=(A[i+1][j][j]+A[i][j][k]*k)%K
print A[M][N][N]
