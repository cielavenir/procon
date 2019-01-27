#!/usr/bin/ruby
gets;puts$<.map{|e|k,x=e.split.map &:to_i;x+9*~-k}
