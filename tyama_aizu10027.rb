#!/usr/bin/ruby
h=[[0,3],[1,1],[3,0]]
puts gets.to_i.times.map{h[gets.chomp.split.reduce(:<=>)+1]}.reduce([0,0]){|s,e|s.zip(e).map{|z|z.reduce(:+)}}*' '