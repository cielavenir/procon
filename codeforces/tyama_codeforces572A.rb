#!/usr/bin/ruby
z,(k,m),A,B=$<.map{|e|e.split.map &:to_i}
puts A.sort[k-1]<B.sort[-m] ? :YES : :NO