#!/usr/bin/ruby
n=gets.to_i
r=0
a,b,c=$<.map{|e|[0]+e.split.map(&:to_i).sort+[Float::INFINITY]}
(1..n).each{|z|
i=(0..n+1).bsearch{|i|a[i]>=b[z]}-1
k=(0..n+1).bsearch{|k|b[z]<c[k]}
r+=i*(n+1-k)
}
p r
