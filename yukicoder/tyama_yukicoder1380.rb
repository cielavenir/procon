#!/usr/bin/ruby
n,k,*a=`dd`.split.map &:to_i
a.sort_by!{|e|-e}
(p k;exit)if k==n
i=k-1
i-=1 while i>=0&&a[i]==a[i+1]
p i+1
