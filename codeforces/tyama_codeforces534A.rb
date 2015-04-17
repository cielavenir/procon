#!/usr/bin/env ruby
n=gets.to_i
if n<3
	puts "1\n1\n"
elsif n<4
	puts "2\n1 3\n"
else
	p n
	puts (2.step(n,2).to_a+1.step(n,2).to_a)*' '
end