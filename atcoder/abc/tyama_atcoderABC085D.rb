#!/usr/bin/ruby
n,h=gets.split.map &:to_i
a,b=$<.map{|e|e.split.map &:to_i}.transpose
amax=a.max
i=0
r=b.sort_by(&:-@).find{|e|e>amax&&(i+=1;h-=e;h<=0)}
p r ? i : i+(h+amax-1)/amax
