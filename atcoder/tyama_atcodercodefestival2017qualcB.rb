#!/usr/bin/ruby
n,*a=`dd`.split.map &:to_i;p 3**n-2**a.count(&:even?)
