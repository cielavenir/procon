#!/usr/bin/env moon
n = io.read("*n")
t = 0
x = 0
y = 0
for i=1,n
	t0,x0,y0 = io.read("*n","*n","*n")
	dt = t0-t
	dx = x0-x
	dy = y0-y
	if dx+dy>dt or (dt-dx-dy)%2>0
		print "No"
		return
	t = t0
	x = x0
	y = y0
print "Yes"
