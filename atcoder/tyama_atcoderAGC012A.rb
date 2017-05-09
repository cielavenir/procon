#!/usr/bin/ruby
n,*a=`dd`.split.map &:to_i;a.sort_by! &:-@;p n.times.map{|i|a[2*i+1]}.reduce :+
