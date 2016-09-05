#!/usr/bin/ruby
n,l,*a=`dd`.split.map &:to_i;puts (z=(1...n).find{|i|a[i-1]+a[i]>=l})?[:Possible,*1...z,[*z...n].reverse]: :Impossible