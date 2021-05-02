#!/usr/bin/ruby
M=10**9+7;N=gets.to_i;G=(0..N).map{[]};$<.map{|_|a,b=_.split.map &:to_i;G[a]<<b;G[b]<<a}
F=->x,y{w=b=1;G[x].each{|e|(c,d=F[e,x];w=w*(c+d)%M;b*=c)if e!=y};[w,b]}
w,b=F[1,0];p (w+b)%M
