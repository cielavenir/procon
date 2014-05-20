#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input
cross=lambda a1, b1, a2, b2: a1*b2-a2*b1
try:
	T=0
	while True:
		T+=1
		n=int(raw_input())
		if n==0: break
		a=[[float(e) for e in raw_input().split()] for i in range(n)]
		s=0
		t=0
		for i in range(n-1):
			x=cross(a[i][0],a[i][1],a[i+1][0],a[i+1][1])
			if x>0: s+=abs(x)/2
			else: t+=abs(x)/2
		x=cross(a[n-1][0],a[n-1][1],a[0][0],a[0][1])
		if x>0: s+=abs(x)/2
		else: t+=abs(x)/2
		print('%d %.1f'%(T,abs(s-t)))
		raw_input()
except EOFError:
	pass