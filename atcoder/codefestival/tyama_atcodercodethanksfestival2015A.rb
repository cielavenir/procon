#!/usr/bin/ruby
a,b=$<.map &:to_i;p a*b<0?(a-b).abs*2:[a.abs,b.abs].max*2