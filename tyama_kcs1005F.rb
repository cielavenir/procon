#!/usr/bin/ruby
puts $<.drop(1).map{|e|e.split.map(&:to_i)}.transpose.map{|e|e*' '}