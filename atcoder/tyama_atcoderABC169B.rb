#!/usr/bin/ruby
gets
a=gets.split.map &:to_i
p a.count(0)>0 ? 0 : a.reduce(1){|s,e|s*e<=10**18 ? s*e : (break -1)}
