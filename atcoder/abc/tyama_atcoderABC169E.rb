#!/usr/bin/ruby
n=gets.to_i
a,b=n.times.map{gets.split.map &:to_i}.transpose.map{|e|(e.sort[(n-1)/2]+e.sort[n/2])}
p (b-a)/(1+n%2)+1
