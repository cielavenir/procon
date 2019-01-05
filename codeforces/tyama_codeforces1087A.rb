#!/usr/bin/ruby
s=gets.chomp
puts s[0,-~s.size/2].reverse.chars.zip(s[-~s.size/2..-1].chars).map{|x,y|x+y.to_s}*''
