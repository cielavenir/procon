#!/usr/bin/ruby
gets
a=gets.split.map(&:to_i).each_with_index.to_a.sort.reverse
puts "#{a[0].last+1} #{a[1].first}"