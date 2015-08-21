#!/usr/bin/rexx

do while 1
	s=linein()
	parse var s n " " k " " m
	if n==0 then leave
	r=0
	do i=1 until i==n-1
		r=(r+k)//i
	end
	say (r+m)//n+1
end