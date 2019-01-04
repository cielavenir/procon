#!/usr/bin/ruby
gets
h=Hash.new r=s=0
$<.each{|e|a,b=e.split.map &:to_i;h[a]+=1;h[b+1]-=1}
h.sort.each{|k,v|r=[r,s+=v].max}
p r
