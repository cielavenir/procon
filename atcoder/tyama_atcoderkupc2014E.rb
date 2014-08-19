#!/usr/bin/ruby
gets.to_i.times{
	a,b=gets.split.map(&:to_i)
	puts (a*b)%8==0 && !((a*b)==8||a<2||b<2) ? 'Possible' : 'Impossible'
}