#!/usr/bin/ruby
N,X=gets.split.map &:to_i;S=2*N-1
puts S>X&&X>1?[:Yes,*(0...S).map{|i|1+(X-N+i)%S}]: :No
