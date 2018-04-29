#!/usr/bin/ruby
n=gets.to_i
m=$<.map{|e|e.chomp.chars}
p n*(0...n).count{|i|t=m.rotate(i);t==t.transpose}
