#!/usr/bin/ruby
n=gets.to_i
z=$<.map{|e|e.split.map &:to_i}
a,b=z.transpose
x=a.sort[n/2]
y=b.sort[n/2]
p z.map{|a,b|(a-x).abs+(b-a)+(y-b).abs}.reduce :+
