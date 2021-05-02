#!/usr/bin/ruby
gets
a=gets.split.map(&:to_i).select{|e|e>0}
p (a.reduce(:+)+a.size-1)/a.size