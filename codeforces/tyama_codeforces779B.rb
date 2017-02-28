#!/usr/bin/ruby
s,n=gets.split
n=n.to_i
k=d=0
s.reverse.chars{|c|
	if k!=n
		if c=='0'
			k+=1
		else
			d+=1
		end
	end
}
p k==n ? d : s.size-1
