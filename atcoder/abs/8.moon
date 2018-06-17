#!/usr/bin/env moon
n,y = io.read("*n","*n")
for i=0,n
	for j=0,n-i
		k=n-i-j
		if i*1000+j*5000+k*10000==y
			print tostring(k).." "..tostring(j).." "..tostring(i)
			return
print "-1 -1 -1"
