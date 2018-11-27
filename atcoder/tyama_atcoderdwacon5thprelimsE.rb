#!/usr/bin/ruby
n,*a=`dd`.split.map &:to_i;a.sort!;r=1;n.times{|i|r*=a[i].gcd i};p r%998244353
