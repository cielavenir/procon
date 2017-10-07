#!/usr/bin/ruby
puts$<.map.with_index{|e,i|[-e.to_i,(65+i).chr]}.sort.map &:last
