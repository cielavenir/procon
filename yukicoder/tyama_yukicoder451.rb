#!/usr/bin/ruby
n,*b=$<.map &:to_i
l,h=1,1<<60
n.times{|i|l,h=[[[b[i]-h,1].max,b[i]-l],[[l-b[i],1].max,h-b[i]]][i%2]}
a=[l]
(n-1).downto(0){|i|a<<b[i]+a[-1]*(i%2*2-1)}
puts l>h ?-1:[n+1,*a.reverse]
