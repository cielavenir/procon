#!/usr/bin/ruby
h={}
h[10]=[20,8,30]
h[29]=[20,8,30]
h[20]=[8,30]
h[3]=[8,30]
h[8]=[30]
h[52]=[30]
while s=gets
	x,y=s.split.map(&:to_i)
	p (h[x]&h[y])[0]
end