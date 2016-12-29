#!/usr/bin/ruby
require'prime'
n,x=gets.split.map &:to_i
a=(x+=1).prime_division.map{|k,v|(0..v).map{|i|k**i}}
a=a.pop.product(*a).map{|e|e.reduce :*}.sort
m={}
f=->x,n,d{r=0;x<2&&n==0?1:m[[x,n,d]]||=d.downto(1){|i|x%a[i]>0||r+=f[x/a[i],n-1,i]}&&r}
p f[x,n,a.size-1]
