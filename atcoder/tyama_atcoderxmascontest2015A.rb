#!/usr/bin/ruby
require'openssl';n,x,t,a,b,c=`dd`.split.map &:to_i
g=a.to_bn.mod_exp(t,c)
h=a.to_bn.mod_exp(t,c*a-=1)/a
s=0
n.times{s+=x;x=(x*g+b*h[0])%c}
p s
