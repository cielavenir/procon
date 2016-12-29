#!/usr/bin/ruby
f=->a{($>.<<("? %d %d\n"%a)).flush;gets.to_i}
n=gets.to_i
g=n^1<<(n.to_s(2).size-1)
r=f[[g,n]]
(k=g&-g;(k<<1&g)>0?r-=f[[g,g+=k]]:r+=f[[g-=k,g+k]])while g>0
puts'! %d'%r
