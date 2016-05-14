#!/usr/bin/ruby
n=gets.to_i
h={}
gets.chomp.chars{|c|h[c]=1}
p n>26 ? -1 : n-h.size