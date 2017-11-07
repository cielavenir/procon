#!/usr/bin/ruby
x,y,n,*a=$<.map &:to_i;p (n-a.uniq.size)*(x+y)
