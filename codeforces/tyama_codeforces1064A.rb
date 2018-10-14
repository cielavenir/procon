#!/usr/bin/ruby
a,b,c=gets.split.map(&:to_i).sort
p [c-a-b+1,0].max
