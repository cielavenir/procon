#!/usr/bin/ruby
H=Hash.new 0
gets
gets.chomp.chars{|c|H[c]+=1}
p [H['U'],H['D']].min+[H['L'],H['R']].min<<1
