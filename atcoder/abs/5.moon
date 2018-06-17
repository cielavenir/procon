#!/usr/bin/env moon
n,a,b = io.read("*n","*n","*n")
r = 0
for i=1,n
	s=0
	j=i
	while j>0
		s+=j%10
		j=j//10
	if a<=s and s<=b
		r+=i
print r
