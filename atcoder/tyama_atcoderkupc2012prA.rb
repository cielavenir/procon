#!/usr/bin/ruby
a=gets.split.map(&:to_i)
case a[0]
	when 0 then puts a[1]+1
	when 1 then puts a[1]+2
	when 2 then puts 2*a[1]+3
	when 3 then puts 2**(a[1]+3)-3
end