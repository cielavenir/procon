#!/usr/bin/ruby
while(n=gets.to_f)>0
a=gets.split.map &:to_i;b=a.reduce(:+)/n;p (a.reduce(0){|s,e|s+(b-e)**2}/n)**0.5 end