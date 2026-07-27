#!/usr/bin/ruby
n,*a=`dd`.split.map(&:to_i);m=a.max;p a.sum{|e|[e.abs,m].max}
