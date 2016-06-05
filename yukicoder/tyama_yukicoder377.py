#!/usr/bin/python
from collections import defaultdict
from fractions import gcd
import sys,subprocess
if sys.version_info[0]>=3:
	raw_input=input
	xrange=range

def prime_division(n):
	h=defaultdict(int)
	line=subprocess.check_output(['factor',str(n)])
	for e in line.split()[1:]: h[int(e)]+=1
	return [(k,v) for k,v in h.items()]

def divisor_totient(a,d,n,t):
	if d==len(a):
		yield (n,t)
	else:
		for i in xrange(a[d][1]+1):
			for x,xt in divisor_totient(
				a,d+1,
				n*a[d][0]**i,
				(t if i==0 else t*(a[d][0]-1)*a[d][0]**(i-1))
			): yield (x,xt)

cache={}
M=1000000007
H,W,K=map(int,raw_input().split())
A=prime_division(H)
B=prime_division(W)
r=0
for a,at in divisor_totient(A,0,1,1):
	for b,bt in divisor_totient(B,0,1,1):
		key=W*H*gcd(a,b)//a//b
		if key not in cache: cache[key]=pow(K,key,M)
		r=(r+at*bt*cache[key])%M
print(r*pow(W*H,M-2,M)%M)