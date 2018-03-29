#!/usr/bin/ruby
N,K,*A=`dd`.split.map &:to_i
puts A.reduce(0){|s,e|s^e%-~K}<1 ? :NO : :YES
