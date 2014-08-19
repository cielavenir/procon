#!/usr/bin/ruby
h=Hash.new(0)
gets.chomp.chars{|c|h[c]+=1}
p [[(h['n']-1)/2,0].max,h['i'],h['e']/3,h['t']].min