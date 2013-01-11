#!/usr/bin/ruby
a=[1,2]
i=1;while(s=a[i]+a[i-1])<4000000 do a<<s;i+=1 end
p a.reduce(0){|s,e|s+=e%2==0?e:0}