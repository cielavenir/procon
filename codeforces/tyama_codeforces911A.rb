#!/usr/bin/ruby
n,*a=$<.read.split.map &:to_i
b=[]
m=1<<30
a.each_with_index{|e,i|(b=[];m=e)if m>e;b<<i if m==e}
p b.each_cons(2).map{|x,y|y-x}.min
