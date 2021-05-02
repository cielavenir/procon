#!/usr/bin/ruby
m={0=>1,1=>2}
d=lambda{|n|m[n]||=d[x=n/2]+d[~-x]+d[n+~x]}
p d[gets.to_i]%(10**9+7)
