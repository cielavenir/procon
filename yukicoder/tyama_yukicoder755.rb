#!/usr/bin/ruby
n,m=gets.split.map &:to_i
a=[[0]*-~m]
a+=m.times.map{[0]+gets.split.map(&:to_i)}
(m+1).times{|y|m.times{|x|a[y][x+1]+=a[y][x]}}
(m+1).times{|x|m.times{|y|a[y+1][x]+=a[y][x]}}
n.times{
	r=0
	x,y=gets.split.map(&.to_i)
	(0...x).each{|x0|(x..m).each{|x1|
	(0...y).each{|y0|(y..m).each{|y1|
		r+=1 if a[x0][y0]-a[x1][y0]-a[x0][y1]+a[x1][y1]==0
	}}}}
	p r
}
