#!/usr/bin/ruby
n,m,*a=$<.read.split.map &:to_i
s=q=0;r=[]
a.each{|e|s+=e;r<<s/m-q/m;q=s}
puts r*' '
