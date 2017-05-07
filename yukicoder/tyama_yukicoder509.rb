#!/usr/bin/ruby
s=gets.chomp
p [x=s.size,y=1+s.bytes.reduce(0){|s,e|s+[1,0,0,0,1,0,1,0,2,1][e-48]}].min+x+y
