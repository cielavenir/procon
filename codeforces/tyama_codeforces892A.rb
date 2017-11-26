#!/usr/bin/ruby
gets
a=gets.split.map(&:to_i).reduce :+
b=gets.split.map(&:to_i).sort[-2..-1].reduce :+
puts a<=b ? :YES : :NO
