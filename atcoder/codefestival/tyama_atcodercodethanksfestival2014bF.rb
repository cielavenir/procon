#!/usr/bin/ruby
X,*A=$<.map &:chomp
$m={}
def d(i)i<X.size ? $m[i]||=A.reduce(0){|s,e|s+(X[i,l=e.size]==e ?d(i+l):0)}%1000000007:1 end
p d(0)