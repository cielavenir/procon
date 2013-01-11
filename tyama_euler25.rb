#!/usr/bin/ruby
a,b,c,n=1,1,2,3
while c<10**999 do a,b,c,n=b,c,b+c,n+1 end
p n