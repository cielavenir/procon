#!/usr/bin/ruby
x,y=gets.split.map &:to_f
print [x,1-y].min,' ',x-[x,y].min