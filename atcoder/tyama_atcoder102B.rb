#!/usr/bin/ruby
x1,y1,x2,y2=gets.split.map &:to_i
dx=x2-x1;dy=y2-y1
puts [x2-dy,y2+dx,x1-dy,y1+dx]*' '
