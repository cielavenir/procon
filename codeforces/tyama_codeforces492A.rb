#!/usr/bin/ruby
n=gets.to_i
s=0
i=0
loop{
	break if s+i*(i+1)/2>n
	s+=i*(i+1)/2
	i+=1
}
p i-1