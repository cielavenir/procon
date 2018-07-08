#!/usr/bin/ruby
h=Hash.new 0;gets;gets.split.map{|e|h[e]+=1};p h.values.max
