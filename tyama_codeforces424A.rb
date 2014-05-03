#!/usr/bin/ruby
N=gets.to_i
s=gets.chomp
n=s.chars.count{|c|c=='X'}
if n<N/2
	m=N/2-n
	p m
	m.times{s.sub!('x','X')}
	puts s
elsif N/2<n
	m=n-N/2
	p m
	m.times{s.sub!('X','x')}
	puts s
else
	p 0
	puts s
end