#!/usr/bin/ruby
a=`dd`.split.map &:to_i;p (1..a[0]).count{|i|i==a[a[i]]}/2
