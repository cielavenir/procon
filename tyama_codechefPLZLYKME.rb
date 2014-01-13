#!/usr/bin/ruby
gets.to_i.times{
	l,d,s,c=gets.split.map(&:to_i)
	puts s*(c+1)**(d-1)>=l ? 'ALIVE AND KICKING' : 'DEAD AND ROTTING'
}