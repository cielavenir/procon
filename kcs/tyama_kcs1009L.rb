#!/usr/bin/ruby
h,m=gets.split.map(&:to_i)
p (h+m)^(h-m)^(h/m)^(h*m)