#!/usr/bin/ruby
A,B=gets.split.map &:to_i
a=-~A/2
b= ~-B/2
p (a*2!=A ? A : 0)^(b*2!=~-B ? B : 0)^(b-a&1^1)
