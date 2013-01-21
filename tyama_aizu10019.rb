#!/usr/bin/ruby
while(s=gets)!="0\n"
p s.chars.map(&:to_i).reduce(:+)end