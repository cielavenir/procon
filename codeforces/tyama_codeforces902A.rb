#!/usr/bin/ruby
n,m=gets.split.map &:to_i
last=0
n.times{
	a,b=gets.split.map &:to_i
	if a>last
		puts :NO
		exit
	else
		last=[b,last].max
		if last>=m
			puts :YES
			exit
		end
	end
}
puts :NO
