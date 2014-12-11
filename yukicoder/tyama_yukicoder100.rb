#!/usr/bin/ruby
n=gets.to_i;f=[];a=gets.split.map{|e|e.to_i-1};puts n.times.map{|i|f[i]?1:(x=a[i];c=1;while x!=i
f[x]=1;x=a[x];c+=1;end;c)}.group_by{|e|e}.all?{|k,v|k%2==1||v.size%2==0}?:Yes: :No