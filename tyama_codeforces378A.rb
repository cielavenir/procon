#!/usr/bin/ruby
a,b=gets.split.map(&:to_i)
h=1.step(6).group_by{|i|(a-i).abs<=>(b-i).abs}
puts -1.step(1).map{|i|h[i] ? h[i].size : 0}*' '