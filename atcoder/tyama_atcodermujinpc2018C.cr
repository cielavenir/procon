#!/usr/bin/env crystal
n,m=gets.not_nil!.split.map &.to_i
a=n.times.map{gets.not_nil!.chomp.chars}.to_a
r=0
[
	a,
	a.reverse.transpose,
	a.reverse.map(&.reverse),
	a.transpose.reverse,
].each{|b|
	h=b.size
	w=b[0].size
	c=h.times.map{|e|[0]*w}.to_a
	d=h.times.map{|e|[0]*w}.to_a
	(h-1).downto(0){|y|(w-1).downto(0){|x|
		if b[y][x]=='#'
			c[y][x]=-1
		else
			q=x==w-1 ? -1 : c[y][x+1]
			c[y][x]=q+1
		end
	}}
	(w-1).downto(0){|x|(h-1).downto(0){|y|
		if b[y][x]=='#'
			d[y][x]=-1
		else
			q=y==h-1 ? -1 : d[y+1][x]
			d[y][x]=q+1
		end
	}}
	(h-1).downto(0){|y|(w-1).downto(0){|x|r+=c[y][x]*d[y][x] if c[y][x]>0&&d[y][x]>0}}
}
p r
