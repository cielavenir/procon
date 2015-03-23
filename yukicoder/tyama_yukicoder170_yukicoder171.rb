#!/usr/bin/ruby
r=1;t=0
gets.chop.bytes.group_by{|e|e}.map{|k,v|v.size.times{|i|r=r*(t+=1)/-~i}}
p ~-r%573