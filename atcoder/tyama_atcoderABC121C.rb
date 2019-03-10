#!/usr/bin/ruby
(n,m),*a=$<.map{|e|e.split.map &:to_i};a.sort!
r=0
while m>0
m-=1
r+=a[0][0]
1>(a[0][1]-=1)&&a.shift
end
p r
