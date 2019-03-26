#!/usr/bin/ruby
n,*a=`dd`.split.map &:to_i
r=[]
n.times{(a.size-1).downto(0){|j|
	if a[j]==j+1
		r<<j+1
		a.delete_at j
		break
	end
}}
puts a.empty? ? r.reverse : -1
