#!/usr/bin/ruby
N,*t=`dd`.split.map &:to_i;d=t.shift N;M,*t=t
t,d=[t,d].map{|e|h=Hash.new 0;e.map{|f|h[f]+=1};h}
puts t.all?{|k,v|d[k]>=v}?:YES: :NO
