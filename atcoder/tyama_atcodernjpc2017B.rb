#!/usr/bin/ruby
g=->{gets.split.map &:to_i}
h,w,n=g[];r=0;a={}
n.times{y,x=g[];r+=4-(y==h||y==1?1:0)-(x==w||x==1?1:0)-(h==1?1:0)-(w==1?1:0);a[[y,x]]=1}
a.map{|(y,x),_|[[1,0],[0,1]].map{|dy,dx|a[[y+dy,x+dx]]&&r-=1}}
p 2*h*w-h-w-r
