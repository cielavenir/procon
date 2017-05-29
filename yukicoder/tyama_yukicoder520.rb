#!/usr/bin/ruby
M=10**9+7;A=[[1]];1.upto(999){A<<[1]+A[-1].each_cons(2).map{|x,y|(x+y)%M}+[1]}
g=->a,b,c{$m[[a,c]]||=A[a+b+c][b-1]+(a>0?g[a-1,b,c]:A[b+c][b])+(c>0?g[a,b,c-1]:A[a+b][a])%M}
gets;$<.map{|e|$m={};a,b,c=e.split.map &:to_i;p (A[a+b+c-1][b-1]+g[a-1,b,c-1])%M}
