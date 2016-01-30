#!/usr/bin/ruby
n=gets.to_i
a=n.times.map{gets.split.map(&:to_i).max}
a[a.index(n-1)]=n
puts a*' '