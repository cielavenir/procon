#!/usr/bin/ruby
h=Hash.new 0
gets.to_i.times{gets;x,y=gets.split.map &:to_i;gets.split.each{|e|h[e]+=y}}
puts h.sort_by{|k,v|[-v,k]}.map{|e|e*' '}[0,10]
