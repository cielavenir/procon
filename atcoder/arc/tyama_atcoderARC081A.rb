#!/usr/bin/ruby
x,a,b=gets.split.map &:to_i
p (x-a).abs<(x-b).abs ? :A : :B
