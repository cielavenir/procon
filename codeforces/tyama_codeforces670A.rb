#!/usr/bin/ruby
n=gets.to_i
r,d=n.divmod(7)
puts [[0,0],[0,1],[0,2],[0,2],[0,2],[0,2],[1,2]][d].map{|e|e+r*2}*' '