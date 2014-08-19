#!/usr/bin/ruby
gets;
a=gets.split.map(&:to_i).sort_by{|e|e}.chunk{|e|e}.to_a
puts "#{a.map{|k,v|v.size}.max} #{a.size}"