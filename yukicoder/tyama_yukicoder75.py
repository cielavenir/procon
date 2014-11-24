#!/usr/bin/python
#derived from checkio expected-dice

from fractions import Fraction
def gauss(a):
	if not a or len(a)==0: return None
	n=len(a)
	for i in range(n):
		if a[i][i]==0:
			for j in range(i+1,n):
				if a[j][i]!=0:
					for k in range(i,n+1): a[i][k]+=a[j][k]
					break
			else:
				return None
		for j in range(n):
			if i!=j:
				r = Fraction(a[j][i],a[i][i])
				for k in range(i,n+1): a[j][k] = a[j][k] - a[i][k]*r
	for i in range(n):
		x=Fraction(a[i][i],1)
		for j in range(len(a[i])):
			a[i][j] /= x
	return a

def expected(n, s, t): #, b):
	#perform probably-dice
	a=[0]*(s*(n+1)+1)
	for i in range(1,s+1):
		a[i+s]=Fraction(1,s)**n
	for e in range(n-1):
		for i in reversed(range(0,s*n+1)):
			a[i+s]=sum(a[i:i+s])
	l = t+1
	A = [[int(i==j) for i in range(l)]+[int(j!=t)] for j in range(l)]
	for start in range(l):
		if start != t:
			for roll in range(n,s*n+1):
				end = roll + start
				#end = (end + b[end%l])%l
				if end>=l: end=0
				A[start][end] -= a[roll+s]
	return float(gauss(A)[0][-1])

if __name__ == '__main__':
	import sys
	if sys.version_info[0]>=3: raw_input=input
	N=int(raw_input())
	print(expected(1,6,N))