#!/usr/bin/ruby
n=gets.to_i
p n.times.map{gets.chomp}.zip(n.times.map{gets.chomp}).count{|a,b|a==b}