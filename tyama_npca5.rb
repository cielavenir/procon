#!/usr/bin/ruby
n,m=gets.split.map(&:to_i)
p n.times.count{a,b=gets.split.map(&:to_i);a<=m&&m<=b}