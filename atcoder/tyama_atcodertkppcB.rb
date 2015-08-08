#!/usr/bin/ruby
p$<.drop(1).each.with_index(1).map{|e,i|[-e.to_i,i]}.min[1]