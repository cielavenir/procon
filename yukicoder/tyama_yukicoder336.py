#!/usr/bin/python
from __future__ import print_function
import sys
if sys.version_info[0]>=3: raw_input=input

def A001250_list(n):
	R = [1]; A = {-1:0, 0:2}; k = 0; e = 1
	for i in range(n+1):
		Am = 0; A[k + e] = 0; e = -e
		for j in range(i+1): Am += A[k]; A[k] = Am%1000000007; k += e
		if i > 1 : R.append(A[-i//2] if i%2 == 0 else A[i//2])
	return R

n=int(raw_input())
print(0 if n<3 else A001250_list(n)[-1])