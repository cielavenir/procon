#!/usr/bin/ruby
n,z,w,*a=`dd`.split.map &:to_i;p [(a[-1]-w).abs,((a[-2]||a[-1])-a[-1]).abs].max
