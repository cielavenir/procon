#!/usr/bin/ruby
x,y=gets.split.map &:to_i
p x==1||y==1?1:x*y+1>>1
