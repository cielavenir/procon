#!/usr/bin/ruby
s=gets.chomp
n=s.size
k=s.chars.group_by{|e|e}.count{|k,v|v.size%2>0}
p k==0?n:(n-k)/k/2*2+1