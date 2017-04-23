#!/usr/bin/ruby
a,b,c,d=$<.map &:to_i
p (a^b)&(c|d)^((b&c)|(a^d))
