#!/usr/bin/ruby
_,k,t=$<.read.split
i=1;i+=1 while t[i..-1]!=t[0...-i]
puts t[0,i]*k.to_i+t[i..-1]
