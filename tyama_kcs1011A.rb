#!/usr/bin/ruby
s=gets.chomp.split('')
gets.to_i.times{
	a,b=gets.split.map{|e|e.to_i-1}
	s[a],s[b]=s[b],s[a]
}
puts s*''