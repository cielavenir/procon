#!/usr/bin/ruby
n=gets.to_i
a=n.times.map{gets.split.map(&:to_i)}
p n.times.reduce(0){|s,i|s+Math.hypot(a[i][0]-a[(i+1)%n][0],a[i][1]-a[(i+1)%n][1])}
