#!/usr/bin/ruby
n,*a=`dd`.split.map &:to_i;a.sort!;r=0;n.times{|i|r+=(i+1-a[i]).abs};p r
