#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input

cross=lambda a,b: (a.conjugate()*b).imag
dot=lambda a,b: (a.conjugate()*b).real

def solve(poly, p):
	f=False
	for i in range(len(poly)):
		a=poly[i]-p
		b=poly[(i+1)%len(poly)]-p
		if a.imag>b.imag: a,b=b,a
		if a.imag<=0 and 0<b.imag and cross(a,b)<0: f=not f
		if cross(a,b)==0 and dot(a,b)<=0: return 1
	return 2 if f else 0

checkio=lambda data: solve([complex(*e) for e in data[0]],complex(*data[1]))

n=int(raw_input())
poly=[[float(e) for e in raw_input().split()] for i in range(n)]
n=int(raw_input())
try:
	for i in range(n):
		print(checkio([poly,[float(e) for e in raw_input().split()]]))
except EOFError:
	pass