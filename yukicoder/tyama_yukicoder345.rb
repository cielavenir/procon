#!/usr/bin/ruby
s=gets
r=a=b=2*N=s.size
N.downto(0){|i|s[i]==?w?(a,b=b,i):s[i]==?c?r=[r,a-i+1].min : 0}
p r>N ? -1 : r