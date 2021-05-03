#!/usr/bin/ruby
gets
a,b=gets.split.map &:to_i
c,d=gets.split.map &:to_i
p (c-a).abs+(d-b).abs
