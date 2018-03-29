#!/usr/bin/ruby
s=gets.chomp
n=(s[0,3].to_i+5)/10
if n==100
	puts '1.0*10^%d'%s.size
else
	puts '%d.%d*10^%d'%[n/10,n%10,s.size-1]
end
