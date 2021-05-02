#!/usr/bin/ruby
h=Hash.new(0)
gets.to_i.times{
	n=gets.to_i
	h[n]+=1
}
r=0
h.each{|k,v|r+=[0,v-1].max}
p r