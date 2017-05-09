#!/usr/bin/ruby
x,y,t,*a=`dd`.split.map &:to_i
r=y
a.each{|e|r+=[e-t,y].min;t=e}
p r
