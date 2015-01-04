#!/usr/bin/ruby
gets
p gets.split.map(&:to_i).each_cons(3).count{|e|e.minmax.include?(e[1])&&e.uniq==e}