#!/usr/bin/ruby
a,b=gets.split.map &:to_i
30.times{
	a%=2*b if b>0
	b%=2*a if a>0
}
puts [a,b]*' '
