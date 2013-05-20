#!/usr/bin/python
import sys

n=int(sys.stdin.readline())
for i in range(0,n):
	a=map(int,sys.stdin.readline().split())
	a[0]-=1;a[1]-=1
	print(196471-a[0]*195-a[0]/3*5-a[1]*20+(a[1]/2 if a[0]%3!=2 else 0)-a[2])