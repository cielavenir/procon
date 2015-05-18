#!/usr/bin/ruby
A,B,C=gets.split.map &:to_i
p (a=(A-C).abs)>(b=(B-C).abs)&&C>1?b+(A<1?C+1:[a,C-1].min+A):a+C