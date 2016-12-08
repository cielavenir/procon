#!/usr/bin/ruby
n,x,*a=$<.read.split.map(&:to_i)
h=Hash.new(r=0)
a.each{|e|h[e]+=1}
h.each_key{|k|
	opp=k^x
	if opp==k
		r+=h[k]*(h[k]-1)/2
	elsif k<opp
		r+=h[k]*h[opp]
	end
}
p r
