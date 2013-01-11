#!/usr/bin/ruby
require "rational"
m=gets.chomp.split(" ").map!{|i|i=i.to_i}.max
puts m==1?"1/1":Rational(7-m,6)