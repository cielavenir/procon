#!/usr/bin/ruby
a=gets.split.map(&:to_i).group_by{|e|e}.map{|k,v|v.size}.sort
puts a==[2,3]?'FULL HOUSE':a==[1,1,3]?'THREE CARD':a==[1,2,2]?'TWO PAIR':a==[1,1,1,2]?'ONE PAIR':'NO HAND'