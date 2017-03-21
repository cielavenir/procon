#!/usr/bin/python
M=10**9+7
def f(n):
	return 1 if n==1 else (f(n-1)*100+1)%M if n%2 else f(n//2)*(pow(100,n//2,M)+1)%M

import sys
n=int(sys.stdin.readline())
print(f(n))
print([0,1,101,10101,1010101,101010101,10101010101,1010101010101,101010101010101,10101010101010101,1010101010101010101][n%11])
