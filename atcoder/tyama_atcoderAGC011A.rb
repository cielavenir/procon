#!/usr/bin/ruby
n,c,k,*t=`dd`.split.map &:to_i
r=d=q=0
t.sort.map{|e|(e>q||d==c)&&(q=e+k;d=0;r+=1);d+=1}
p r
