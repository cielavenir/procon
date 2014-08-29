#!/usr/bin/ruby
def zip(a) a.shift.zip(*a) end
puts zip(('0'+gets.chomp).split('').map(&:to_i).reverse.each_slice(2).to_a).map{|e|e.compact.reduce(0,:+)}.reverse*' '