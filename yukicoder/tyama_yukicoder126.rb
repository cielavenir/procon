#!/usr/bin/ruby
A,B,C=gets.split.map(&:to_i)
p (a=(A-C).abs)>(b=(B-C).abs)? b+(A<C ? C+1-(-A)[9]:[C-1,A-C].min+A): a+C