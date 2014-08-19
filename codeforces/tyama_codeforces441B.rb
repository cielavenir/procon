#!/usr/bin/ruby
n,v=gets.split.map(&:to_i)
a=n.times.map{gets.split.map(&:to_i)}
ma=a.max[0]
m=[0]*(ma+2)
a.each{|x,y|m[x]+=y}
r=0
1.step(ma+1){|i|
	avail=m[i-1]+m[i]
	gather=[avail,v].min
	r+=gather
	x=[m[i-1],gather].min
	m[i-1]-=x
	gather-=x
	m[i]-=gather
}
p r