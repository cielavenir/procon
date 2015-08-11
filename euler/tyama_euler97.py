#!/usr/bin/python
M=1000000000000
r=0
for _ in range(int(raw_input())):
	a,b,c,d=map(int,raw_input().split())
	r=(r+a*pow(b,c,M)+d)%M
print('%012d'%r)