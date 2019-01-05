#!/usr/bin/ruby
a,b,c=gets.split.map &:to_i;p 3*[a+1,b,c-1].min
