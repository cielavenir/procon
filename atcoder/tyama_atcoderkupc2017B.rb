#!/usr/bin/ruby
n,s,t=gets.split.map &:to_i;p s==t>>(k=t.bit_length-s.bit_length)?k:-1
