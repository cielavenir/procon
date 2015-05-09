#!/usr/bin/env ruby
gets
p$<.map{|e|e.chomp.chars.map(&:to_i)}.transpose.map{|x,y|(x-y).abs}.map{|e|[10-e,e].min}.reduce(:+)