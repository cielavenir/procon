#!/usr/bin/ruby
n,k,*a=`dd`.split.map &:to_i;puts a.rotate(k)*' '
