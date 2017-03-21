#!/usr/bin/ruby
n,*a=`dd`.split.map &:to_i;a.sort!
s=0
p~-n-((0...n-1).select{|i|(2*s+=a[i])<a[i+1]}[-1]||-1)
