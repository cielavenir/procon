#!/usr/bin/ruby
n,a,b,*t=`dd`.split.map &:to_i;p t.count{|e|e<a||b<=e}
