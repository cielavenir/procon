#!/usr/bin/ruby
def leap(y)
	return true if y%400==0
	return nil if y%100==0
	y%4==0
end
f=nil;while(a,b=gets.split.map &:to_i)!=[0,0]
	puts if f;f=1
	z=a.step(b).select{|i|leap(i)}
	puts z.size==0? :NA : z
end