#!/usr/bin/ruby
STDOUT.sync = true
LX, LY, TX, TY = gets.split(" ").collect {|x| x.to_i}

x=LX-TX
y=LY-TY
a=[y<0 ? 'N' : 'S']*y.abs+[nil]*([y.abs,x.abs].max-y.abs)
b=[x<0 ? 'W' : 'E']*x.abs
puts a.zip(b).map{|x,y|(x||'')+(y||'')}