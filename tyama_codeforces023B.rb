#!/usr/bin/ruby
puts$<.drop(1).map{|e|[0,e.to_i-2].max}