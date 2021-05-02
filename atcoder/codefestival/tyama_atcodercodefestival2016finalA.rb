#!/usr/bin/ruby
H,W,*A=`dd`.split
z=999.times.find{|i|A[i]=='snuke'}
puts'%c%d'%[z%W.to_i+65,z/W.to_i+1]
