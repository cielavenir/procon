#!/usr/bin/ruby
s=r=0
gets
gets.split.each.with_index(1){|e,i|r=[r,(i-1+s+=e.to_i)/i].max}
p r