#!/usr/bin/ruby
n,*a=$<.read.split.map(&:to_i)
(n-1).downto(0){|i|n-=1 if a[i]==n}
p n