#!/usr/bin/env crystal
W=[0]*9**6
a=ARGF.gets_to_end.split.map &.to_i
i=n=a.shift
z=(0...n).to_a.sort{|i,j|a[i]!=a[j] ? a[i]<=>a[j]: i<=>j}
r=0_i64
b=a.sort
while 0<=(i-=1)
k=z[i];while k>0;r+=W[k];k-=-k&k end
k=z[i]+1;while k<=n;W[k]+=1;k+=-k&k end
end
n.times{|i|puts r;r-=((0...n).bsearch{|j|a[i]<=b[j]}||n)-n+((0...n).bsearch{|j|a[i]<b[j]}||n)}
