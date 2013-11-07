#!/usr/bin/ruby
gets.to_i.times{
	gets
	a=[]
	s=gets.chomp.split('')
	1.step(s.size){|i|a+=s.combination(i).to_a.map(&:join)}
	puts a.sort
}