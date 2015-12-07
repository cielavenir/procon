#!/usr/bin/ruby
n,*a=$<.read.split.map &:to_i
p 1+((0...n).bsearch{|i|a[i]>a[n]}||n)