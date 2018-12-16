#!/usr/bin/ruby
n,k,*a=$<.read.split.map &:to_i
a=a.uniq.sort
q=0
k.times{p (x=a.shift||q)-q;q=x}
