#!/usr/bin/ruby
n,*a=$<.read.split.map &:to_i
p a.reduce :+
