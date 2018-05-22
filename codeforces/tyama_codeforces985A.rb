#!/usr/bin/ruby
n=gets.to_i
a=gets.split.map(&:to_i).sort
p [1,2].map{|s|a.zip(s.step(n,2).to_a).map{|x,i|(x-i).abs}.reduce :+}.min
