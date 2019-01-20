#!/usr/bin/ruby
N,K,R=gets.split.map &:to_i
M=(N-K)*(N-K+1)/2
R>M&&(puts"No Luck";exit)
r=M-R
h={}
(N-K).downto(1){|j|r>=j&&(r-=j;h[N-K-j+1]=1)}
h=h.keys.sort
p *h+([*1..N]-h).reverse
