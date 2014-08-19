#!/usr/bin/ruby
h=Hash.new(0)
a=gets.split.map(&:to_f)
b=gets.split.map(&:to_f)
a.each{|e|b.each{|f|h[("%.5f"%[e-f]).to_f]+=1}}
puts h.map{|k,v|[v,k]}.max