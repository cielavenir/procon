#!/usr/bin/ruby
def zeller(_y,m,d)
	m+=1
	if m<4 then _y-=1;m+=12 end
	y=_y/100;z=_y%100
	(5*y+z+y/4+z/4+13*m/5+d-1)%7
end
def leap(y)
	return true if y%400==0
	return false if y%100==0
	y%4==0
end
n=gets.to_i
a=[zeller(n,1,1),leap(n)]
p (n+1..1/0.0).find{|i|a==[zeller(i,1,1),leap(i)]}