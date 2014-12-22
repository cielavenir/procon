#!/usr/bin/ruby
h=Hash.new(0)
gets.chomp.each_char{|c|h[c]+=1}
puts h.count{|k,v|v%2==1}<2 ? :YES : :NO