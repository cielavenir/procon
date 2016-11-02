#!/usr/bin/ruby
n,*a=`dd`.split.map &:to_i
a.sort_by! &:-@
i=(0...n).find{|x|a[x]<x+1}||n
j=(i...n).find{|x|a[x]<i}||n
puts (a[i-1]-i)%2+(j-i)%2>0?:First: :Second
