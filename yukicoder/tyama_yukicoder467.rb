#!/usr/bin/ruby
n,*d,x,y=`dd`.split.map{|e|e.to_i.abs}
x=[x,y].max
p x==0?0:d.index(x)?1:x<(m=d.max)?2:(x+m-1)/m
