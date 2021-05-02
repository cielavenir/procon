#!/usr/bin/ruby
a,b=gets.split.map &:to_i;m=[a,b].max;p a==b ? a*2 : m+m-1
