#!/usr/bin/ruby
gets
a=gets.split.map(&:to_i)
x=a[0]
b=a.select{|e|e!=x}
h,l=b.partition{|e|e>x}
puts (l+[x]*(a.size-b.size)+h)*' '