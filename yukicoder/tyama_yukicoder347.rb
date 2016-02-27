#!/usr/bin/ruby
_,b,*a=$<.read.split.map &:to_f
x=y=0
a.map{|e|x+=e*b**(e-1);y+=e!=-1?b**(e+1)/(e+1):Math.log(b)}
p x
p y