#!/usr/bin/ruby
_,*a=`dd`.split
p [-1,1].map{|c|r=s=0;a.map{|e|(s+=e.to_i)*(c=-c)<=0&&(r+=(s-c).abs;s=c)};r}.min
