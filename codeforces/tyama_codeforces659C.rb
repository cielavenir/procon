#!/usr/bin/ruby
n,m=gets.split.map(&:to_i)
h={}
gets.split.each{|e|h[e.to_i]=1}
r=[]
(1..1/0.0).each{|i|
	if !h[i]
		break if m<i
		m-=i
		r<<i
	end
}
p r.size
puts r*' '