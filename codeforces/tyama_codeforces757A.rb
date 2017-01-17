#!/usr/bin/ruby
x,y=['Bulbasaur',gets.chomp].map{|s|
	h=Hash.new 0
	s.chars{|c|h[c]+=1}
	h
}
p x.map{|k,v|y[k]/v}.min
