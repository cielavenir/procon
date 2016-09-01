#!/usr/bin/ruby
gets.to_i.times{
	a=(1..gets.to_i).map{|i|a,p=gets.split.map(&:to_i);[a*(100-p)+a*3*p,i]}.sort
	puts a.select{|e|e[0]==a[-1][0]}.map(&:last)*' '
}