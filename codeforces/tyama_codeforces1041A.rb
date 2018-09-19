#!/usr/bin/ruby
n,*a=$<.read.split.map &:to_i
p a.max-a.min+1-n
