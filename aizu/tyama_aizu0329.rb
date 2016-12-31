#!/usr/bin/ruby
m={r=s=0=>-1}
gets.to_i.times{|i|
	s+=gets.to_i
	m[s]=i if !m[s]
	r=[r,i-m[s]].max
}
p r
