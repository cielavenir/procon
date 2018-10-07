#!/usr/bin/ruby
h={};n=gets.to_i;a=[*0...n]
(1<<a.size).times{|i|x=0;y=[];a.size.times{|j|i[j]>0&&(x+=1<<a[j];y<<a[j])};h[x]=y}
puts h.sort.map{|k,v|k.to_s+':'+v.map{|e|' %d'%e}*''}
