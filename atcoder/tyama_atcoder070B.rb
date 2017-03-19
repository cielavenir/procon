#!/usr/bin/ruby
w,a,b=gets.split.map &:to_i;p [0,(a-b).abs-w].max
