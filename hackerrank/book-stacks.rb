#!/usr/bin/ruby
gets
a=gets.split.map(&:to_i).sort
p (1...a.size).reduce(a[0]+(a[0]-1)*2){|s,i|s+a[i]+(a[i]-1)}