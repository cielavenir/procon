#!/usr/bin/rexx

do while 1
	n=linein()
	if n==0 then leave
	s=0
	ma=0
	mi=1000
	do i=1 until i==n
		x=linein()
		s=s+x
		if ma<x then ma=x
		if mi>x then mi=x
	end
	say trunc((s-ma-mi)/(n-2))
end