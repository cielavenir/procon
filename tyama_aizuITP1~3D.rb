#!/usr/bin/ruby
require 'prime'
a,b,c=gets.split.map(&:to_i)
d=c<2 ? [[c]] : c.prime_division.map{|e,n|0.step(n).map{|i|e**i}}
p d.shift.product(*d).map{|e|e.reduce(:*)}.count{|e|a<=e&&e<=b}