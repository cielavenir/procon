#!/usr/bin/ruby
puts$<.map{|l|l.to_i.odd?? 0:1}