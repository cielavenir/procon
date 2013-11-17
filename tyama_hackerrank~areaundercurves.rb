#!/usr/bin/ruby
d=0.001
a=gets.split.map(&:to_i)
b=gets.split.map(&:to_i)
l,r=gets.split.map(&:to_i)
p d*l.step(r,d).map{|z|a.size.times.map{|i|a[i]*z**b[i]}.reduce(:+)}.reduce(:+)
p d*Math::PI*l.step(r,d).map{|z|a.size.times.map{|i|a[i]*z**b[i]}.reduce(:+)**2}.reduce(:+)