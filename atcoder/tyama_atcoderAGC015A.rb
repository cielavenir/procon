#!/usr/bin/ruby
n,a,b=gets.split.map &:to_i;p [(n-2)*(b-a)+1,0].max
