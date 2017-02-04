#!/usr/bin/ruby
n,*a=$<.read.split.map &:to_i;(n/2).times{|i|a[i],a[n-i-1]=a[n-i-1],a[i]if i.even?};puts a*' '
