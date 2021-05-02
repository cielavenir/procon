#!/usr/bin/ruby
n=gets.to_i
a=gets.split.map &:to_i
s=a.reduce :+
gets.to_i.times{x,y=gets.split.map &:to_i;p s-a[x-1]+y}
