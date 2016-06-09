#!/usr/bin/ruby
a=gets.split.map(&:to_i)
s=0;h=Hash.new(0)
a.each{|e|s+=e;h[e]+=1}
r=s
h.each{|k,v|
	if v>=2
		r=[r,s-k*[v,3].min].min
	end
}
p r