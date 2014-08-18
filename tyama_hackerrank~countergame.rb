#!/usr/bin/ruby
gets.to_i.times{
	n=gets.to_i
	cnt=0
	while n>1
		i=1
		i*=2 while i*2<n
		n-=i
		cnt+=1
	end
	puts ['Richard','Louise'][cnt%2]
}