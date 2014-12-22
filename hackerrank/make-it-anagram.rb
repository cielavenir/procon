#!/usr/bin/ruby
h=Hash.new(0)
gets.chomp.chars{|c|h[c]+=1}
gets.chomp.chars{|c|h[c]-=1}
p h.values.map(&:abs).reduce(:+)