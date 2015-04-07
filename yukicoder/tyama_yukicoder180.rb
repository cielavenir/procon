#!/usr/bin/ruby
f=->(w){a,b=A.map{|a,b|a+b*w}.minmax;b-a}
A=$<.drop(l=1).map{|e|e.split.map &:to_i}
r=1<<30
f[x=(l*2+r)/3]<=f[y=(l+r*2)/3]?r=y :l=x while l+2<r
p (l..r).min_by &f