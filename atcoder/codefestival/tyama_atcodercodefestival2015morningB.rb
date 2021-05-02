#!/usr/bin/ruby
n=gets.to_i
s=gets.chomp
if n%2>0
	p -1
	exit
end
x=s[0,n/2]
y=s[n/2..-1]
p (n/2).times.count{|i|x[i]!=y[i]}