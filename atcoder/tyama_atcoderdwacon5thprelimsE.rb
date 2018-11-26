#!/usr/bin/ruby
n,*a=`dd`.split.map &:to_i;a.sort!
(1...n).map{|i|a[0]=a[0]*a[i].gcd(i)%998244353}
p a[0]
