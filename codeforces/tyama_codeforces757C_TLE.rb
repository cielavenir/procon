#!/usr/bin/ruby
n,m=gets.split.map(&:to_i)
h=m.times.map{[]}
n.times{|i|
	_,*a=gets.split.map(&:to_i)
	a.each{|e|h[e-1]<<i}
}
g=Hash.new 0
(0...m).each{|i|g[h[i]]+=1}
r=1
g.each_value{|n|
	(1..n).each{|i|r=r*i%(10**9+7)}
}
p r
