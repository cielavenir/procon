#!/usr/bin/ruby
a=gets.to_i.times.map{gets.chomp}.sort
gets.to_i.times{
	str=gets.chomp
	idx=a.index(str)+1
	x=0
	str.each_byte{|n|x+=n-64}
	p x*idx
}