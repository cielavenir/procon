#!/usr/bin/ruby
gets;$<.map{|e|n,d=e.split.map &:to_i;p 127*n+[-d,d-127][n%2]}
