#!/usr/bin/ruby
s=0
gets;$<.map{|e|n,k=e.split.map(&:to_i);s+=(n+1)/2*k}
p s%1000000007