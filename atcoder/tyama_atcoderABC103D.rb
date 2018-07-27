#!/usr/bin/ruby
r=t=0
(n,m),*a=$<.map{|e|e.split.map &:to_i}
a.sort_by{|x,y|y}.map{|x,y|x>t&&(r+=1;t=y-1)}
p r
