#!/usr/bin/ruby
#require 'prime'
h=Hash.new 0
gets
gets.split.each{|_|
	if false
		_.to_i.prime_division.each{|n,p|h[n]+=1}
	else
		n=_.to_i
		i=2
		while i*i<=n
			if n%i==0
				h[i]+=1
				n/=i while n%i==0
			end
			i+=1
		end
		h[n]+=1 if n>1
	end
}
p h.values.max||1
