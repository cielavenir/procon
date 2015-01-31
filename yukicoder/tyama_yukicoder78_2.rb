#!/usr/bin/ruby
N,K=gets.split.map &:to_i
S=gets
b=[0]*(N+1)
a=0
1.step(N){|i|a==0&&b[i]=a=1
b[i]+=b[i-1]
a+=S[i-1].to_i-1}
d,r=(K-1).divmod(N)
p d==0?b[r+1]:b[-1]+(d-1)*[b[-1]-a,0].max+[b[r+1]-a,0].max