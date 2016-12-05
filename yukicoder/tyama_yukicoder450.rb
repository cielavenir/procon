#!/usr/bin/ruby
a,b,c,d=`dd`.split.map &:to_f;p c*d/(a+b)
