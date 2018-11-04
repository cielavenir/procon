#!/usr/bin/ruby
n,t,a,*h=`dd`.split.map &:to_i
p (1..n).min_by{|i|(t-h[i-1]*0.006-a).abs}
