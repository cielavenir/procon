#!/usr/bin/ruby
w,h=gets.split.map(&:to_i)
cnt=h.times.flat_map{gets.split.map(&:to_i)}.zip(h.times.flat_map{gets.split.map(&:to_i)}).count{|a,b|a==b}
puts '%.2f'%[1.0*cnt/h/w]