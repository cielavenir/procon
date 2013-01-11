#!/usr/bin/ruby
n,q,d=gets.split.map(&:to_i)
a=gets.split.map(&:to_i).each.reduce([0]){|a,e|a<<e+a[a.length-1]}
q.times{|i|s,t=gets.split.map(&:to_i);p (a[t]-a[s-1])%d}