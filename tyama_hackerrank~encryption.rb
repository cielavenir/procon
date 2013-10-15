#!/usr/bin/ruby
def zip(a) a.shift.zip(*a) end
s=gets.chomp
n=Math.sqrt(s.size).ceil
puts zip(s.chars.each_slice(n).to_a).map(&:join)*' '