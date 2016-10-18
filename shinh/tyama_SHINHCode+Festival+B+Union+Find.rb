#!/usr/bin/ruby
P=[*0..1e5];r=->(a){P[a]=a==P[a]?a:r[P[a]]};gets;while gets;t,x,y=$_.split.map &:to_i;x=r[x];y=r[y];t>0?puts(x==y ?:YES: :NO):P[x]=y;end