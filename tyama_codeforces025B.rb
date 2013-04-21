#!/usr/bin/ruby
gets;s=gets.chomp
if s.size%3==1
	t=s[-4..-1]
	x=s[0..-5].chars.each_slice(3).map{|e|e*''}*'-'
	puts (x.size>0 ? x+'-' : '')+t[0,2]+'-'+t[2,2]
else
	puts s.chars.each_slice(3).map{|e|e*''}*'-'
end