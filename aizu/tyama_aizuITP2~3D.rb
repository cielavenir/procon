#!/usr/bin/ruby
a,b=2.times.map{gets;gets.split.map &:to_i}
p [0,0,1][a<=>b]
