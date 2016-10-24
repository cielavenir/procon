#!/usr/bin/ruby
k,t,*a=`dd`.split.map &:to_i;p [2*a.max-1-k,0].max
