#!/usr/bin/python
import sys
n,q=map(int,sys.stdin.readline().split())
for _ in range(q):
	x,y=map(int,sys.stdin.readline().split())
	print( ((x-1)*n+y+1+(x+y)%2*n*n)//2 )
