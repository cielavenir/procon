#!/usr/bin/ruby
n=gets.to_i
p ([0]+gets.split.map{|e|e.to_i-1}).each_cons(2).map{|a,b|b-a<0 ? b+n-a : b-a}.reduce(:+)