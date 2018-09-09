#!/usr/bin/ruby
a,b,c=gets.split.map &:to_i;s=a+b+c;p [a,b,c].uniq.size==2 ? 2 : [3*a,3*b,3*c].include?(s) ? 3 : -1
