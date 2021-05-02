#!/usr/bin/ruby
n=gets.to_i
a=[0]*-~n
b=[0]*-~n
z=gets.split.map &:to_i
n.times{|i|a[i+1]=a[i].gcd z[i]}
n.downto(1){|i|b[i-1]=b[i].gcd z[i-1]}
p n.times.map{|i|a[i].gcd b[i+1]}.max
