#!/usr/bin/python
M=2
def grid(m,I,J):
	z=[0]*(M*M+1)
	for j in range(M*M):
		if m[I][j]: z[m[I][j]]+=1
		if z[m[I][j]]>1: return False
	z=[0]*(M*M+1)
	for i in range(M*M):
		if m[i][J]: z[m[i][J]]+=1
		if z[m[i][J]]>1: return False
	i=I//M+J//M*M
	z=[0]*(M*M+1)
	for j in range(M*M):
		x=i%M*M+j//M
		y=i//M*M+j%M
		if m[x][y]: z[m[x][y]]+=1
		if z[m[x][y]]>1: return False
	return True

def dfs(m,n):
	if n==M*M*M*M: return m
	i=n//(M*M)
	j=n%(M*M)
	if m[i][j]: return dfs(m,n+1)
	for k in range(1,M*M+1):
		m[i][j]=k
		if grid(m,i,j) and dfs(m,n+1): return m
	m[i][j]=0
	return None

checkio=lambda m: dfs(m,0)

import sys
a=[map(int,e.strip()) for e in sys.stdin]
for e in checkio(a): print(''.join(map(str,e)))