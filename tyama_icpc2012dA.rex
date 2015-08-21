#!/usr/bin/rexx

n=linein()
do i=1 until i==n
	s=linein()
	parse var s y " " m " " d
	r=0
	if y//3>0 then r=(m-1)%2
	say 196471-(y-1)*195-(y-1)%3*5-(m-1)*20+r-d
end