#!/usr/bin/ruby
n,m,*a=$<.map &:to_i
puts [[(a.reduce(:+)+m+n-1)/n,a.max].max,a.max+m]*' '
