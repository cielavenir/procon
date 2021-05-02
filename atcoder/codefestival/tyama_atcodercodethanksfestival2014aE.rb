#!/usr/bin/ruby
r,c,k,_,*a=$<.read.split.map &:to_i
m=(r+1).times.map{[0]*-~c}
a=[*a.each_slice(4)].each{|x,y,z,w|m[x-1][z-1]+=1;m[y][z-1]-=1;m[x-1][w]-=1;m[y][w]+=1}
t=n=0
r.times{|i|c.times{|j|m[i][j+1]+=m[i][j]}}
r.times{|i|c.times{|j|m[i+1][j]+=m[i][j]}}
r.times{|i|c.times{|j|t+=1 if 0==m[i][j]%=4}}
a.map{|x,y,z,w|n+=1;s=t;(x-1..y-1).map{|i|(z-1..w-1).map{|j|s-=1 if m[i][j]==0;s+=1 if m[i][j]==1}};p n if s==k}