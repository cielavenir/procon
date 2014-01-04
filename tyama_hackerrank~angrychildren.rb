#!/usr/bin/ruby
n=gets.to_i
k=gets.to_i
a=n.times.map{gets.to_i}.sort
p (n-k+1).times.map{|i|a[i+k-1]-a[i]}.min