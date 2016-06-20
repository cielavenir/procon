#!/usr/bin/ruby
a=$<.map(&:to_i)
p a.reduce(:+)-a[0,4].min-a[4,2].min