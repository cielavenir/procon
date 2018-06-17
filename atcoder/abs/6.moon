#!/usr/bin/env moon
n = io.read("*n")
io.read("*l")
arr = [tonumber(e) for e in io.read("*l")\gmatch("%d+")]
table.sort(arr,(a,b)->a>b)
r = 0
t = 1
for e in *arr
	r+=t*e
	t=-t
print r
