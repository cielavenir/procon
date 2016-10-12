#!/usr/bin/ruby
h=Hash.new(0)
gets
gets.split.each{|e|h[e.to_i]^=1}
h.each{|k,v|p k if v>0}
