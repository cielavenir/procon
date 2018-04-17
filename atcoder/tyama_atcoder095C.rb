#!/usr/bin/ruby
n,*a=`dd`.split.map &:to_i
b=a.sort
idx=n/2
n.times{|i|p a[i]<=b[idx-1] ? b[idx] : b[idx-1]}
