#!/usr/bin/ruby
gets
a=gets.chars.chunk{|c|c}.select{|k,v|k=='B'}.map{|k,v|v.size}
p a.size
puts a*' '
