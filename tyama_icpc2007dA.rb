#!/usr/bin/ruby
while(n=gets.to_i)>0
p n.times.map{gets.to_i}.sort[1..-2].reduce(:+)/(n-2)end
#a=n.times.map{gets.to_i};p (a.reduce(:+)-a.max-a.min)/(n-2)end
#original:
#p n.times.map{gets.to_i}.sort.drop(1).take(n-2).reduce(:+)/(n-2)