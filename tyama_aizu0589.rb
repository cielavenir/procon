#!/usr/bin/ruby
h=Hash.new(0)
gets.to_i.times{a,b=gets.split;h[a]+=b.to_i}
h.keys.sort{|a,b|x=a.size<=>b.size;x!=0?x:a<=>b}.each{|k|puts "#{k} #{h[k]}"}