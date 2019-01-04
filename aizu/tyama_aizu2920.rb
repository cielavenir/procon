#!/usr/bin/ruby
gets
o,e=gets.split.map(&:to_i).sort.partition &:odd?
o.size.odd? && o.shift
p o.reduce(:+)+e.reduce(:+)>>1
