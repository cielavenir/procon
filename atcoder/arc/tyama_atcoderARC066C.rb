#!/usr/bin/ruby
n,*a=`dd`.split.map &:to_i;p a.sort!=n.times.map{|i|(i+n%2)&~1^~n%2}?0:2**(n/2)%(10**9+7)
