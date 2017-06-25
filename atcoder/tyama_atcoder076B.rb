#!/usr/bin/ruby
n,*a=$<.map &:to_i;x=1;p (1..n).find{|i|2==x=a[x-1]}||-1
