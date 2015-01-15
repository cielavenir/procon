#!/usr/bin/ruby
a=10.times.map{|i|3**i}
r=a.dup
2.step(a.size-1){|n|a.combination(n){|b|r<<b.reduce(:+)}}
puts r.sort[0,100]