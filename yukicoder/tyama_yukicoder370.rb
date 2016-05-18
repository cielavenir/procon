#!/usr/bin/ruby
n,m,*d=$<.read.split.map &:to_i
d.sort!
p (n..m).map{|i|x,y=d[i-n],d[i-1];y<0?-x:x>0?y:y-x+[y,-x].min}.min