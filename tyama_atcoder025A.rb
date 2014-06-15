#!/usr/bin/ruby
p$<.map{|e|e.split.map(&:to_i)}.transpose.reduce(0){|s,e|s+e.max}