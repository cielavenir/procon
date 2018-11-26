#!/usr/bin/ruby
f=->x,y{return[x,1,0]if y==0
g,a,b=f[y,x%y]
[g,b,a-x/y*b]}
a=(1..29).map{|i|[gets.to_i,i]}
r=a.reduce{|(a,m),(b,n)|g,x,y=f[m,n]
(b-=a)%g>0&&break
n*=m/g
[(a+b/g*x*m)%n,n]}
puts r&&(x=r[r[0]>0?0:1])<=1e12&&a.all?{|n,i|x.to_s(i+1).chars.map{|e|e.to_i(30)}.reduce(:+)==n}?x: :invalid
