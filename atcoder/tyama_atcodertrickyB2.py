#!/usr/bin/python
from __future__ import division,print_function
import sys,math,ctypes
if sys.platform=='win32':
	libc=ctypes.msvcrt
else:
	libc=ctypes.cdll.LoadLibrary(None)

def scanlld():
	n=ctypes.c_longlong()
	libc.scanf(b"%lld",ctypes.byref(n))
	return n.value

#T=scanlld()
T=int(sys.stdin.readline())
for _ in range(T):
	#a=scanlld()
	#b=scanlld()
	#c=scanlld()
	a,b,c=map(int,sys.stdin.readline().split())
	if a==0:
		if b==0: print("0" if c else "3")
		else: print("1 %.12f"%(-c/b))
	else:
		if a<0:
			a = -a
			b = -b
			c = -c
		d=b*b-4.0*a*c
		if abs(d)<1e-9: print("1 %.12f"%(-b/2/a))
		elif d<0: print("0")
		else:
			# acknowledgement: http://tricky.contest.atcoder.jp/submissions/120839
			x=y=0.0
			if b>0:
				x = (-b-math.sqrt(d))/2/a
				y = c/a/x
			else:
				y = (-b+math.sqrt(d))/2/a
				x = c/a/y
			print("2 %.12f %.12f"%(x,y))
