#!/usr/bin/ruby
h=Hash.new 0
gets
gets.chomp.chars.each_cons(2){|a|h[a]+=1}
puts h.max_by{|k,v|v}[0]*''
