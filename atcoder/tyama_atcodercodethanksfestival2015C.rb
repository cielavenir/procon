#!/usr/bin/ruby
n,*a=$<.read.split.map &:to_i;p 1+(0..n).find{|i|a[i]>=a[n]}