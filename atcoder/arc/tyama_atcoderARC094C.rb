#!/usr/bin/ruby
a,b,c=gets.split.map &:to_i
m=[a,b,c].max
s=a+b+c
m+=1 if m%2!=s%2
m*=3
p (m-s)/2
