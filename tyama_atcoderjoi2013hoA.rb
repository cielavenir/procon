#!/usr/bin/ruby
gets
a=b=c=d=y=s=0
gets.split.map{|e|e=e.to_i
e==y ?(a,b,c=b,c,d):y=e
d+=1
s+=s<d-a ?1:0}
p s