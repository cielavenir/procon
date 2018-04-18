#!/usr/bin/ruby
n,*a=$<.read.split.map &:to_i
s=a.reduce :+
r=0
p (1..n).find{|i|(r+=a[i-1])*2>=s}
