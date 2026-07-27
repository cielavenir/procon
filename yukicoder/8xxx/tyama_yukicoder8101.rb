#!/usr/bin/ruby
n=gets.to_i;a=0
(n=n.to_s.chars.map(&:to_i).reduce(:*);a+=1)while n>9
p a
