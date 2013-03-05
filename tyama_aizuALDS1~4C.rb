#!/usr/bin/ruby
h={}
gets.to_i.times{
	q,s=gets.chomp.split
	if q=='find'
		puts h[s] ? :yes : :no
	else h[s]=1 end
}