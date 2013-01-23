#!/usr/bin/ruby
a=[]
n=gets.to_i
while s=gets do a.push(s) end
puts a.sort{|a,b|-(a.length<=>b.length)}[0,n]