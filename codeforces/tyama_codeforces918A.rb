#!/usr/bin/ruby
n=gets.to_i
s='o'*n
a=b=1
while b<=n
	s[b-1]='O'
	a,b=b,a+b
end
puts s
