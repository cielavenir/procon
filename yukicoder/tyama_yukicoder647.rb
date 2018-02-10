#!/usr/bin/ruby
a=gets.to_i.times.map{gets.split.map &:to_i}
b=gets.to_i.times.map{
	x,y=gets.split.map &:to_i
	a.count{|x0,y0|x0>=x&&y0<=y}
}
if b.all?{|e|e==0}
	p 0
else
	m=b.max
	p *(1..b.size).select{|i|b[i-1]==m}
end
