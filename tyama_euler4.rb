#!/usr/bin/ruby
a=[]
999.step(0,-1){|i|999.step(i,-1){|j|s=i*j;a<<s if s.to_s==s.to_s.reverse}}
#p a.max
a.sort!
gets.to_i.times{
	n=gets.to_i
	p a.take_while{|e|e<n}.last
}