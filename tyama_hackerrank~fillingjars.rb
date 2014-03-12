#!/usr/bin/ruby
n,q=gets.split.map(&:to_i)
s=0
q.times{
	a,b,c=gets.split.map(&:to_i)
	s+=c*(b-a+1)
}
p s/n