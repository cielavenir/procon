#!/usr/bin/ruby
while(a,b=gets.split.map(&:to_i))!=[-1,-1]
	puts "#{a+b} #{a-b} #{a*b} #{begin (a.to_f/b).round rescue :NA end}"
end