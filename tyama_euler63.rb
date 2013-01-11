#!/usr/bin/ruby
B=10
p 1.step(B-1).map{|i|(1/(1-Math.log(i,B))).to_i}.reduce(&:+)