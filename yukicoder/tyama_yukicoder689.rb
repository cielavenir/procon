#!/usr/bin/ruby
f=->n{n*~-n/2}
g=->k{(0..2*k).find{|e|f[e]>=k}}
c=f[b=g[d=f[a=g[k=gets.to_i]]-k]]-d
p a-~c,24,*[2]*b,*[7]*c,*[1]*a-=b
