#!/usr/bin/ruby
a,b,c=gets.split.map &:to_i;p a.downto(1).select{|i|a%i==0&&b%i==0}[c-1]
