#!/usr/bin/ruby
a,b,c,d=gets.split.map &:to_i;x=(a-c).abs;y=(b-d).abs;p x*y==0?0:x+y-x.gcd(y)
