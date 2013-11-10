#!/usr/bin/ruby
puts$<.map{|e|a,b=e.split.map &:to_i;a-b}