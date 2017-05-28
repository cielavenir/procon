#!/usr/bin/ruby
f=->n{n>0?1<<n.to_s(2).size: 1}
#f=->n{1<<n.bit_length}
a,b=$<.map &:to_i
p (c=f[a^b])-(a&=c-1)-[a-f[(b&~-c)-c/2],0].max
