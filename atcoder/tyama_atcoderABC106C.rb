#!/usr/bin/ruby
s=gets.chomp
k=gets.to_i
q=(0...[k,s.size].min).find{|i|s[i]!=?1}
puts q ? s[q] : 1
