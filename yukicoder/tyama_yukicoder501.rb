#!/usr/bin/ruby
n,d=gets.split.map(&:to_i)
if n>d
	puts 'A'*d+'C'*(n-d)
else
	puts 'A'*(2*n-d)+'B'*(d-n)
end
