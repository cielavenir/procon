#!/usr/bin/ruby
puts$<.map{|e|a,b=e.split.map(&:to_i);((6-a)*1.2).to_i*1000*b}