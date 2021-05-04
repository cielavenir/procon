#!/usr/bin/ruby
n,h,*t=`dd`.split.map &:to_i;puts t.map{|e|e+h}*' '
