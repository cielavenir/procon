#!/usr/bin/ruby
N,K=gets.split.map(&:to_i)
k=0
N.times{|i|
	k+=gets.to_i
	if k>=K
		p i+1
		exit
	end
}