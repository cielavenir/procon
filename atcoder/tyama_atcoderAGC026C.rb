#!/usr/bin/ruby
f=->s,n{i=-1;s.chars.partition{n[i+=1]>0}}
n=gets.to_i
s=gets.chomp
t=s[n..-1].reverse
s=s[0,n]
n=2**n
h=Hash.new r=0
n.times{|i|h[f[s,i]]+=1}
n.times{|i|r+=h[f[t,i]]}
p r
