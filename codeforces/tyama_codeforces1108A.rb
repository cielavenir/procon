#!/usr/bin/ruby
gets;puts$<.map{|e|a,b,c,d=e.split.map &:to_i;[a,(c!=a ? c : d)]*' '}
