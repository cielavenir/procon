#!/usr/bin/ruby
puts $<.map{|e|e.split.map(&:to_i).max}