#!/usr/bin/ruby
n,z,*a=`dd`.split.map &:to_i;p a.map{|e|e.gcd z}.reduce &:lcm
