#!/usr/bin/ruby
x,y=gets.split.map &:to_i;p y-x-(x*y<0?1:0)