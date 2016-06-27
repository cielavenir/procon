#!/usr/bin/ruby
a,b,k,l=gets.split.map &:to_i;p k/l*b+[k%l*a,b].min