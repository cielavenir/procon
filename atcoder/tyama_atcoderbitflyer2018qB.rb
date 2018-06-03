#!/usr/bin/ruby
s,c,n=gets.split.map &:to_i
gets.chomp.chars{|q|
	if q==?S
		s-=1 if s>0
	elsif q==?C||s<c
		c-=1 if c>0
	else
		s-=1 if s>0
	end
}
p s,c
