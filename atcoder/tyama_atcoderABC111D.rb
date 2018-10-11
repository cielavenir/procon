#!/usr/bin/ruby
n,m=gets.split.map &:to_i
i=r=0
while i*i<=m
i+=1
next if m%i>0
r=[r,i].max if i<=m/n
r=[r,m/i].max if m/i<=m/n
end
p r
