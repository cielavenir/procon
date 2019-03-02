#!/usr/bin/ruby
a,b=gets.split.map &:to_f
p a*b*100/(a*b+(100-a)*(100-b))
