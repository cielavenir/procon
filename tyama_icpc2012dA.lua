#!/usr/bin/lua
n=io.read("*n")
i=0
repeat
	y=io.read("*n")-1
	m=io.read("*n")-1
	d=io.read("*n")
	r=0
	if y%3~=2 then r=math.floor(m/2) end
	print(196471-y*195-math.floor(y/3)*5-m*20+r-d)
	i=i+1
until i==n