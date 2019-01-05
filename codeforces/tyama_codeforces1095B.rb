#!/usr/bin/ruby
n,*a=$<.read.split.map &:to_i;a.sort!;p n<3?0:[a[-1]-a[1],a[-2]-a[0]].min
