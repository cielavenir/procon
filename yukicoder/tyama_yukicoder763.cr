#!/usr/bin/env crystal
H=Hash(Int32,Array(Int32)).new{|h,k|h[k]=[] of Int32}
V=Hash(Int32,Int32).new
R=[0]
def f(j);a=true;V[j]=1;H[j].each{|e|!V.has_key?(e)&&f(e)&&(a=false)};a&&(R[0]+=1);a end
(gets.not_nil!.to_i-1).times{a,b=gets.not_nil!.split.map &.to_i;H[a]<<b;H[b]<<a}
f 1;p R[0]
