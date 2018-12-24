#!/usr/bin/ruby
n,h,w=gets.split.map &:to_i
p n.times.count{a,b=gets.split.map &:to_i;a>=h&&b>=w}
