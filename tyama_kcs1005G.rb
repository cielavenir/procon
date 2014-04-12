#!/usr/bin/ruby
gets.to_i.times{
	a,b=gets.chomp.split
	a=a.to_i
	s=''
	s+='Fizz' if a%3==0
	s+='Buzz' if a%5==0
	s=a.to_s if s.empty?
	puts s==b ? :OK : :NG
}