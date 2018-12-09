#!/usr/bin/ruby
n,k,*a=`dd`.split.map &:to_i;a.sort!;p (n-k+1).times.map{|i|a[i+k-1]-a[i]}.min
