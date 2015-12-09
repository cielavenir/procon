#!/usr/bin/ruby
a,b,c,x,y,z=$<.read.split.map &:to_i
t=[a,x].min;a-=t;x-=t
t=[b,y].min;b-=t;y-=t
t=[c,z].min;c-=t;z-=t
puts [a,b,c].map{|e|e/2}.reduce(:+)>=[x,y,z].reduce(:+) ? :Yes : :No