#!/usr/bin/ruby
n,*a=$<.read.split.map &:to_i
a<<r=q=0
a.each{|e|e==1 ? q+=1 : (r=[q,r].max;q=0)}
p r+1
