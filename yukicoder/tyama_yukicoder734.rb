#!/usr/bin/ruby
a,b,c=gets.split.map &:to_i;p (k=60*a-b)>0 ? (3600*c+k-1)/k : -1
