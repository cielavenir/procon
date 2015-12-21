#!/usr/bin/ruby
h=Hash.new(0)
n=gets.to_i
gets.split.each{|e|h[e.to_i]+=1}
r=n*(n-1)/2
h.each{|k,v|r-=v*(v-1)/2}
p r