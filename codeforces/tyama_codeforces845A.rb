#!/usr/bin/ruby
n,*a=$<.read.split.map &:to_i
a.sort!
puts a[n-1]<a[n]?:YES: :NO
