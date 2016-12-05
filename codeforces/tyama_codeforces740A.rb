#!/usr/bin/ruby
n,a,b,c=gets.split.map(&:to_i)
if n%4==0
	p 0
elsif n%4==1
	p [a*3,a+b,c].min
elsif n%4==2
	p [a*2,b,c*2].min
elsif n%4==3
	p [a,b+c,c*3].min
end
