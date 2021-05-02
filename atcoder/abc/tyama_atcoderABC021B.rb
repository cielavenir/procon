#!/usr/bin/ruby
gets
a=gets.split.map(&:to_i)
gets
a+=gets.split.map(&:to_i)
puts a.uniq==a ? :YES : :NO