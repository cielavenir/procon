#!/usr/bin/ruby
n,*a=$<.map &:to_i;p (n-1+m=a.min)/m+4
