#!/usr/bin/ruby
gets.to_i.times{
	n,k=gets.split.map &:to_i
	a=gets.split.map &:to_i
	p [a[0],n+1-a[-1],*a.each_cons(2).map{|x,y|(y-x+2)/2}].max
}
