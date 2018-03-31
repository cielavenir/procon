#!/usr/bin/ruby
n,m,_=gets.split.map &:to_i
C=gets.split.map &:to_i
r=0
n.times.map{
	c,w=gets.split.map &:to_i
	[c-1,w]
}.sort_by{|c,w|
	-w
}.each{|c,w|
	if m>0&&C[c]>0
		r+=w
		m-=1
		C[c]-=1
	end
}
p r
