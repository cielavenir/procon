#!/usr/bin/ruby
#O(N+logK)
n,k,*a=`dd`.split.map &:to_i
h=Hash.new r=0
a.map{|e|h[e.gcd k]+=1}
h.to_a.repeated_combination(2){|(x,z),(y,w)|x*y%k>0||r+=x==y ?z*~-z/2:z*w}
p r
