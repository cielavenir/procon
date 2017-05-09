#!/usr/bin/ruby
a,b,c=gets.split.map &:to_i
puts (0..b).any?{|e|e*a%b==c}?:YES: :NO
