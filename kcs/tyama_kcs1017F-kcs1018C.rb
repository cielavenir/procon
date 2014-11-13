#!/usr/bin/ruby
gets.to_i.times{
	a,b,c=gets.split.map(&:to_i)
	x=(a+b+c)/3
	p (x-a)**2+x**2+(x-b)**2
}