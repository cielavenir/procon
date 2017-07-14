#!/usr/bin/ruby
N,X,Y,*A=`dd`.split.map &:to_i;s=0
(1<<N).times{|i|d=r=1;N.times{|j|i[j]>0&&(r=r.lcm A[j];d+=1)};s+=(Y/r-~-X/r)*~-d*(-1)**d}
p s
