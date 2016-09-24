#!/usr/bin/ruby
n=gets.to_i
a=([nil]+gets.split.map(&:to_i))[-2..-1]
if a[-1]==0
	puts :UP
elsif a[-1]==15
	puts :DOWN
elsif n==1
	p -1
else
	puts a[0]<a[1] ? :UP : :DOWN
end
