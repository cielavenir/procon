#!/usr/bin/env moon
r = 1<<29
n = tonumber(io.read("*l"))
for _ in io.read("*l")\gmatch("%d+")
	r0=0
	k=tonumber(_)
	while k%2<1
		r0+=1
		k=k//2
	if r>r0
		r=r0
print r
