#!/usr/bin/ruby
ho,wo=gets.split.map &:to_i
r,c=gets.split.map &:to_i
a=r.times.map{gets.chomp}
h_compressed,h = ho>2*r+1 ? [true,2*r+1] : [false,ho]
w_compressed,w = wo>2*c+1 ? [true,2*c+1] : [false,wo]
m=(h+1).times.map{[0]*(w+1)}
r.times{|y|c.times{|x|
	if a[y][x]==?#
		m[y][x]+=1
		m[h-r+y+1][x]-=1
		m[y][w-c+x+1]-=1
		m[h-r+y+1][w-c+x+1]+=1
	end
}}
h.times{|y|(w+1).times{|x|m[y+1][x]+=m[y][x]}}
(h+1).times{|y|w.times{|x|m[y][x+1]+=m[y][x]}}
v=0
h.times{|y|w.times{|x|
	if m[y][x]>0
		f=1
		f*=ho-2*r if y==r && h_compressed
		f*=wo-2*c if x==c && w_compressed
		v+=f
	end
}}
p v
