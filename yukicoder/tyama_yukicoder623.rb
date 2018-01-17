#!/usr/bin/ruby
r,*c,_,a=$<.map{|e|e.split.map &:to_i}
a.map{|e|f=1,e;c.map{|t,x,y|f<<r=[x*y=f[y],y*x=f[x],x+y][t-2]%998244353};p r}
