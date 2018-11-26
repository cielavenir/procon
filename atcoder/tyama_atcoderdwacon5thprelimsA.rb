#!/usr/bin/ruby
n,*a=`dd`.split.map &:to_i
q=a.reduce(:+)
p (0...n).min_by{|i|(a[i]*n-q).abs}
