#!/usr/bin/ruby
gets;p gets.split.map(&:to_i).sort.reverse.each_with_index.map{|e,i|(-1)**i*Math::PI*e**2}.reduce(:+)