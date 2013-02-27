#!/usr/bin/ruby
k,n=gets.split.map(&:to_i)
puts k.times.map{
	h=Hash.new(0)
	gets.split.each{|e|h[e.to_i]+=1}
	v,k=h.map{|k,v|[v,k]}.sort[-1]
	v>n/2 ? k : -1
}*' '