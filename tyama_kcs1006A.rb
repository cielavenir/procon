#!/usr/bin/ruby
h=Hash.new(0)
gets.chomp.each_char{|c|h[c]+=1}
g=Hash.new(0)
gets.chomp.each_char{|c|g[c]+=1}
puts g.all?{|k,v|h[k]>=v} ? :Yes : :No