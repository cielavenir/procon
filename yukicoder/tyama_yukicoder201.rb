#!/usr/bin/ruby
(a,x),(b,y)=$<.map &:split
puts [-1,a,b][x.to_i<=>y.to_i]
#puts [b,-1,a][(x.to_i<=>y.to_i)+1]