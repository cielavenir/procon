#!/usr/bin/ruby
n,*a=$<.read.split.map &:to_i
puts n&a[0]&a[-1]&1>0 ? :YES : :NO
