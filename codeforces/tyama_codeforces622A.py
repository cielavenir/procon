#!/usr/bin/python
n=int(raw_input())
s=0
i=1
while True:
	s+=i
	if n<=s:
		print(i-s+n)
		break
	i+=1