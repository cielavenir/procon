#!/usr/bin/ruby
h=Hash.new 0
gets.chomp.chars{|c|h[c]^=1}
s=h.reduce(0){|s,(k,v)|s+v}
p s/2
