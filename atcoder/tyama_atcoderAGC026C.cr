#!/usr/bin/env crystal
def f(s,n)i=-1;s.chars.partition{i+=1;n>>i&1>0}end
n=gets.not_nil!.to_i
s=gets.not_nil!.chomp
t=s[n..-1].reverse
s=s[0,n]
n=2**n
h=Hash(Tuple(Array(Char),Array(Char)),Int64).new r=0_i64
n.times{|i|h[f s,i]+=1}
n.times{|i|r+=h[f t,i]}
puts r
