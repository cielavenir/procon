#!/usr/bin/ruby
n,m=gets.split.map &:to_i
v={1=>r=[1]}
h=Hash.new{|h,k|h[k]=[]}
m.times{a,b=gets.split.map &:to_i;h[a]<<b;h[b]<<a}
f=->x{1while h[x].any?{|e|!v[e]&&v[e]=r<<x=e}}
f[1]
r.reverse!
f[1]
p r.size,*r
#puts r*' '
