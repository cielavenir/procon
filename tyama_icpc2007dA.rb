#!/usr/bin/ruby
while(n=gets.to_i)>0
a=n.times.map{gets.to_i};p (a.reduce(:+)-a.max-a.min)/(n-2)end
#original:
#p n.times.map{gets.to_i}.sort.drop(1).take(n-2).reduce(:+)/(n-2)