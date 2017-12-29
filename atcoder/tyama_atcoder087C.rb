#!/usr/bin/ruby
h=Hash.new 0;gets;gets.split.each{|e|h[e.to_i]+=1};p h.reduce(0){|s,(k,v)|s+(v<k ? v : v-k)
