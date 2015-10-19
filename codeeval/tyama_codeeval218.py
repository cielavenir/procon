#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input

def checkio(lines_list):
	wipe_list=[max(e) for e in lines_list if 0 in e]
	lines_list=[e for e in lines_list if not any(f in wipe_list for f in e)]
	M=5
	#if any(any(e>16 for e in _) for _ in lines_list): M=5
	h={}
	for p,q in lines_list: h[(min(p,q)-1,max(p,q)-1)]=1
	r=0
	for k in range(1,M):
		for x in range((M-1)-k+1):
			for y in range((M-1)-k+1):
				if all(((y+i)*M+x,(y+i+1)*M+x) in h and (y*M+x+i,y*M+x+i+1) in h and ((y+i)*M+x+k,(y+i+1)*M+x+k) in h and ((y+k)*M+x+i,(y+k)*M+x+i+1) in h for i in range(k)):
					r+=1
	return r

try:
	while True:
		a=[[int(f) for f in e.split()] for e in raw_input().split(' | ')]
		print(checkio(a))
except EOFError:
	pass