#!/usr/bin/ruby
n,*a=$<.read.split.map &:to_r
$><<(a.shift(n).reduce(:/)/a[1..-1].reverse.reduce{|s,e|e/s}).to_s.tr(?/,' ')
