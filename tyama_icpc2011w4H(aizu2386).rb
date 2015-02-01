#!/usr/bin/ruby
n=gets.to_i
m=(1..n).map{gets.split.map(&:to_i)}
s=0
[*0...n].combination(2){|x,y|s+=[m[x][y],m[y][x]].min}
p s