#!/usr/bin/ruby
gets;$<.each{|e|s,a,b,c=e.split.map &:to_i;p s/c/a*b+s/c}
