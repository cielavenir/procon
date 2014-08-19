#!/usr/bin/ruby
n=gets.to_i*2
a=[1]
n.times{a=[1]+a.each_cons(2).map{|x,y|x+y}+[1]}
n.downto(1){|i|a[i-1]+=a[i]}
puts (1..n).map{|i|Math.log10(a[i]*0.5**n)}*' '