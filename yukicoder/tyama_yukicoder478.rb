#!/usr/bin/ruby
n,k=gets.split.map(&:to_i)
M=10**9
r=[]
(n-k).times{|i|
	if i%2==0
		r<<i/2
	else
		r<<M-i/2
	end
}
puts (r+[r[-1]||0]*(n-r.size))*' '
