#!/usr/bin/env moon
a = io.read("*n")
b = io.read("*n")
c = io.read("*n")
x = io.read("*n")
r = 0
for i=0,500
	for j=0,(x-500*i)//100
		k=x-500*i-100*j
		if k%50==0 and c>=k//50 and a>=i and b>=j
			r+=1
print r
