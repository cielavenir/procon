#!/usr/bin/ruby
require "rational"
m=gets.split.map(&:to_i).max
puts m==1?"1/1":Rational(7-m,6)