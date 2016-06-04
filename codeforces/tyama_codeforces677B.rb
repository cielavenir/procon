#!/usr/bin/ruby
N,H,K=gets.split.map(&:to_i)
r=h=0
gets.split.map(&:to_i).each{|x|
	if h+x<=H
		h+=x
	else
		r+=1
		h=x
	end
	r+=h/K
	h%=K
}
p r+(h+K-1)/K