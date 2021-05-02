#!/usr/bin/ruby
h=Hash.new 0
[1,-1].each{|e|gets.to_i.times{h[gets.chomp]+=e}}
p [0,*h.values].max
