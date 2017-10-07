#!/usr/bin/ruby
puts$<.map.with_index{|e,i|x,y=e.split.map &:to_i;[-x,y,(65+i).chr]}.sort.map &:last
