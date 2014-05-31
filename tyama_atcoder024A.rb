#!/usr/bin/ruby
gets
ha=Hash.new(0)
hb=Hash.new(0)
gets.split.each{|e|ha[e.to_i]+=1}
gets.split.each{|e|hb[e.to_i]+=1}
p ha.each_key.reduce(0){|s,k|s+[ha[k],hb[k]].min}