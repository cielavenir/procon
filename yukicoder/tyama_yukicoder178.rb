#!/usr/bin/ruby
a=$<.drop(1).map{|e|a,b=e.split.map &:to_i;a+4*b}
s=0
p a.all?{|e|(s+=a.max-e)%2<1}?s/2:-1