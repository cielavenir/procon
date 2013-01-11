#!/usr/bin/booi
import System

n=int.Parse(Console.ReadLine())
for i in range(0,n):
	a=[int.Parse(i) for i in Console.ReadLine().Split()]
	y as int=a[0];m as int=a[1];d as int=a[2]
	y-=1;m-=1
	r=0
	if y%3!=2:
		r=m/2
	print 196471-y*195-y/3*5-m*20+r-d