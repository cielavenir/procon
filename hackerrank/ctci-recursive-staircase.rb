#!/usr/bin/ruby
gets.to_i.times{
	a,b,c=0,0,1
	gets.to_i.times{a,b,c=b,c,a+b+c}
	p c
}
