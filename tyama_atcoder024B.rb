#!/usr/bin/ruby
a=$<.drop(1).map(&:to_i)
m=(a+a).chunk{|e|e}.map{|k,v|v.size}.max
p m==a.size*2 ? -1 : (m+1)/2