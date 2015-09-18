#!/usr/bin/ruby
x,y,X,Y=gets.split.map &:to_i
x-=X
y-=Y
a=[y<0??N:?S]*y.abs+[nil]*([y.abs,x.abs].max-y.abs)
b=[x<0??W:?E]*x.abs
puts a.zip(b).map{|x,y|(x||'')+(y||'')}