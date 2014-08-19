#!/usr/bin/ruby
puts$<.map{|e|"3C%02d"%((e.to_i-1)%39+1)}