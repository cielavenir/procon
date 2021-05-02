#!/usr/bin/ruby
h={}
s=0
gets.to_i.times{
	x,y=gets.split
	s+=h[x]=y.to_i
}
r=h.select{|k,v|v>s/2}
puts !r.empty? ? r.keys[0] : :atcoder