#!/usr/bin/ruby
N=[
	lambda{|q|20*30**(2*q-1)},
	lambda{|q|0},
	lambda{|q|20*30**(2*q)},
	lambda{|q|100*500**q}
]
p 1.step(9).reduce(0){|s,i|s+N[i%4][i/4]}