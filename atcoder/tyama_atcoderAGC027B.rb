#!/usr/bin/ruby
n,c,*x=`dd`.split.map &:to_i
*s=0;x.map{|e|s<<s[-1]+e}
p (1..n).map{|k|t=5*s[n]+(k+n)*c;(n-k*2).step(1,-k){|o|t+=2*s[o]};t}.min
