#!/usr/bin/ruby
h=Hash.new 0
gets.to_i.times{h[gets.chomp.size-2]+=1}
p h.max_by{|k,v|[v,k]}[0]
