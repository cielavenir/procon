#!/usr/bin/ruby
n,*a=`dd`.split.map &:to_i
p n^a[-1]^a.count{|e|e%2==0}
