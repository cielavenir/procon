#!/usr/bin/ruby
a=[0]*3
gets
gets.split.each{|e|a[e.to_i%3]+=1}
if a[1]==0 && a[2]==0
	p [1,a[0]].min
else
	pairs=[a[1],a[2]].min
	a[1]-=pairs
	a[2]-=pairs
	p a[0]+pairs*2+[[3,a[1]].min,[3,a[2]].min].max
end
