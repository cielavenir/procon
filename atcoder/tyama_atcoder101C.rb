#!/usr/bin/ruby
n,k,*x=`dd`.split.map &:to_i
z=1<<30
(n-k+1).times{|l|r=l+k-1;z=[z,x[r]-x[l]+x[l].abs,x[r]-x[l]+x[r].abs].min}
p z
