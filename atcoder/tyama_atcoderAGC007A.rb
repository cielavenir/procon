#!/usr/bin/ruby
h,w=gets.split.map &:to_i
print $<.read.count(?#)==h+w-1?:P,:Imp,:ossible
