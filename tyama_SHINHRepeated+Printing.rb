#!/usr/bin/ruby
puts$<.map{|e|a,b,c=e.split;(a..b).map{|x|x*c.to_i}*''}