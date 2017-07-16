#!/usr/bin/ruby
n,k,*a=`dd`.split.map &:to_i;p a.max(k).reduce :+
