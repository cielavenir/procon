#!/usr/bin/ruby
_,k,*a=`dd`.split.map &:to_i
p a.max>0 ? a.select{|e|e>0}.max(k).sum : a.max
