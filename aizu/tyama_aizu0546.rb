#!/usr/bin/ruby
while(n=gets.to_i)>0
	k=gets.to_i
	h={}
	n.times.map{gets.chomp}.permutation(k){|a|h[a*'']=1}
	p h.size
end