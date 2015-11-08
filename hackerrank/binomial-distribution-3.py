#!/usr/bin/python
def comb(n,r):
	x=1
	for i in range(r): x=x*(n-i)//(i+1)
	return x

N=10
P=0.12
Q=1-P
print('%.3f'%sum(comb(N,i)*P**i*Q**(N-i) for i in range(0,3)))
print('%.3f'%sum(comb(N,i)*P**i*Q**(N-i) for i in range(2,N+1)))