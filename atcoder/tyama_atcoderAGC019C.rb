#!/usr/bin/ruby
x1,y1,x2,y2,n,*A=`dd`.split.map &:to_i
xf=yf=1
x1>x2&&(x1,x2,xf=x2,x1,-1)
y1>y2&&(y1,y2,yf=y2,y1,-1)
V=[];A.each_slice(2){|x,y|(x1..x2)===x&&(y1..y2)===y&&V<<[x*xf,y*yf]}
#D=[F=1e9]*-~n;V.sort.map{|x,y|D[D.bsearch_index{|e|e>y}]=y};n=D.index{|e|e>=F}
D=[];n=-1;V.sort.map{|x,y|D[D.bsearch_index{|e|e>y}||n+=1]=y};n+=1 #lis()
p 1e2*(x2-x1+y2-y1)-20*n+5*(n+(n>[x2-x1,y2-y1].min ? 1:0))*Math::PI
