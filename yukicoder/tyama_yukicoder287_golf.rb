#!/usr/bin/ruby
n=gets.to_i+1
a=[90,77,0,140,210,98,15]
i=s=0
a.map{|e|s+=e*n**(i+=1)}
p s/630