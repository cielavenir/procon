#!/usr/bin/ruby
n,*a=`dd`.split.map &:to_i;puts (1..n).sort_by{|i|-a[i-1]}