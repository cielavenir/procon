#!/usr/bin/ruby
n,k,q=gets.split.map(&:to_i)
a=gets.split.map(&:to_i).rotate(-k)
q.times{p a[gets.to_i]}