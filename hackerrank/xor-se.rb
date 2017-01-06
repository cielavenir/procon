#!/usr/bin/ruby
def f(x) [x,2,x+2,0][x%8/2] end
gets.to_i.times{
	a,b=gets.split.map(&:to_i)
	p f(b)^f(a-1)
}
