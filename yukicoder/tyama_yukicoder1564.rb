#!/usr/bin/ruby
n,*a=`dd`.split.map &:to_i;a.sort!;r=0;a.each_slice(2){|a,b|r+=a*b};p r
