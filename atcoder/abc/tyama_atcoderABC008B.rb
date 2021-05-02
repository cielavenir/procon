#!/usr/bin/ruby
h=Hash.new(0)
gets.to_i.times{h[gets.chomp]+=1}
puts h.map{|k,v|[v,k]}.sort.last.last