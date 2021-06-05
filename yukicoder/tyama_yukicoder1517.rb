#!/usr/bin/ruby
d,a,b=`dd`.split.map &:to_i
p (a-b)*(a>b ? 0 : d)+b*d
