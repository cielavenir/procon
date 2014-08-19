#!/usr/bin/ruby
n=gets.to_i
if n>0
	p n
else
	n=-n
	p -[n/10,n/100*10+n%10].min
end