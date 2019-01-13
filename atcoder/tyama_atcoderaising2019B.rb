#!/usr/bin/ruby
n,a,b,*t=`dd`.split.map &:to_i
x,y,z=t.group_by{|e|e<=a ? 0 : e<=b ? 1 : 2}.map{|k,v|v.size}
p [x,y.to_i,z.to_i].min
