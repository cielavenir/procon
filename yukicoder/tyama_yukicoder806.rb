#!/usr/bin/ruby
h=Hash.new r=0
gets
$<.map{|e|a,b=e.split.map &:to_i;h[a]+=1;h[b]+=1}
h.each_value{|e|r+=e-2 if e>2}
p r
