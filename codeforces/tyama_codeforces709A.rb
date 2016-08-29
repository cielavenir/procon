#!/usr/bin/ruby
n,b,d,*a=$<.read.split.map &:to_i
r=k=0
a.each{|e|e<=b&&(d<k+=e)&&(r+=1;k=0)}
p r