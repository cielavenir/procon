#!/usr/bin/ruby
a=99.times.map{|i|i*(i+1)/2}
puts a.index(gets.to_i) ? 'YES' : 'NO'