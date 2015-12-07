#!/usr/bin/ruby
N=gets.to_i
r=0
1.upto(N){|i|
	if i%15==0
		r+=4
	elsif i%3==0||i%5==0
		r+=2
	end
}
p r