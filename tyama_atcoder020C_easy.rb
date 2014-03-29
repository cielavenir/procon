#!/usr/bin/ruby
n=gets.to_i
s=''
n.times{
	a,l=gets.split
	s+=a*l.to_i
}
p s.to_i%gets.to_i