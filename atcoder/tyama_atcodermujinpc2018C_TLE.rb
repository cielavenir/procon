#!/usr/bin/ruby
n,m=gets.split.map &:to_i
a=n.times.map{gets.chomp.chars}
r=0
[
	a,
	a.reverse.transpose,
	a.reverse.map(&:reverse),
	a.transpose.reverse,
].each{|b|
	h=b.size
	w=b[0].size
	c=h.times.map{|e|[0]*w}
	d=h.times.map{|e|[0]*w}
	(h-1).downto(0){|y|(w-1).downto(0){|x|
		if b[y][x]=='#'
			c[y][x]=-1
		else
			c[y][x]=(c[y][x+1]||-1)+1
		end
	}}
	(w-1).downto(0){|x|(h-1).downto(0){|y|
		if b[y][x]=='#'
			d[y][x]=-1
		else
			q=y==h-1 ? -1 : (d[y+1][x]||-1)
			d[y][x]=q+1
		end
	}}
	(h-1).downto(0){|y|(w-1).downto(0){|x|r+=c[y][x]*d[y][x] if c[y][x]>0&&d[y][x]>0}}
}
p r
