#!/usr/bin/ruby
n,x,*a=`dd`.split.map &:to_i;a.sort!
i=(0...n).find{|i|0>x-=a[i]}
p i ? i : x>0 ? n-1 : n
