#!/usr/bin/ruby
n=gets.to_i
m=gets.to_i
n%=2
if n==1
	(puts :No;exit)if m<10
	m-=10
end
puts [:Yes,:No][m%2]
