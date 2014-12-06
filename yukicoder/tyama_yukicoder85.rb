#!/usr/bin/ruby
n,m,c=gets.split.map(&:to_i)
if n==1||m==1
	puts n*m==2 ? :YES : :NO
else
	puts n*m%2==1 ? :NO : :YES
end