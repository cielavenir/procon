#!/usr/bin/ruby
a,b=gets.split.map &:to_i
b.times{a=a%10==0?a/10:a-1}
p a
