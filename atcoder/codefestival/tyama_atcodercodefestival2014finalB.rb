#!/usr/bin/ruby
s=gets.chomp
r=0
s.each_char.with_index{|c,i|r+=c.to_i*(i%2==0 ? 1 : -1)}
p r