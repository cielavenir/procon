#!/usr/bin/ruby
a=$<.map(&:to_i)
a.each{|e|p a.sort.reverse.index(e)+1}