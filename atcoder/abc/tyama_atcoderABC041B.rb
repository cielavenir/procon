#!/usr/bin/ruby
a,b,c=gets.split.map &:to_i;p a*b*c%(10**9+7)