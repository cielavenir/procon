#!/usr/bin/ruby
a=gets.to_i.times.map{
	h=Hash.new 0
	gets.chomp.chars{|c|h[c]+=1}
	h
}
puts ('a'..'z').map{|c|c*a.map{|h|h[c]}.min}*''
