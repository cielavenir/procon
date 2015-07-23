#!/usr/bin/booi
import System

while 1:
	a=[int.Parse(i) for i in Console.ReadLine().Split()]
	n as int=a[0];k as int=a[1];m as int=a[2]
	if n==0:
		break
	r=0
	for i in range(1,n):
		r=(r+k)%i
	print((r+m)%n+1)