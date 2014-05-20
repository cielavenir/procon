#!/usr/bin/python
#http://www.checkio.org/mission/spaceship-landing-strip/ verifier.
#sadly TLE for aizu0116

import sys
if sys.version_info[0]>=3: raw_input=input

def checkio(data):
	y=len(data)
	x=len(data[0])
	m=[[0]*x for i in range(y)]
	for j in range(y):
		r=0
		for i in range(x):
			#if data[j][i]=='.': r+=1
			if data[j][i]==1: r+=1
			else: r=0
			m[j][i]=r
	r=0
	for i in range(x):
		for j in range(y):
			M=9999999
			for k in range(j,y):
				M=min(M,m[k][i])
				r=max(r,M*(k-j+1))
	return r

'''
if __name__=='__main__':
	try:
		while True:
			y,x=[int(e) for e in raw_input().split()]
			if y==0: break
			data=[raw_input().rstrip() for i in range(y)]
			print(checkio(data))
	except EOFError:
		pass
'''
if __name__=='__main__':
	n=int(raw_input())
	try:
		for _i in range(n):
			data=[[int(e) for e in raw_input().split()] for i in range(5)]
			print(checkio(data))
			raw_input()
	except EOFError:
		pass