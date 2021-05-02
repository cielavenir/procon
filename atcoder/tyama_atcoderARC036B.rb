#!/usr/bin/ruby
n=gets.to_i
a=n.times.map{gets.to_i}
b=[0]+(1..n-2).select{|i|a[i-1]>a[i]&&a[i]<a[i+1]}+[n-1]
p b.each_cons(2).map{|x,y|y-x}.max+1