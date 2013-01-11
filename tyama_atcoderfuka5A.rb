#!/usr/bin/ruby
while(a=gets.split.map{|e|e.to_i})[0]>0 do p gets.split.map{|e|e.to_i}.sort[0...a[1]].inject(:+)end